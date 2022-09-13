from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="tobii_glasses_pkg",
            executable="devel_cam.py",
            name="tobii_pub_node",
            #prefix=['Terminal -e gdb -ex run --args'],
            arguments=[('__log_level:=debug')],
            output='screen'
        ),
        Node(
            package="fiducials",
            executable="aruco_detect.py",
            name="aruco_detect"
        ),
        Node(
            package="diegetic_button_pkg",
            executable="diegetic_button.py",
            name="diegetic_button_pubsub_node"
        ),
        ExecuteProcess(
            cmd=['rviz2']
        ),
        Node(
            package="joy",
            executable="joy_node",
            name="gamepad"  # ros2 run joy joy_node
        )
    ])


"""
        Node(
            package="diegetic_button_pkg",
            executable="input_check.py",
            name="process_inputs_node"
        ),
"""
