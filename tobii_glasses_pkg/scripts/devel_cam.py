#! /usr/bin/env python3


# Lots of stuff pending


import rclpy
from rclpy.node import Node

# from tobiiglassesctrl import TobiiGlassesController  # Import glasses lib

# from sensor_msgs.msg import Image
from sensor_msgs.msg import CompressedImage
from std_msgs.msg import String

import cv2
from cv_bridge import CvBridge
import numpy as np

import pyautogui

publish_rate = 0.01  # Need to change to on refresh...


class tobiiPublisher(Node):  # Create node inheriting from Node

    def __init__(self):

        # Base node init
        super().__init__("tobii_pub_node")

        # "tobii_glasses_front_camera"
        self.publisher_front_camera = self.create_publisher(
            CompressedImage, "tobii_glasses/camera_compressed", 10)

        self.publisher_eye_data = self.create_publisher(
            String, "tobii_glasses/eye_info", 1)

        # Check if camera opened successfully
        self.bridge = CvBridge()
        self.cap = cv2.VideoCapture(0)

        if (self.cap.isOpened() == False):
            print("Error opening video stream or file")

        # Publish glasses image
        # self.tobii_glasses.start_streaming()
        self.timer = self.create_timer(publish_rate, self.publish_tobii_data)

    def publish_tobii_data(self):
        # msg.data = ...
        start_time = self.get_clock().now()

        # Capture frame-by-frame
        ret, frame = self.cap.read()

        if not ret:
            return

        # De-colour and resize image
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        resized_frame = cv2.resize(gray_frame, (0, 0), fx=0.5, fy=0.5)

        # Build message
        imgmsg = self.bridge.cv2_to_compressed_imgmsg(
            resized_frame)
        imgmsg.header.stamp = self.get_clock().now().to_msg()
        imgmsg.header.frame_id = "tobii_frame"

        print("Sending Image")
        # print(imgmsg)

        self.publisher_front_camera.publish(imgmsg)

        # Get cursor position instead of eye data
        # Normalized respect to screen size
        w = pyautogui.position()
        screenWidth, screenHeight = pyautogui.size()
        x_mouse = w.x/screenWidth
        y_mouse = w.y/screenHeight
        print(x_mouse, y_mouse)

        # Send
        data_msg = String()
        tobii_gp = "{'mems': {'ac': {'ts': 1549970177, 's': 0, 'ac': [-0.118, -10.305, -1.419]}, 'gy': {'ts': 1549975065, 's': 0, 'gy': [-1.19, 1.74, -0.191]}}, 'right_eye': {'pc': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'pc': [-29.35, -33.55, -31.9], 'eye': 'right'}, 'pd': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'pd': 6.26, 'eye': 'right'}, 'gd': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'gd': [-0.1164, 0.1088, 0.9872], 'eye': 'right'}},  'left_eye': {'pc': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'pc': [27.31, -32.35, -31.24], 'eye': 'left'}, 'pd': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'pd': 5.12, 'eye': 'left'}, 'gd': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'gd': [-0.1345, -0.0705, 0.9884], 'eye': 'left'}}, 'gp': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'l': 71271, 'gp': [0.6345, 0.5532]}, 'gp3': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'gp3': [-72.87, 7.7, 340.59]}, 'pts': {'ts': 1549408533, 's': 0, 'pts': 118876414, 'pv': 1}, 'vts': {'ts': -1}}"
        data_msg.data = tobii_gp
        data_msg.data = str(x_mouse) + \
            "," + str(y_mouse)
        print(f"Eyes emulator pointing at {data_msg.data}")

        print("Sending eye data")
        self.publisher_eye_data.publish(data_msg)  # Publish the message
        end_time = self.get_clock().now()
        print(
            f"Camera processing time is {(end_time - start_time).nanoseconds*0.000000001}")


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
'right_eye': {'pc': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'pc': [-29.35, -33.55, -31.9], 'eye': 'right'}, 'pd': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'pd': 6.26, 'eye': 'right'}, 'gd': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'gd': [-0.1164, 0.1088, 0.9872], 'eye': 'right'}}, 
'left_eye': {'pc': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'pc': [27.31, -32.35, -31.24], 'eye': 'left'}, 'pd': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'pd': 5.12, 'eye': 'left'}, 'gd': {'ts': 1493590817, 's': 0, 'gidx': 126838, 'gd': [-0.1345, -0.0705, 0.9884], 'eye': 'left'}}, 
'gp': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'l': 71271, 'gp': [0.6345, 0.5532]}, 
'gp3': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'gp3': [-72.87, 7.7, 340.59]}, 
'pts': {'ts': 1549408533, 's': 0, 'pts': 118876414, 'pv': 1}, 'vts': {'ts': -1}}
"""
