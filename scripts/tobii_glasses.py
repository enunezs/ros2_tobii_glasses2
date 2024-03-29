#! /usr/bin/env python3

# ! TODO: Copyright stuff
# GNU V3.0

# * Core dependencies
import rclpy
from rclpy.node import Node

from queue import Empty
from re import L
from socket import IPV6_CHECKSUM
from time import time
import json

# * Image messaging and conversion
from cv_bridge import CvBridge
import cv2 # TODO: specify particular modules of cv2
import numpy as np

from visualization_msgs.msg import Marker
from visualization_msgs.msg import MarkerArray
from geometry_msgs.msg import Point as PointMsg


# * My classes
from tobii_glasses_pkg.video_capture import VideoCapture   
from tobii_glasses_pkg.tobii_glasses_buffer import TobiiGlassesBuffer

# * Base messages
from sensor_msgs.msg import Image
from std_msgs.msg import String
from builtin_interfaces.msg import Time as TimeMsg

# * Glasses library
from tobiiglassesctrl import TobiiGlassesController  # Import glasses lib

# * Glasses messages
from tobii_glasses_pkg.msg import TobiiGlasses as TobiiGlassesMsg
from tobii_glasses_pkg.msg import EyeData as EyeDataMsg

# * Mouse emulation
import pyautogui

# TODO Remove after study done
import numpy as np
import cv2, queue, threading, time

### * PARAMETERS * ###
# Wifi connection
ipv4_address = "192.168.71.50"
# Refresh mode
high_refresh_rate = True
publish_freq = 50   #50 Hz for high refresh rate, 25 Hz for low
# Sample resolutions, only change if set to low refresh rate
video_resolution = (960, 540)     # (qHD) Default for high framerate, optimal performance
#video_resolution = (720, 480)     # Not recommmeded
#video_resolution = (1280, 720)    # plain HD
#video_resolution = (1600, 900)
#video_resolution = (1920,1080)    # (full HD) Default for low framerate


# Glasses emulation via mouse, very useful for testing
EMULATE_GLASSES = False
# Perform initial calibration
do_calibration = True # Set to false to skip calibration process
# Send image on topic "tobii_glasses/front_camera"
send_image = True

### * DEBUG * ###
syncronize_data = False  
greyscale = False
draw_circle = False
print_performance = False

### ! Future:

# ! Debug mode not sending other eye data

# ! Wired connection, not supported yet
wired_mode = False
#ipv6_address = "fe80::76fe:48ff:fe1f:2c16"      # fe80::692c:1876:10f:33c8
#ipv6_interface = "enx60634c83de17"
#ping6 ff02::1%eth0

# record_glasses = False      # TODO: Future
# undo_distortion = False     # TODO: Future


# TODO: Future: INVESTIGATE Individual eye control
# Add toggle to switch between eyes
# Trigger calibration from other terminal?
# TODO: Parameter expose
# TODO: Use config file

# >>> ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml

class tobiiPublisher(Node): 

    def __init__(self):

        # * Base node init
        super().__init__("tobii_glasses_node")
        self.frame_buffer = None 

        #self.declare_parameter("Name",name)
        #self.get_parameter("Name").get_parameter_value()

        # * Intialize publishers
        self.publisher_glasses = self.create_publisher(
            TobiiGlassesMsg, "tobii_glasses", 1)        

        if send_image:
            self.publisher_front_camera = self.create_publisher(
                Image, "tobii_glasses/front_camera", 1)

        self.declare_parameter('devel_mode', False)

        global EMULATE_GLASSES
        EMULATE_GLASSES = self.get_parameter('devel_mode').get_parameter_value().bool_value
        print("emulate mode is ", EMULATE_GLASSES)

        # * markers
        self.publisher_marker = self.create_publisher(
            MarkerArray, "tobii_glasses/visualization_marker", 2)        

        #marker_pub = rospy.Publisher("/visualization_marker", Marker, queue_size = 2)

        
        self.publisher_gaze_position = self.create_publisher(
            String, "tobii_glasses/gaze_position", 1)
        

        # * Init glasses
        self.bridge = CvBridge()
        global syncronize_data
        global publish_freq

        if EMULATE_GLASSES:
            print("Connecting to webcam 0")
            self.cap = VideoCapture(0)
            syncronize_data = False
            publish_freq = 25 
            #self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 0)
            #publish_freq = 5            #Hz
            #syncronize_data = False     
            pass
        else:
            if wired_mode:
                self.tobii_glasses = TobiiGlassesController("fe80::76fe:48ff:fe1f:2c16%enx60634c83de17")
                #self.tobii_glasses = TobiiGlassesController(ipv6_address+"%"+ipv6_interface, video_scene=True)
            else:
                self.tobii_glasses = TobiiGlassesController(
                    ipv4_address, video_scene=True)

            if high_refresh_rate:
                res = self.tobii_glasses.set_video_freq_50()
                print("Setting video refresh rate to 50Hz")
                publish_freq = 50            #Hz
            else:
                res = self.tobii_glasses.set_video_freq_25()
                print("Setting video refresh rate to 25Hz") 
                publish_freq = 25

            self.tobii_glasses.start_streaming()

            # TODO: To parameter expose
            # * Calibrate glasses
            # self.declare_parameter()
            if do_calibration:
                self.calibrate_glasses(self.tobii_glasses)

            # self.load_glasses_calibration()
            
            self.cap = VideoCapture("rtsp://%s:8554/live/scene" % ipv4_address)
            #self.cap = VideoCapture("rtsp://%s:8554/live/eyes" % ipv4_address)
            
                

        # * Check if connection is succesful
        
        if (self.cap == False):
            print("Error opening video stream")
        else:
            print("Video stream opened")
        

        if syncronize_data:
            self.buffer = TobiiGlassesBuffer()

        #self.last_ts = 0
        # * Create publisher
        self.timer = self.create_timer(1.0/publish_freq, self.publish_tobii_data)

        # * Init debug vars
        self.iterations = 0
        self.total_time = 0
        self.timings = []

        #self.pts_video_to_sensor_offset = 0
        self.stamps = []

    def calibrate_glasses(self, tobiiglasses):

        print(f"Battery level at: {tobiiglasses.get_battery_info()}")
        print(f"Storage at: {tobiiglasses.get_storage_info()}")

        #Stop recordings if they are running
        if tobiiglasses.is_recording():
            rec_id = tobiiglasses.get_current_recording_id()
            tobiiglasses.stop_recording(rec_id)

        #Set project name
        #project_name = input("Please insert the project's name: ")
        project_name = "test"
        project_id = tobiiglasses.create_project(project_name)

        participant_name = input("Please insert the participant's name: ")
        participant_id = tobiiglasses.create_participant(
            project_id, participant_name)

        calibration_id = tobiiglasses.create_calibration(
            project_id, participant_id)
        input(
            "Put the calibration marker in front of the user, then press enter to calibrate")
        tobiiglasses.start_calibration(calibration_id)

        res = tobiiglasses.wait_until_calibration_is_done(calibration_id)


        if res is False:
            print("Calibration failed!")
            return 1
        else:
            print("Calibration successful!")
            return 0

    def publish_tobii_data(self):

        start_time = self.get_clock().now()

        # * Get latest data stream 
        if not EMULATE_GLASSES:
            # Real glasses
            json_data = self.tobii_glasses.get_data()
        else:
            #Emulated: Webcam + Mouse
            string_data = self.emulate_glasses()
            #print(string_data)
            json_data = json.loads(string_data)
        
        eye_data_get_time = self.get_clock().now()

        # * Get latest image frame
        ret, frame = self.cap.read()
        if ret:
            self.frame_buffer = frame
        else:
                    
            if not self.frame_buffer:
                return
            frame = self.frame_buffer

        # * Buffer and sync data
        #video_pts = self.cap.get(cv2.CAP_PROP_POS_MSEC)
        video_pts = self.get_clock().now().nanoseconds/1e3

        if syncronize_data and not EMULATE_GLASSES:
            #ros_time = self.get_clock().now().nanoseconds/1e9
            json_data = self.buffer.get_synced_data(json_data, video_pts , debug=False)

        # * Make and pack eye data message
        tobii_glasses_msg = self.make_glasses_msg(json_data)

        # * Adjust colour and resize image
        frame = self.modify_image(frame, greyscale= greyscale)
        if send_image and draw_circle:
            if not tobii_glasses_msg.gaze_position is None: # and tobii_glasses_msg.status == 0:
                gaze_pos = tobii_glasses_msg.gaze_position
                frame = self.draw_circle(frame,gaze_pos)

        # * Pack image into message
        img_msg = self.bridge.cv2_to_imgmsg(frame)
        img_msg.header.stamp = self.get_clock().now().to_msg() # TODO: Change to glasses, align with pts?
        img_msg.header.frame_id = "tobii_glasses_frame"

        tobii_glasses_msg.camera_image = img_msg

        # * Publish all glasses data
        #print("Publishing glasses data")
        self.publisher_glasses.publish(tobii_glasses_msg)

        # * Publish image
        if send_image:
            #print("Publishing image")
            self.publisher_front_camera.publish(img_msg)  # Publish the message


        # make a string message with the gaze point data and publish it
        gaze_point_msg = String()
        gaze_point_msg.data = str(tobii_glasses_msg.gaze_position[0]) + "," + str(tobii_glasses_msg.gaze_position[1])
        self.publisher_gaze_position.publish(gaze_point_msg)

        #self.publisher_gaze_position.publish()  # Publish the message




        if False : # tobii_glasses_msg.left_eye:

            marker_msg = MarkerArray()
            magnitude = 0.15
            # TODO Publish Arrow marker
            # Position/Orientation method
            marker_msg_left = Marker()
            marker_msg_left.header.frame_id = "tobii_glasses_frame"
            marker_msg_left.header.stamp = self.get_clock().now().to_msg() # Change to empty time message?
            marker_msg_left.ns = "tobii_glasses"
            marker_msg_left.id = 0
            marker_msg_left.type = Marker.ARROW
            marker_msg_left.action = Marker.ADD #Same as modify?

            end_point_msg = PointMsg()
            end_point_msg.x = float(tobii_glasses_msg.left_eye.gaze_direction[0])*magnitude
            end_point_msg.y = float(tobii_glasses_msg.left_eye.gaze_direction[1])*magnitude
            end_point_msg.z = float(tobii_glasses_msg.left_eye.gaze_direction[2])*magnitude
            marker_msg_left.points.append(end_point_msg)            
            start_point_msg = PointMsg()
            start_point_msg.x = float(tobii_glasses_msg.left_eye.pupil_center[0])
            start_point_msg.y = float(tobii_glasses_msg.left_eye.pupil_center[1])
            start_point_msg.z = float(tobii_glasses_msg.left_eye.pupil_center[2])
            marker_msg_left.points.append(start_point_msg)

            marker_msg_left.scale.x = 0.1
            marker_msg_left.scale.y = 0.50
            marker_msg_left.scale.z = 1.0
            marker_msg_left.color.a = 1.0 # Don't forget to set the alpha!
            marker_msg_left.color.r = 1.0
            marker_msg_left.color.g = 0.0
            marker_msg_left.color.b = 0.0
            marker_msg.markers.append(marker_msg_left)

            #self.publisher_marker.publish(marker_msg_left)

            #if tobii_glasses_msg.right_eye:

            # TODO Publish Arrow marker
            # Position/Orientation method
            marker_msg_right = Marker()
            marker_msg_right.header.frame_id = "tobii_glasses_frame"
            marker_msg_right.header.stamp = self.get_clock().now().to_msg() # Change to empty time message?
            marker_msg_right.ns = "tobii_glasses"
            marker_msg_right.id = 0
            marker_msg_right.type = Marker.ARROW
            marker_msg_right.action = Marker.ADD #Same as modify?
            end_point_msg = PointMsg()

            end_point_msg.x = float(tobii_glasses_msg.right_eye.gaze_direction[0])*magnitude
            end_point_msg.y = float(tobii_glasses_msg.right_eye.gaze_direction[1])*magnitude
            end_point_msg.z = float(tobii_glasses_msg.right_eye.gaze_direction[2])*magnitude
            marker_msg_right.points.append(end_point_msg)
            start_point_msg = PointMsg()
            start_point_msg.x = float(tobii_glasses_msg.right_eye.pupil_center[0])
            start_point_msg.y = float(tobii_glasses_msg.right_eye.pupil_center[1])
            start_point_msg.z = float(tobii_glasses_msg.right_eye.pupil_center[2])
            marker_msg_right.points.append(start_point_msg)
  
            marker_msg_right.scale.x = 0.1
            marker_msg_right.scale.y = 0.5
            marker_msg_right.scale.z = 1.0
            marker_msg_right.color.a = 1.0 # Don't forget to set the alpha!
            marker_msg_right.color.r = 0.0
            marker_msg_right.color.g = 0.0
            marker_msg_right.color.b = 1.0

            #
            marker_msg.markers.append(marker_msg_right)
            self.publisher_marker.publish(marker_msg)


        # * Calculate time difference between iterations and frame rate
        end_time = self.get_clock().now() 

        if print_performance:
            self.print_performance_stats(start_time, end_time)

    # receives json data from glasses
    # returns the corresponding filled message with latest data
    # Order of timestamps not guaranteed
    def make_glasses_msg(self, data):

        #video_pts = self.cap.get(cv2.CAP_PROP_POS_MSEC)

        # parse json data into a dictionary
        # Save to messages
        tobii_glasses_msg = TobiiGlassesMsg()
        #gp_ts, gp3_ts, pts_ts, pts_pts = None,None,None,None

        for key in data:

            #TODO: header based on vts?
            # * Currently using latest timestamp not from the video (gp)
            try:
                if key == 'gp' and data[key]['s'] ==0: 
                    # Gaze position
                    stamp = TimeMsg()
                    stamp.sec = int(data[key]['ts']/1000000)        # timestamp in microseconds
                    stamp.nanosec = int((data[key]['ts']%1000000)*1000)
                    
                    tobii_glasses_msg.header.stamp = stamp       
                    tobii_glasses_msg.header.frame_id = "tobii_glasses_frame"  # TODO: Should be different "Relative to the user head or root

                    tobii_glasses_msg.gaze_position = data[key]['gp']  
                    #self.stamps.append(stamp.nanosec)
            except:
                #ts = -1 
                pass

            try:
                if key == 'gp3' and data[key]['s'] ==0: 
                    # Gaze position 3D
                    tobii_glasses_msg.gaze_position_3d = data[key]['gp3']# gaze position
            except:
                pass

            # Right eye
            if key == 'right_eye':
                try:
                    right_eye_data_msg = EyeDataMsg()
                    right_eye_data_msg.name = "right_eye"

                    eye_status = 0
                    if data[key]['pc'] and data[key]['pc']['s'] ==0: 
                        right_eye_data_msg.pupil_center = data[key]['pc']['pc']
                        eye_status = min(eye_status, data[key]['pc']['s'])
                    if data[key]['pd'] and data[key]['pd']['s'] ==0: 
                        right_eye_data_msg.pupil_diameter = data[key]['pd']['pd']
                        eye_status = min(eye_status, data[key]['pd']['s'])
                    if data[key]['gd'] and data[key]['gd']['s'] ==0: 
                        right_eye_data_msg.gaze_direction = data[key]['gd']['gd']
                        eye_status = min(eye_status, data[key]['gd']['s'])

                    right_eye_data_msg.status = eye_status
                    tobii_glasses_msg.right_eye = right_eye_data_msg
                except:
                    pass
            # Right eye
            if key == 'left_eye':
                try:
                    left_eye_data_msg = EyeDataMsg()
                    left_eye_data_msg.name = "left_eye"

                    eye_status = 0
                    if data[key]['pc'] and data[key]['pc']['s'] ==0: 
                        left_eye_data_msg.pupil_center = data[key]['pc']['pc']
                        eye_status = min(eye_status, data[key]['pc']['s'])
                    if data[key]['pd'] and data[key]['pd']['s'] ==0: 
                        left_eye_data_msg.pupil_diameter = data[key]['pd']['pd']
                        eye_status = min(eye_status, data[key]['pd']['s'])
                    if data[key]['gd'] and data[key]['gd']['s'] ==0: 
                        left_eye_data_msg.gaze_direction = data[key]['gd']['gd']
                        eye_status = min(eye_status, data[key]['gd']['s'])

                    tobii_glasses_msg.left_eye = left_eye_data_msg
                except:
                    pass

            # TODO: Nothing if no data!
            # Eyes stuck when glasses removed
            # Consistency between user hasnt worn glasses and user has removed glasses

            if key == 'mems':
                try:
                    if data[key]['ac'] and data[key]['ac']['s'] ==0: 
                        # Accelerometer
                        tobii_glasses_msg.acelerometer = data[key]['ac']['ac']  
                except:
                    #ts = -1 
                    pass

                try:
                    if data[key]['gy'] and data[key]['gy']['s'] ==0: 
                        # Gyroscope
                        tobii_glasses_msg.gyroscope = data[key]['gy']['gy']  
                except:
                    #ts = -1 
                    pass

            try:
                if key == 'vts' and data[key]['s'] ==0: # VTS
                    pass
            except:
                #ts = -1 
                pass

            try:
                if key == 'evts' and data[key]['s'] ==0: # TODO
                    pass
            except:
                #ts = -1 
                pass

            try:
                if key == 'pts' and data[key]['s'] == 0: # Gaze position
                    #self.stamps.append(data[key]['ts'])
                    pts_ts = data[key]['ts']
                    #self.stamps.append(data[key]['pts'])
                    pts_pts = data[key]['pts']
                    pass
                    #print(f"ts: {data[key]['ts']}")
                    #print(f"pts: {data[key]['pts']}")
            except:
                #ts = -1 
                pass
            
            try:
                if key == 'epts' and data[key]['s'] ==0: # TODO
                    pass
            except:
                #ts = -1 
                pass

        return tobii_glasses_msg

    def emulate_glasses(self):
        screen_res_x,screen_res_y = pyautogui.size()
        cursor_x, cursor_y = pyautogui.position()
        gaze_x = cursor_x/screen_res_x
        gaze_y = cursor_y/screen_res_y

        ros_time = self.get_clock().now().nanoseconds/1e9
        ts = ros_time + 500000 
        pts = ros_time*0.09

        # Using dummy vals
        emulation_mems = """ "mems": {  "ac": {"ts":    1549970177, "s": 0, "ac": [-0.118, -10.305, -1.419]}, 
                                        "gy": {"ts":    1549975065, "s": 0, "gy": [-1.19, 1.74, -0.191]}}"""
        emulation_right_eye = """   
                                    "right_eye": {  "pc": {"ts":    1493630785, "s": 0, "gidx": 126842, "pc": [-29.35, -33.55, -31.9], "eye": "right"}, 
                                                    "pd": {"ts":    1493630785, "s": 0, "gidx": 126842, "pd": 6.26, "eye": "right"}, 
                                                    "gd": {"ts":    1493630785, "s": 0, "gidx": 126842, "gd": [-0.1164, 0.1088, 0.9872], "eye": "right"}}"""
        emulation_left_eye = """    "left_eye": {   "pc": {"ts":    1493590817, "s": 0, "gidx": 126838, "pc": [27.31, -32.35, -31.24], "eye": "left"}, 
                                                    "pd": {"ts":    1493590817, "s": 0, "gidx": 126838, "pd": 5.12, "eye": "left"}, 
                                                    "gd": {"ts":    1493590817, "s": 0, "gidx": 126838, "gd": [-0.1345, -0.0705, 0.9884], "eye": "left"}}"""
        emulation_gp =  """"gp": {"ts": %i,           "s": 0, "gidx": 126842, "l": 71271, "gp": [%f, %f]}"""% (ts, gaze_x, gaze_y) 
        emulation_gp3 = """"gp3": {"ts": 1493630785,  "s": 0, "gidx": 126842, "gp3": [-72.87, 7.7, 340.59]}"""
        emulation_pts = """"pts": {"ts": %i,          "s": 0, "pts": %i, "pv": 1} """% (ts,pts) 
        #, "vts": {"ts": -1}

        emulation_data = "{" + emulation_mems + "," + emulation_right_eye + "," + emulation_left_eye + "," + emulation_gp + "," + emulation_gp3 + "," + emulation_pts + "}"

        emulation_data = emulation_data.replace(" ", "")
        return emulation_data

    def print_performance_stats(self, start_time, end_time):
        self.iterations += 1
        self.total_time += (end_time - start_time).nanoseconds/1000000000
        if self.iterations % 10 == 0:
            print(f"Average time per iteration: {self.total_time/self.iterations} s")
            self.iterations = 0
            self.total_time = 0

    # TODO: Pending, open parameters
    def modify_image(self, image, greyscale= False, video_resolution = (960, 540) ):
        # Resize selected image to given dimension
        if greyscale:
            image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        image = cv2.resize(image, video_resolution)

        # Convert to uint8
        image = image.astype(np.uint8)
        # Apply Gaussian blur to remove noise -> Best left for receiver?
        #image = cv2.GaussianBlur(image, (5, 5), 0)

        return image

    # Draw circle on image given gaze position
    def draw_circle(self, image, gaze_position):
        image_size = image.shape[:2][::-1]
        # Draw circle at gaze position
        cv2.circle(image, (int(gaze_position[0]*image_size[0]), int(gaze_position[1]*image_size[1])), 10, (0, 255, 0), -1)
        # Draw circle at center of image
        cv2.circle(image, (int(image_size[0]/2), int(image_size[1]/2)), 10, (0, 0, 255), -1)
        # Draw line from gaze position to center of image
        cv2.line(image, (int(gaze_position[0]*image_size[0]), int(gaze_position[1]*image_size[1])), (int(image_size[0]/2), int(image_size[1]/2)), (0, 0, 255), 2)
        return image

# * Core
def main(args=None):
    rclpy.init(args=args)  # Initialize ROS DDS

    glasses_publisher = tobiiPublisher()  # Create instance of function

    print('Tobii Glasses Publisher Node is Running...')

    try:
        rclpy.spin(glasses_publisher)  # prevents closure. Run until interrupt
    except KeyboardInterrupt:
        cv2.destroyAllWindows()

        # Save timings to file
        fields = ['start_time', 'eye_data_get_time', 'eye_data_pack_time', 'image_data_get_time', 'image_process_time', 'image_data_pack_time', 'end_time', 'iterations'] 
        #fields = ['gp_ts', 'gp3_ts', 'pts_ts', 'pts_pts', 'video_pts', 'ros_time', 'iteration'] 
        rows = glasses_publisher.timings
        combined = rows.insert(0, fields)
        np.savetxt("Res_" + str(video_resolution) + "_Grey_"+ str(greyscale) + "_HRR_" + str(high_refresh_rate) + ".csv", 
                rows,
                delimiter =", ", 
                fmt ='% s')


        glasses_publisher.destroy_node() 
        rclpy.shutdown() 


if __name__ == '__main__':
    main()
