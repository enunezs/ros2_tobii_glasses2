#! /usr/bin/env python3

# ! TODO: Copyright stuff

# * Core dependencies
from socket import IPV6_CHECKSUM
import rclpy
from rclpy.node import Node
import json

# * Image messaging and conversion
from cv_bridge import CvBridge
import cv2
import numpy as np

# * Base messages
from sensor_msgs.msg import Image
from std_msgs.msg import String
from builtin_interfaces.msg import Time as TimeMsg

# * Glasses library
from tobiiglassesctrl import TobiiGlassesController  # Import glasses lib

# * Glasses messages
# TODO: Ahem, simplify or fill
from tobii_glasses_pkg.msg import TobiiGlasses as TobiiGlassesMsg
from tobii_glasses_pkg.msg import GazePosition
from tobii_glasses_pkg.msg import GazePosition3D

### * PARAMETERS * ###
# Wifi connection
ipv4_address = "192.168.71.50"
# Wired conneciton
ipv6_address = "fe80::76fe:48ff:fe1f:2c16"      # fe80::692c:1876:10f:33c8
ipv6_interface = "enx60634c83de17"
#ping6 ff02::1%eth0
wired_mode = False
publish_freq = 50   #Hz
video_resolution = (960, 540)   #Default for high framerate, optimal performance
# video_resolution = (720, 480) #Not recommmeded
# video_resolution = (1280, 720)
# video_resolution = (1600, 900)
# video_resolution = (1920,1080) # Default for low framerate

# TODO: Visualization error for eye marker

# pixels (qHD).

#eye_update_frequency = 50 # Hz #!!!
#scene_camera_frequency = 50 # * Run
use_glasses_timestamp = True # TODO, if false uses ROS-es
#video_resolution = (1280, 720) # plain HD

### * Mouse emulation * ###
import pyautogui
EMULATE_GLASSES = False

### * DEBUG * ###
high_refresh_rate = True    
send_image = True
draw_circle = True
do_calibration = False
print_performance = False
syncronize_data = False     # TODO
record_glasses = False      # TODO
undo_distortion = False     # TODO


# TODO Remove after study done
import numpy as np

# TODO: INVESTIGATE Individual eye control
# Add toggle to switch between eyes
# Trigger calibration from other terminal?

# TODO: Sync data sources
#Modes?

# TODO: Need to carefully observe data, particularly time

# TODO: Parameter expose
# >>> ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml

class tobiiPublisher(Node):  # Create node inheriting from Node

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
                Image, "tobii_glasses/camera", 1)

        """
        self.publisher_eye_data = self.create_publisher(
            String, "tobii_glasses/eye_info", 1)
        """

        # To data queue
        self.gp_buffer = {}
        self.last_pts = 0
        self.last_ts = 0
        


        # * Init glasses
        self.bridge = CvBridge()

        if EMULATE_GLASSES:
            self.cap = cv2.VideoCapture(0)
            publish_freq = 30            #Hz

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
                print(f"Trying to set video refresh rate to 50Hz: {res}")
                publish_freq = 50            #Hz
            else:
                publish_freq = 25            #Hz



            self.tobii_glasses.start_streaming()

            # TODO: To parameter expose
            # * Calibrate glasses
            # self.declare_parameter()
            if do_calibration:
                self.calibrate_glasses(self.tobii_glasses)

            # self.load_glasses_calibration()
            self.cap = cv2.VideoCapture(
                "rtsp://%s:8554/live/scene" % ipv4_address)
            self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 3); # internal buffer will now store only 3 frames

        # * Check if connection is succesful
        if (self.cap.isOpened() == False):
            print("Error opening video stream")

        # * Create publisher
        self.timer = self.create_timer(1.0/publish_freq, self.publish_tobii_data)

        # * Init debug vars
        self.iterations = 0
        self.total_time = 0
        self.timings = []

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
            json_data = json.loads(self.emulate_glasses())
        
        eye_data_get_time = self.get_clock().now()

        # * Buffer and sync data

        #json_data = self.get_synced_data(json_data)

        # * Get latest image frame
        if self.cap.grab():
            ret, frame = self.cap.retrieve()
            if ret:
                self.frame_buffer = frame
                #print(f"Frame: {frame}")
            else:
                frame = self.frame_buffer

        #print(f"frames in buffer: {self.cap.get(cv2.CAP_PROP_FRAME_COUNT)}")
        image_data_get_time = self.get_clock().now()


        # * Make and pack eye data message
        tobii_glasses_msg = self.get_glasses_update(json_data)

        eye_data_pack_time = self.get_clock().now() 

        # * Adjust colour and resize image
        frame = self.modify_image(frame)
        if send_image and draw_circle:
            if tobii_glasses_msg.gaze_position and tobii_glasses_msg.gaze_position.status == 0:
                gaze_pos = tobii_glasses_msg.gaze_position.gaze_position
                frame = self.draw_circle(frame,gaze_pos)

        image_process_time = self.get_clock().now() 

        # * Pack image into message
        img_msg = self.bridge.cv2_to_imgmsg(frame)
        img_msg.header.stamp = self.get_clock().now().to_msg() # TODO: Change to glasses, align with pts?
        img_msg.header.frame_id = "tobii_frame"

        tobii_glasses_msg.camera_image = img_msg

        image_data_pack_time = self.get_clock().now() 

        # * Publish all glasses data
        #print("Publishing glasses data")
        self.publisher_glasses.publish(tobii_glasses_msg)

        # * Publish image?
        if send_image:
            #print("Publishing image")
            self.publisher_front_camera.publish(img_msg)  # Publish the message

        # * Calculate time difference between iterations and frame rate

        end_time = self.get_clock().now() 

        self.iterations += 1
        self.timings.append( [start_time.nanoseconds, eye_data_get_time.nanoseconds, eye_data_pack_time.nanoseconds, image_data_get_time.nanoseconds, image_process_time.nanoseconds, image_data_pack_time.nanoseconds, end_time.nanoseconds, self.iterations] )

        if print_performance:
            self.performance_stats(start_time, self.get_clock().now())


    # 'gp': {   'ts': 1,579,247,690,   's': 0, 'gidx': 137928, 'l': 121786, 'gp': [0.5913, 0.0918]},  
    # 'gp3': {  'ts': 1,579,247,690,   's': 0, 'gidx': 137928, 'gp3': [-55.52, 191.5, 413.59]},  
    # 'pts': {  'ts': 1,579,117,765,   's': 0, 'pts': 48,486,755, 'pv': 5},  


    """
        self.gp_buffer = {}
        self.last_pts = 0
        self.last_ts = 0
    """

    def get_synced_data(self, json_data): 

        # save new data in buffer, use ts as`key
        new_sync_data = None
        new_ts = None

        for key, value in json_data.items():
            # All sensor data
            if key == "gp": # or key == "gp3":
                #TODO iterate on others                
                self.gp_buffer[value['ts']] = value['gp']

                # TODO get latest ts for group
                new_ts = value['ts']
            
            # Get pts 
            elif key == "pts":
                new_sync_data = value
                # maybe add to a buffer as well?
                #self.pts_buffer[value['ts']] = value

        # Update data 
        if new_sync_data:
            self.last_pts = new_sync_data['pts']
            self.last_ts = new_sync_data['ts']

        # get associated ts 

        #



        return json_data

    # receives json data from glasses
    # returns the corresponding filled message with latest data
    # Order of timestamps not guaranteed
    # TODO SYNC image
    def get_glasses_update(self, data):

        # parse json data into a dictionary
        # Save to messages
        tobii_glasses_msg = TobiiGlassesMsg()

        for key in data:
            #print(key,data[key])
            try:
                if key == 'gp' and data[key]['s'] ==0: # Gaze position
                    #make a new message object
                    #print("Packing gaze position")
                    gaze_pos_msg = GazePosition()

                    stamp = TimeMsg()
                    stamp.sec = int(data[key]['ts']/1000000)        # timestamp in microseconds
                    stamp.nanosec = int((data[key]['ts']%1000000)*1000)

                    gaze_pos_msg.glasses_header.stamp = stamp       
                    gaze_pos_msg.glasses_header.frame_id = "tobii_glasses_frame"  # TODO: Should be different "Relative to the user head or root
                    gaze_pos_msg.status = data[key]['s']            # status
                    gaze_pos_msg.latency = data[key]['l']           # latency
                    gaze_pos_msg.gaze_index = data[key]['gidx']     # gaze index
                    gaze_pos_msg.gaze_position = data[key]['gp']    # gaze position

                    tobii_glasses_msg.gaze_position = gaze_pos_msg
            except:
                #nothing if wrong?
                #ts = -1 
                pass

            try:
                if key == 'gp3' and data[key]['s'] ==0: # Gaze position
                    #make a new message object
                    #print("Packing gaze position")
                    gaze_pos_msg = GazePosition3D()

                    stamp = TimeMsg()
                    stamp.sec = int(data[key]['ts']/1000000)        # timestamp in microseconds
                    stamp.nanosec = int((data[key]['ts']%1000000)*1000)

                    gaze_pos_msg.glasses_header.stamp = stamp       
                    gaze_pos_msg.glasses_header.frame_id = "tobii_glasses_frame"  # TODO: Should be different "Relative to the user head or root
                    gaze_pos_msg.status = data[key]['s']            # status
                    gaze_pos_msg.latency = data[key]['l']           # latency
                    gaze_pos_msg.gaze_index = data[key]['gidx']     # gaze index
                    gaze_pos_msg.gaze_position_3d = data[key]['gp3']# gaze position

                    tobii_glasses_msg.gaze_position = gaze_pos_msg
            
            except:
                #ts = -1 
                pass

            try:
                if key == 'pts' and data[key]['s'] ==0: # Gaze position
                    pass
                    #print(f"ts: {data[key]['ts']}")
                    #print(f"pts: {data[key]['pts']}")
            except:
                #ts = -1 
                pass

        return tobii_glasses_msg

    def emulate_glasses(self):
        screen_res_x,screen_res_y = pyautogui.size()
        cursor_x, cursor_y = pyautogui.position()
        gaze_x = cursor_x/screen_res_x
        gaze_y = cursor_y/screen_res_y

        emulation_data = """{'mems': {'ac': {'ts':          1549970177, 's': 0, 'ac': [-0.118, -10.305, -1.419]}, 
                    'gy': {'ts':        1549975065, 's': 0, 'gy': [-1.19, 1.74, -0.191]}}, 
        'right_eye': {  'pc': {'ts':    1493630785, 's': 0, 'gidx': 126842, 'pc': [-29.35, -33.55, -31.9], 'eye': 'right'}, 
                        'pd': {'ts':    1493630785, 's': 0, 'gidx': 126842, 'pd': 6.26, 'eye': 'right'}, 
                        'gd': {'ts':    1493630785, 's': 0, 'gidx': 126842, 'gd': [-0.1164, 0.1088, 0.9872], 'eye': 'right'}}, ###gd, this one?
        'left_eye': {   'pc': {'ts':    1493590817, 's': 0, 'gidx': 126838, 'pc': [27.31, -32.35, -31.24], 'eye': 'left'}, 
                        'pd': {'ts':    1493590817, 's': 0, 'gidx': 126838, 'pd': 5.12, 'eye': 'left'}, 
                        'gd': {'ts':    1493590817, 's': 0, 'gidx': 126838, 'gd': [-0.1345, -0.0705, 0.9884], 'eye': 'left'}}, 
        'gp': {'ts':                    1493630785, 's': 0, 'gidx': 126842, 'l': 71271, 'gp': [%f, %f]}, 
        'gp3': {'ts':                   1493630785, 's': 0, 'gidx': 126842, 'gp3': [-72.87, 7.7, 340.59]}, 
        'pts': {'ts':                   15494   08533, 's': 0, 'pts': 118876414, 'pv': 1}, 'vts': {'ts': -1}} }""" % (gaze_x, gaze_y)
        emulation_data = ' {"gp": {"ts": 1493630785, "s": 0, "gidx": 126842, "l": 71271, "gp": [%f, %f]} }'% (gaze_x, gaze_y)

        #print(emulation_data)

        return emulation_data

    def print_performance_stats(self, start_time, end_time):
        self.iterations += 1
        self.total_time += (end_time - start_time).to_sec()
        if self.iterations % 10 == 0:
            print(f"Average time per iteration: {self.total_time/self.iterations}")
            self.iterations = 0
            self.total_time = 0

    # TODO: Pending, open parameters
    def modify_image(self, image, greyscale= False, video_resolution = (960, 540) ):
        # Resize selected image to given dimension
        image = cv2.resize(image, video_resolution)
        if greyscale:
            image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
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

# * Run
def main(args=None):
    rclpy.init(args=args)  # Initialize ROS DDS

    glasses_publisher = tobiiPublisher()  # Create instance of function

    print('Tobii Glasses Publisher Node is Running...')

    try:
        rclpy.spin(glasses_publisher)  # prevents closure. Run until interrupt
    except KeyboardInterrupt:
        cv2.destroyAllWindows()

        fields = ['start_time', 'eye_data_get_time', 'eye_data_pack_time', 'image_data_get_time', 'image_process_time', 'image_data_pack_time', 'end_time', 'iterations'] 
        rows = glasses_publisher.timings

        combined = rows.insert(0, fields)

        np.savetxt("grey_" + "Res_"+str(video_resolution)+"_HRR_"+ str(high_refresh_rate) + ".csv", 
                rows,
                delimiter =", ", 
                fmt ='% s')


        glasses_publisher.destroy_node()  # duh
        rclpy.shutdown()  # Shutdown DDS !


if __name__ == '__main__':
    main()


""" Complete data sample
{'mems': {'ac': {'ts':          1549970177, 's': 0, 'ac': [-0.118, -10.305, -1.419]}, 
            'gy': {'ts':        1549975065, 's': 0, 'gy': [-1.19, 1.74, -0.191]}}, 
'right_eye': {  'pc': {'ts':    1493630785, 's': 0, 'gidx': 126842, 'pc': [-29.35, -33.55, -31.9], 'eye': 'right'}, 
                'pd': {'ts':    1493630785, 's': 0, 'gidx': 126842, 'pd': 6.26, 'eye': 'right'}, 
                'gd': {'ts':    1493630785, 's': 0, 'gidx': 126842, 'gd': [-0.1164, 0.1088, 0.9872], 'eye': 'right'}}, ###gd, this one?
'left_eye': {   'pc': {'ts':    1493590817, 's': 0, 'gidx': 126838, 'pc': [27.31, -32.35, -31.24], 'eye': 'left'}, 
                'pd': {'ts':    1493590817, 's': 0, 'gidx': 126838, 'pd': 5.12, 'eye': 'left'}, 
                'gd': {'ts':    1493590817, 's': 0, 'gidx': 126838, 'gd': [-0.1345, -0.0705, 0.9884], 'eye': 'left'}}, 
'gp': {'ts':                    1493630785, 's': 0, 'gidx': 126842, 'l': 71271, 'gp': [0.6345, 0.5532]}, 
'gp3': {'ts':                   1493630785, 's': 0, 'gidx': 126842, 'gp3': [-72.87, 7.7, 340.59]}, 
'pts': {'ts':                   15494   08533, 's': 0, 'pts': 118876414, 'pv': 1}, 'vts': {'ts': -1}}

Not a properly formatted json file, so need to decipher data
gidx: gaze index or gaze counter
s: status -> 0 means ok
l: glasses latency
ts: timestamp in microseconds, translate the datastream time ts
ac: acceroation data   
pc: is specified in 3D coordinates with origo in the scenecam.
pd: pupil diameter of each eye (!)
gd: gaze direction
gp: gaze position
gp3: gaze position 3D
mems: MEMS gyroscope (gy) info or acceleromter (ac)
pts: the videostream time pts
epts: eye position timestamp
"""
