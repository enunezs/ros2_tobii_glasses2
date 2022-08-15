#export containerId=$(docker ps -l -q)
docker image build -t ros2-glass-base .     

docker run -it --env="DISPLAY" --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --net=host -v /home/ema/Documents/ROS2_Workspaces/:/home/ema/workspaces --privileged ros2-glass-base




