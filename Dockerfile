FROM ros:foxy-ros-base	
LABEL maintainer="Emanuel Nunez S gmail dot com"
ENV HOME /root
WORKDIR $HOME
SHELL ["/bin/bash", "-c"]

# install ros2 packages
RUN apt-get update && apt-get install -y \ 
	ros-foxy-cv-bridge \
	ros-foxy-vision-opencv \
	ros-foxy-compressed-image-transport\
	ros-foxy-image-transport

# install ros2 packages
RUN apt-get update && apt-get install -y \ 
	python3-numpy \
	python3-opencv \
	python3-pip
	
#pip3 install --no-cache-dir pyautogui 
RUN pip3 install --upgrade pip

RUN pip3 install -U \
  	argcomplete \
	pyautogui


# general utilities
RUN apt-get update && apt-get install -y \
    wget \
    curl \
    git \
    gdb \
    vim \
    nano \
    python-dev \
    python3-pip \
    unzip

#
RUN pip3 install -U \
	tobiiglassesctrl

# Glasses emulation (Via Mouse)
RUN pip3 install python-xlib

RUN apt-get update && apt-get install -y \
	scrot \
	python3-tk\
	python3-dev

RUN source /opt/ros/foxy/setup.sh && \
	colcon build

RUN echo ' \n\
echo "Sourcing ROS2 packages..." \n\
source /opt/ros/foxy/setup.sh \n\
source $HOME/install/setup.bash' >> $HOME/.bashrc

#### SET ENVIRONMENT
WORKDIR $HOME

# RUN echo 'alias python="python3"' >> $HOME/.bashrc

# launch ros package
#CMD ["ros2", "launch", "demo_nodes_cpp", "talker_listener.launch.py"]
