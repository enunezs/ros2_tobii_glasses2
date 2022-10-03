#! /usr/bin/env python3

import sys

# * Core dependencies
import rclpy
from rclpy.node import Node

from math import sqrt

# Broadcasters
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped

# * Glasses messages
from tobii_glasses_pkg.msg import TobiiGlasses as TobiiGlassesMsg
from tobii_glasses_pkg.msg import EyeData as EyeDataMsg

# np
from numpy import cross as cross_product
from numpy.linalg import norm
from numpy import dot

import cv2, queue, threading, time

#from tf2_ros.transformations import quaternion_from_euler

# Publishes frames for glasses (centered on the camera), both pupils, and the gaze point
# visual stuff too

class FramePublisher(Node):

    def __init__(self):
        super().__init__('tobii_frame_publisher')

        # Receive pupil data for new frames
        self.subscription = self.create_subscription(
            TobiiGlassesMsg,
            'tobii_glasses',
            self.listener_callback,
            1)

        # Glasses frame is static
        # By default camera is oriented with y pointing upwards, z forwards
        self.static_broadcaster = StaticTransformBroadcaster(self)

        self.glasses_frame = TransformStamped()
        self.glasses_frame.header.frame_id = 'world'
        self.glasses_frame.child_frame_id = 'glasses_frame'
        self.glasses_frame.header.stamp = self.get_clock().now().to_msg()
        self.glasses_frame.transform.translation.x = 0.0
        self.glasses_frame.transform.translation.y = 0.0
        self.glasses_frame.transform.translation.z = 0.0
        self.glasses_frame.transform.rotation.x =  0.7071 #0.0
        self.glasses_frame.transform.rotation.y = 0.0
        self.glasses_frame.transform.rotation.z = 0.0
        self.glasses_frame.transform.rotation.w = 0.7071 # 1.0
        self.static_broadcaster.sendTransform(self.glasses_frame)


        # Initialize the transform broadcaster
        self.tf_broadcaster = TransformBroadcaster(self)


    def listener_callback(self, glasses_msg):

        # Use information on TobiiGlasses.msg to create the frames to broadcast
        #glasses_msg.gaze_position_3d
        #glasses_msg.right_eye
        #glasses_msg.left_eye

        # Right pupil frame
        if glasses_msg.right_eye and glasses_msg.right_eye.status == 0:  
            right_pupil_frame = TransformStamped()
            right_pupil_frame.header.frame_id = 'glasses_frame'
            right_pupil_frame.child_frame_id = 'right_pupil_frame'
            right_pupil_frame.transform.translation.x = float(glasses_msg.right_eye.pupil_center[0]/1000)
            right_pupil_frame.transform.translation.y = float(glasses_msg.right_eye.pupil_center[1]/1000)
            right_pupil_frame.transform.translation.z = float(glasses_msg.right_eye.pupil_center[2]/1000)
            eye_vector = glasses_msg.right_eye.gaze_direction
            ref_vector = [0,1,0]

            dir_quat = self.get_quaternion(eye_vector, ref_vector)
            print(eye_vector)
            print(dir_quat)

            right_pupil_frame.transform.rotation.x = dir_quat[0]
            right_pupil_frame.transform.rotation.y = dir_quat[1]
            right_pupil_frame.transform.rotation.z = dir_quat[2]
            right_pupil_frame.transform.rotation.w = dir_quat[3]
            #right_pupil_frame.transform.rotation = dir_quat
            self.tf_broadcaster.sendTransform(right_pupil_frame)
        
        # Left pupil frame
        if glasses_msg.left_eye and glasses_msg.left_eye.status == 0:  
            left_pupil_frame = TransformStamped()
            left_pupil_frame.header.frame_id = 'glasses_frame'
            left_pupil_frame.child_frame_id = 'left_pupil_frame'
            left_pupil_frame.transform.translation.x = float(glasses_msg.left_eye.pupil_center[0]/1000)
            left_pupil_frame.transform.translation.y = float(glasses_msg.left_eye.pupil_center[1]/1000)
            left_pupil_frame.transform.translation.z = float(glasses_msg.left_eye.pupil_center[2]/1000)
            #Pending, orientation based on gaze direction
            eye_vector = glasses_msg.left_eye.gaze_direction
            ref_vector = [0,1,0]

            dir_quat = self.get_quaternion(eye_vector, ref_vector)

            left_pupil_frame.transform.rotation.x = dir_quat[0]
            left_pupil_frame.transform.rotation.y = dir_quat[1]
            left_pupil_frame.transform.rotation.z = dir_quat[2]
            left_pupil_frame.transform.rotation.w = dir_quat[3]
            self.tf_broadcaster.sendTransform(left_pupil_frame)
        
        # 3D gaze point frame
        if glasses_msg.left_eye and glasses_msg.left_eye.status == 0:  
            gaze_position_3d_frame = TransformStamped()
            gaze_position_3d_frame.header.frame_id = 'glasses_frame'
            gaze_position_3d_frame.child_frame_id = 'gaze_position_3d'
            gaze_position_3d_frame.transform.translation.x = float(glasses_msg.gaze_position_3d[0]/1000)
            gaze_position_3d_frame.transform.translation.y = float(glasses_msg.gaze_position_3d[1]/1000)
            gaze_position_3d_frame.transform.translation.z = float(glasses_msg.gaze_position_3d[2]/1000)
            #Pending, orientation based on gaze direction
            gaze_position_3d_frame.transform.rotation.x = 0.0
            gaze_position_3d_frame.transform.rotation.y = 0.0
            gaze_position_3d_frame.transform.rotation.z = 0.0
            gaze_position_3d_frame.transform.rotation.w = 1.0
            self.tf_broadcaster.sendTransform(gaze_position_3d_frame)
        
    def get_quaternion(self, eye_vector, ref_vector):
        # Returns the quaternion that rotates eye_vector to ref_vector
        # eye_vector and ref_vector are 3D vectors

        # Get the unit vectors
        eye_vector = eye_vector / norm(eye_vector)
        ref_vector = ref_vector / norm(ref_vector)
        """

        # Get the rotation angle
        angle = np.arccos(np.dot(eye_vector, ref_vector))

        # Convert to quaternion
        quat = quaternion_from_euler(0, 0, angle, axes='sxyz')
        quat = Quaternion(quat[0], quat[1], quat[2], quat[3])
        quat = quat * Quaternion(axis=[axis[0], axis[1], axis[2]], angle=0)
        quat = quat.normalized
        return quat
        """
        # Get the rotation axis
        axis = cross_product( ref_vector,eye_vector)
        axis = axis / norm(axis)

        k_cos_theta = dot(ref_vector, eye_vector)
        k = sqrt((norm(ref_vector) ** 2) * (norm(eye_vector) ** 2))
        if (k_cos_theta / k == -1):
            return [0,0,0,1]

        dir_quat = [axis[0], axis[1], axis[2], k_cos_theta + k]
        return (dir_quat/ norm(dir_quat))

# * Run
def main(args=None):
    rclpy.init(args=args)  # Initialize ROS DDS
    glasses_frame_publisher = FramePublisher()  # Create instance of function
    print('Glasses Frame Publisher Node is Running...')

    try:
        rclpy.spin(glasses_frame_publisher)  # prevents closure. Run until interrupt
    except KeyboardInterrupt:
        cv2.destroyAllWindows()
        glasses_frame_publisher.destroy_node()  # duh
        rclpy.shutdown()  # Shutdown DDS !


if __name__ == '__main__':
    main()
