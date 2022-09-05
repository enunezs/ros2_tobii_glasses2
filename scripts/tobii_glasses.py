#! /usr/bin/env python3

# ! TODO: Copyright stuff

# * Core dependencies
from queue import Empty
from re import L
from socket import IPV6_CHECKSUM
from time import time
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
#publish_freq = 25   #Hz
video_resolution = (960, 540)       # (qHD) Default for high framerate, optimal performance
# video_resolution = (720, 480)     # Not recommmeded
# video_resolution = (1280, 720)    # plain HD
# video_resolution = (1600, 900)
# video_resolution = (1920,1080)    # (full HD) Default for low framerate

# TODO: Visualization error for eye marker

#use_glasses_timestamp = True # TODO, if false uses ROS-es

### * Mouse emulation * ###
import pyautogui
EMULATE_GLASSES = False

### * DEBUG * ###
syncronize_data = True     # TODO
high_refresh_rate = True
do_calibration = False

send_image = True
draw_circle = True
print_performance = False
record_glasses = False      # TODO: Future
undo_distortion = False     # TODO: Future

# TODO Remove after study done
import numpy as np

# TODO: Future: INVESTIGATE Individual eye control
# Add toggle to switch between eyes
# Trigger calibration from other terminal?
# TODO: Need to carefully observe data, particularly time
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

        """
        self.publisher_eye_data = self.create_publisher(
            String, "tobii_glasses/gp", 1)
        """

        # To data queue
        # ! TODO: Move to class 
        self.offset_buffer = {}
        self.sensor_data_buffer = {}
        self.last_pts = 0
        self.pts_video_to_glasses_offset = 0
        #self.last_ts = 0

        # * Init glasses
        self.bridge = CvBridge()

        if EMULATE_GLASSES:
            self.cap = cv2.VideoCapture(0)
            publish_freq = 30            #Hz
            syncronize_data = False     
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
                print("Trying to set video refresh rate to 50Hz")
                publish_freq = 50            #Hz
            else:
                res = self.tobii_glasses.set_video_freq_25()
                print("Trying to set video refresh rate to 25Hz")                #publish_freq = 25            #Hz
                publish_freq = 25

            self.tobii_glasses.start_streaming()

            # TODO: To parameter expose
            # * Calibrate glasses
            # self.declare_parameter()
            if do_calibration:
                self.calibrate_glasses(self.tobii_glasses)

            # self.load_glasses_calibration()
            self.cap = cv2.VideoCapture(
                "rtsp://%s:8554/live/scene" % ipv4_address)
            self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1); # internal buffer will now store only 3 frames

        # * Check if connection is succesful
        if (self.cap.isOpened() == False):
            print("Error opening video stream")

        # * Create publisher
        self.timer = self.create_timer(1.0/publish_freq, self.publish_tobii_data)

        # * Init debug vars
        self.iterations = 0
        self.total_time = 0
        self.timings = []
        self.pts_video_to_sensor_offset = 0
        self.stamps = []
        self.pts_offset = None

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

        # * Get latest image frame
        if self.cap.grab():
            ret, frame = self.cap.retrieve()
            if ret:
                self.frame_buffer = frame
                #print(f"Frame: {frame}")
            else:
                        
                if not self.frame_buffer:
                    return
                frame = self.frame_buffer


        #cv2.imshow("frame1", frame)


        video_pts = self.cap.get(cv2.CAP_PROP_POS_MSEC)

        #print(f"frames in buffer: {self.cap.get(cv2.CAP_PROP_FRAME_COUNT)}")
        image_data_get_time = self.get_clock().now()

        # ! HERE
        # * Buffer and sync data
        if syncronize_data:
            #ros_time = self.get_clock().now().nanoseconds/1e9

            json_data = self.get_synced_data(json_data, video_pts , debug=True)


        # * Make and pack eye data message
        tobii_glasses_msg = self.get_glasses_update(json_data)

        eye_data_pack_time = self.get_clock().now() 

        # * Adjust colour and resize image
        frame = self.modify_image(frame, greyscale= True)
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

        #print(f"Video timing is {time} ?")

        end_time = self.get_clock().now() 

        self.iterations += 1
        self.timings.append( [start_time.nanoseconds, eye_data_get_time.nanoseconds, eye_data_pack_time.nanoseconds, image_data_get_time.nanoseconds, image_process_time.nanoseconds, image_data_pack_time.nanoseconds, end_time.nanoseconds, self.iterations] )

        if print_performance:
            self.print_performance_stats(start_time, end_time)

    # 'gp': {   'ts': 1,579,247,690,   's': 0, 'gidx': 137928, 'l': 121786, 'gp': [0.5913, 0.0918]},  
    # 'gp3': {  'ts': 1,579,247,690,   's': 0, 'gidx': 137928, 'gp3': [-55.52, 191.5, 413.59]},  
    # 'pts': {  'ts': 1,579,117,765,   's': 0, 'pts': 48,486,755, 'pv': 5},  


    """
        self.offset_buffer = {}
        self.sensor_data_buffer = {}
        self.last_pts = 0
    """

# TODO: use latency property
    def get_synced_data(self, json_data, debug = False): 

        # * General process:
        # * [video pts] -> [offset pts, sensor ts] -> [sensor ts, data]

        # Also calculates the video timestamp to message timestamp offset
        def add_data_to_buffers(self, json_data):
            # If the data has a pts and its valid, add ts to the offset buffer indexed by the scaled pts
            if "pts" in json_data and json_data['pts']['s']==0:
                conversion_cnst = 0.09 # 90KHz in microseconds (!), unconfirmed
                offset_pts = int(json_data['pts']['pts']/conversion_cnst)

                if not offset_pts in self.offset_buffer:
                    # Code as is sets the offset to the latest message,
                    # I believe it is correct but it might not be the fully intended behaviour.
                    offset_ts = json_data['pts']['ts']
                    self.offset_buffer[offset_pts] = offset_ts #-json_data["gp"]['l']
                    

            # TODO: Change to sub json for scalability
            if "gp" in json_data and json_data['gp']['s']==0:
                latency = json_data["gp"]['l']
                #Latency means data should be earlier relative to the timestamp
                sensor_ts = json_data['gp']['ts'] - latency 
                self.sensor_data_buffer[sensor_ts] = json_data



        def get_cur_pts(self, video_pts):

            # First time only
            if not self.pts_offset:
                self.pts_offset = min(self.offset_buffer.keys())-video_pts
            # Simply the initial pts + the video pts
            #Basic method
            cur_pts = video_pts + self.pts_offset
            #self.pts_video_to_sensor_offset = offset_pts-video_pts #1000000

            # TODO: Apply delta when buffer changes and flush?
            """
            if not self.first_pts:
                self.first_pts = offset_pts-video_pts
            """

            return cur_pts

        # Gets ts latest from the latest pts
        def get_cur_ts(self, cur_pts):
            # get closes pts in the offset_buffer: largest that is smaller than the timestamp
            prev_pts = min(list(self.offset_buffer))

            for pts in self.offset_buffer: #iterate over key
                if pts <= cur_pts and pts>prev_pts: # TODO: Rewrite in gamma notation(?)
                    prev_pts = pts

            # apply offset and get associated ts
            cur_ts = self.offset_buffer[prev_pts] + (cur_pts - prev_pts)
            return cur_ts

        # TODO: Expand to other data types
        def get_buffered_data(self, cur_ts):
            #print("Looking for buffered data")
            # get closes ts in the sensor_data_buffer: largest that is smaller than the timestamp
            cur_data_ts = list(self.sensor_data_buffer)[0] 
            #print(f"First element {cur_data_ts}")
            #print(f"Limit is current timestamp: {cur_ts}")

            for ts in self.sensor_data_buffer:
                if ts <= cur_ts and ts>cur_data_ts:
                    cur_data_ts = ts
                    #print(f" Updated to: {cur_data_ts}")

            cur_data = self.sensor_data_buffer[ts]
            #print(f"Associated data {cur_data}")

            return cur_data

        def flush_buffer(buffer, timestamp):
            # Get keys smaller than the timestamp
            #get before and after dict

            # TODO: if buffer size 0 or 1 return
            #print(f"Buffer before: {buffer}")
            #print(f"Filter timestamp: {timestamp} ")

            if len(buffer) <=1:
                return buffer

            prev_ts = { k: v for k,v in buffer.items() if k <= timestamp }
            next_ts = { k: v for k,v in buffer.items() if k > timestamp }


            #print(f"Next: {next_ts}")
            updated_buffer = next_ts   
            # Insert the last element of the previous dict into the next dict
            if prev_ts:
                last_ts = max(list(prev_ts.keys()))
                updated_buffer[last_ts] = prev_ts[last_ts]
                #print(f"Final: {last_ts}")

            #print(f"Prev: {prev_ts}")
            #print(f"Buffer after: {updated_buffer}")

            return updated_buffer

        # Add new data to respective data_stream:
        # sync_buffer contains the pts-ts pairs
        # sensor_buffer contains the ts-data for each sensor list
        # How to organize for multiple? Keep multiple buffers or just one with more data?

        add_data_to_buffers(self, json_data)

        # Using the video pts, find inmediate previous pts and respective ts 
        # calculate offset 
        # and find the closest (inmediate previous) ts in the sensor buffer
        current_pts = video_pts + self.pts_video_to_sensor_offset
        current_ts = get_cur_ts(self, current_pts)

        # I guess this can be practically ommitted and only get the last one in the offset buffer?


        # Get new data from json_data, pull closest ts from sensor buffer
        cur_data = get_buffered_data(self, current_ts)

        if debug:
            print(f"Video pts: {video_pts/1000:,}")
            print(f"Current adjusted pts: {current_pts/1000000:,}")
            
            print(f"Offset buffer: {self.offset_buffer}")
            print(f"current ts is {current_ts/1000000:,}")

            print(f"Sensor buffer timestamps: {self.sensor_data_buffer.keys() }")
            print(f"current gp is {cur_data}")

            print(f"Video pts - data offset: {self.pts_video_to_sensor_offset/1000000:,} micro seconds")
            print(f"----")

        # Discard offset buffer data
        self.offset_buffer = flush_buffer( self.offset_buffer, current_pts)

        # Discard offset buffer data
        self.sensor_data_buffer = flush_buffer( self.sensor_data_buffer, current_ts)

        



        return cur_data

    # receives json data from glasses
    # returns the corresponding filled message with latest data
    # Order of timestamps not guaranteed
    # TODO SYNC image
    def get_glasses_update(self, data):

        #video_pts = self.cap.get(cv2.CAP_PROP_POS_MSEC)

        # parse json data into a dictionary
        # Save to messages
        tobii_glasses_msg = TobiiGlassesMsg()
        gp_ts, gp3_ts, pts_ts, pts_pts = None,None,None,None

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

                    gp_ts = data[key]['ts']
                    #self.stamps.append(stamp.nanosec)
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
                    
                    #self.stamps.append(stamp.nanosec)
                    gp3_ts = data[key]['ts']

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

        ros_time = self.get_clock().now().nanoseconds
        #self.iterations += 1
        #self.timings.append( [gp_ts, gp3_ts, pts_ts, pts_pts, video_pts, ros_time, self.iterations] )

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
        ros_time = self.get_clock().now().nanoseconds/1e9
        ts = ros_time + 500000 
        pts = ros_time*0.09

        emulation_data = ' {"mems": {"gp": {"ts": %i, "s": 0, "gidx": 126842, "l": 71271, "gp": [%f, %f]} , "pts": {"ts": %i, "s": 0, "pts": %i, "pv": 1}}}'% (ts, gaze_x, gaze_y,ts,pts)

        #print(emulation_data)

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
        #fields = ['gp_ts', 'gp3_ts', 'pts_ts', 'pts_pts', 'video_pts', 'ros_time', 'iteration'] 
        
        rows = glasses_publisher.timings

        combined = rows.insert(0, fields)

        np.savetxt("Timing_tests" + ".csv", 
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
