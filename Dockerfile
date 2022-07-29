FROM ros:foxy-ros-base	
LABEL maintainer="Emanuel Nunez S gmail dot com"

# working directory
ENV HOME /root
WORKDIR $HOME

# install ros2 packages
RUN apt-get update && apt-get install -y \ 
	ros-foxy-cv-bridge \
	ros-foxy-vision-opencv \
	ros-foxy-compressed-image-transport

#RUN pip3 install --upgrade 
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

#libboost-python-dev \
#foxy-ros-cv-bridge 
#python3-opencv \ 
#ros-${ROS_DISTRO}-demo-nodes-cpp \
# ros-${ROS_DISTRO}-demo-nodes-py && \
#rm -rf /var/lib/apt/lists/*


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

RUN pip3 install -U \
	tobiiglassesctrl

#### SET ENVIRONMENT

WORKDIR /home/ema

RUN echo ' \n\
echo "Sourcing ROS2 packages..." \n\
source /opt/ros/foxy/setup.sh \n\
source $HOME/tf_ws/install/local_setup.sh' >> $HOME/.bashrc


RUN echo 'alias python="python3"' >> $HOME/.bashrc

# launch ros package

#CMD ["ros2", "launch", "demo_nodes_cpp", "talker_listener.launch.py"]
