#! /usr/bin/env python3

# TODO
# Lots of stuff pending
# Change to local ethernet connection
# Minimize needed libraries
# Speed optimizations
# Error catching

import rclpy
from rclpy.node import Node

from tobiiglassesctrl import TobiiGlassesController  # Import glasses lib

# from sensor_msgs.msg import Image
from sensor_msgs.msg import CompressedImage
from std_msgs.msg import String
from cv_bridge import CvBridge

import cv2
import numpy as np

ipv4_address = "192.168.71.50"
# ipv4_address = "169.254.216.158"
# ipv4_address = "164.11.72.104"

publish_rate = 0.01  # Need to change to on refresh...


# TODO: INVESTIGATE Individual eye control
# Add toggle to switch between eyes
# Trigger calibration from other terminal?


# TODO: Make custom tobii glasses message?
# Group everything?

class tobiiPublisher(Node):  # Create node inheriting from Node

    def __init__(self):

        # Base node init
        super().__init__("tobii_pub_node")

        # Intialize camera
        # "tobii_glasses_front_camera"
        self.publisher_front_camera = self.create_publisher(
            CompressedImage, "tobii_glasses/camera_compressed", 1)

        self.publisher_eye_data = self.create_publisher(
            String, "tobii_glasses/eye_info", 1)

        # Init glasses
        self.tobii_glasses = TobiiGlassesController(
            ipv4_address, video_scene=True)

        # TODO:To parameter
        # self.declare_parameter()
        self.calibrate_glasses(self.tobii_glasses)
        # self.load_glasses_calibration()

        # Check if camera opened successfully
        self.bridge = CvBridge()
        self.cap = cv2.VideoCapture(
            "rtsp://%s:8554/live/scene" % ipv4_address)

        if (self.cap.isOpened() == False):
            print("Error opening video stream or file")

        # Publish glasses image
        self.tobii_glasses.start_streaming()
        self.timer = self.create_timer(publish_rate, self.publish_tobii_data)

    def calibrate_glasses(self, tobiiglasses):
        print(tobiiglasses.get_battery_info())
        print(tobiiglasses.get_storage_info())

        if tobiiglasses.is_recording():
            rec_id = tobiiglasses.get_current_recording_id()
            tobiiglasses.stop_recording(rec_id)

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
            exit(1)

    def publish_tobii_data(self):
        # msg.data = ...

        start_time = self.get_clock().now()
        # Capture frame-by-frame
        ret, frame = self.cap.read()

        if not ret:
            return

        # print(self.tobii_glasses.get_data())
        # Eye position data
        data_gp = self.tobii_glasses.get_data()['gp']

        # De-colour and resize image
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        resized_frame = cv2.resize(gray_frame, (0, 0), fx=0.5, fy=0.5)

        # Build message

        imgmsg = self.bridge.cv2_to_compressed_imgmsg(
            resized_frame)
        imgmsg.header.stamp = self.get_clock().now().to_msg()
        imgmsg.header.frame_id = "tobii_frame"

        # print("Sending Image")
        # print(imgmsg)

        self.publisher_front_camera.publish(imgmsg)  # Publish the message

        data_msg = String()  # Message to send is a string object
        # tobii_gp = "Gaze Position: %s " % self.tobii_glasses.get_data()['gp']

        # TODO: What does the data look like?
        # print(self.tobii_glasses.get_data())

        tobii_gp = self.tobii_glasses.get_data()

        if tobii_gp['gp'] and tobii_gp['gp']['ts'] >= 0:
            data_msg.data = str(tobii_gp['gp']['gp'][0]) + \
                "," + str(tobii_gp['gp']['gp'][1])
            print(f"Eyes looking at {data_msg.data}")

            # data_msg.data = "%s " % tobii_gp
            print("Sending eye data")

            self.publisher_eye_data.publish(data_msg)  # Publish the message

        end_time = self.get_clock().now()
        print(
            f"Glasses processing time is {(end_time - start_time).nanoseconds*0.000000001}")


def main():
    rclpy.init()  # Initialize ROS DDS

    glasses_publisher = tobiiPublisher()  # Create instance of function

    print('Tobii Glasses Publisher Node is Running...')

    try:
        rclpy.spin(glasses_publisher)  # prevents closure. Run until interrupt
    except KeyboardInterrupt:
        cv2.destroyAllWindows()
        glasses_publisher.destroy_node()  # duh
        rclpy.shutdown()  # Shutdown DDS !


if __name__ == '__main__':
    main()


""" Complete data sample
{'mems': {'ac': {'ts': 1549970177, 's': 0, 'ac': [-0.118, -10.305, -1.419]}, 'gy': {'ts': 1549975065, 's': 0, 'gy': [-1.19, 1.74, -0.191]}}, 
'right_eye': {  'pc': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'pc': [-29.35, -33.55, -31.9], 'eye': 'right'}, 
                'pd': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'pd': 6.26, 'eye': 'right'}, 
                'gd': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'gd': [-0.1164, 0.1088, 0.9872], 'eye': 'right'}}, ###gd, this one?
'left_eye': {   'pc': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'pc': [27.31, -32.35, -31.24], 'eye': 'left'}, 
                'pd': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'pd': 5.12, 'eye': 'left'}, 
                'gd': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'gd': [-0.1345, -0.0705, 0.9884], 'eye': 'left'}}, 
'gp': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'l': 71271, 'gp': [0.6345, 0.5532]}, 
'gp3': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'gp3': [-72.87, 7.7, 340.59]}, 
'pts': {'ts': 1549408533, 's': 0, 'pts': 118876414, 'pv': 1}, 'vts': {'ts': -1}}

Not a properly formatted json file, so need to decipher data
s: status -> 0 means ok
ts: timestamp?
pc: is specified in 3D coordinates with origo in the scenecam.
pd: pupil diameter of each eye (!)
gd: gaze direction
gp: gaze position
gp3: gaze position 3D
mems: MEMS gyroscope (gy) info or acceleromter (ac)
pts: PTS sync package. “pv” is the “pipeline version” a
"""
