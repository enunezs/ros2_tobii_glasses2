xhost +local:root

docker image build -t ros2-glass-base .     

<<<<<<< HEAD
docker run -it \
	--env="DISPLAY" \
=======
docker run -it --env="DISPLAY" \
>>>>>>> acb9fe5807dc3423a38e0c209adf7e186eab4078
	--device=/dev/video0:/dev/video0 \
	-e DISPLAY=$DISPLAY \
	--env="QT_X11_NO_MITSHM=1" \
	--volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
	--privileged \
	-e "ROS_DOMAIN_ID=7" \
	--net=host \
	-v $(pwd):/root/ws/ros2_tobii_glasses2 \
	-v /dev/shm:/dev/shm \
	ros2-glass-base

export containerId=$(docker ps -l -q)

