from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="tobii_glasses_pkg",
            executable="tobii_glasses.py",
            name="tobii_pub_node",
            #prefix=['Terminal -e gdb -ex run --args'],
            arguments=[('__log_level:=debug')],
            output='screen'
        ),
        Node(
            package="tobii_glasses_pkg",
            executable="frame_publisher.py",
            name="tobii_frame_publisher"
        )
    ])
