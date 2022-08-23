#! /usr/bin/env python3


import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from sensor_msgs.msg import CompressedImage
from std_msgs.msg import String  # Standard ROS low precision float
from cv_bridge import CvBridge


import cv2
import numpy as np
import ast

# Aruco...
from cv2 import aruco
from cv2 import drawFrameAxes
from cv2 import projectPoints
from cv2 import Rodrigues

# Gaze Position: {'ts': 896315080, 's': 0, 'gidx': 83804, 'l': 99959, 'gp': [0.4162, 0.4056]}


class VisualWork(Node):  # Create node inheriting from Node

    def __init__(self):

        # Base node init
        super().__init__("visual_pubsub_node")
        self.u = 0
        self.v = 0

        # Image in
        self.subscriber_front_camera = self.create_subscription(
            Image, "/fiducial_images", self.test_image, 1)

        # Test numbers
        self.subscriber_front_camera = self.create_subscription(
            Float32MultiArray, "/temp_visual", self.update_numbers, 1)

        # Empty data initialize
        # {'ts': 536129738, 's': 0,  'gidx': 47765, 'l': 88279, 'gp': [0.2427, 0.1755]}
        self.tobii_data = {}

        self.pub = self.create_publisher(Image, "visual_processed", 10)

        #  For editting
        self.bridge = CvBridge()

    def update_numbers(self, floatArraymsg):
        self.u = int(floatArraymsg.data[0])
        self.v = int(floatArraymsg.data[1])

    def test_image(self, img_msg):
        # Unpack message, get image
        img = self.bridge.imgmsg_to_cv2(img_msg)
        frame = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)

        # Draw circle
        draw_circle = True
        if draw_circle:
            x, y = self.u*2, self.v*2

            frame = cv2.circle(frame, (x, y), 20, (0, 0, 255), 6)
            print(self.u, self.v)
        # Send image

        imgmsg = self.bridge.cv2_to_imgmsg(frame)
        imgmsg.header.stamp = self.get_clock().now().to_msg()
        imgmsg.header.frame_id = "visual_processed"

        print("Sending Image")
        self.pub.publish(imgmsg)  # Publish the message

        pass

    def camera_callback(self, imgmsg):

        # Unpack message, get image
        img = self.bridge.compressed_imgmsg_to_cv2(imgmsg)

        frame = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)

        # Draw circle
        draw_circle = True
        if draw_circle and self.tobii_data:
            height, width = frame.shape[:2]
            data_gp = self.tobii_data['gp']

            if data_gp['ts'] > 0:
                frame = cv2.circle(frame, (int(
                    data_gp['gp'][0]*width), int(data_gp['gp'][1]*height)), 60, (0, 0, 255), 6)

        # self.publisher_front_camera.publish(imgmsg)  # Publish the message

        # Send image

        imgmsg = self.bridge.cv2_to_imgmsg(frame)
        imgmsg.header.stamp = self.get_clock().now().to_msg()
        imgmsg.header.frame_id = "processed_frame"

        print("Sending Image")
        self.pub.publish(imgmsg)  # Publish the message

        pass

    def eye_callback(self, msg):

        # Update buffer for eye position data
        self.tobii_data = ast.literal_eval(msg.data)
        print((self.tobii_data['gp']))

        # data_gp = self.tobii_glasses.get_data()['gp']
        pass


def main():
    rclpy.init()  # Initialize ROS DDS

    publisher = VisualWork()  # Create instance of function

    print('Visual work Pub/Sub Node is Running...')

    try:
        rclpy.spin(publisher)  # prevents closure. Run until interrupt
    except KeyboardInterrupt:
        cv2.destroyAllWindows()
        publisher.destroy_node()  # duh
        rclpy.shutdown()  # Shutdown DDS !


if __name__ == '__main__':
    main()
