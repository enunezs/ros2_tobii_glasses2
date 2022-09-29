xhost +local:root

docker image build -t ros2-glass-base .     

<<<<<<< HEAD
docker run -it \
	--env="DISPLAY" \
	--device=/dev/video0:/dev/video0 \
	-e DISPLAY=$DISPLAY \
	--env="QT_X11_NO_MITSHM=1" \
	--volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
	--privileged \
	--net=host \
	-v $(pwd):/root \
	-v /dev/shm:/dev/shm \
	ros2-glass-base
=======
docker run -it --env="DISPLAY" --device=/dev/video0:/dev/video0 -e DISPLAY=$DISPLAY --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --privileged --net=host -v $(pwd)/:/home/usr/workspaces/ros2_tobii_glasses2 -v /dev/shm:/dev/shm ros2-glass-base
>>>>>>> 042d9849849bd86e9fad5b9d0f8e382dea69bd42

export containerId=$(docker ps -l -q)

