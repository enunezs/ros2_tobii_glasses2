xhost +local:root



docker run -it --env="DISPLAY" --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --privileged --net=host  osrf/ros:foxy-desktop rviz2
export containerId=$(docker ps -l -q)


