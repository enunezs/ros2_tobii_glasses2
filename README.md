# ros2_tobii_glasses2

Tobii Glasses 2 interfacing for ROS2.

Provides and publishes a `tobii_glasses` message with the Glasses information, as well as optional `tobii_glasses/camera` and `tobii_glasses/gaze_position`for just those variables.

The script has many customizable variables to configure resolution, frequency, syncing mode and more

Using the amazing library [Tobiiglassespysuite](https://github.com/ddetommaso/TobiiGlassesPySuite).

# Usage

To use, clone the repository to your workspace, connect to the Toii Glasses through wifi and run:

```
colcon build
source install/setup
ros2 run tobii_glasses_pkg tobii_glasses.py
```

Alternatively, run the associated as a docker container with the provided Dockerfile

```
xhost +local:root

docker image build -t ros2-glass-base .

docker run -it --env="DISPLAY" --device=/dev/video0:/dev/video0 -e DISPLAY=$DISPLAY --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --privileged --net=host -v /home/ema/Documents/ROS2_Workspaces/:/home/username/workspaces -v /dev/shm:/dev/shm ros2-glass-base

export containerId=$(docker ps -l -q)

```

<!--
# Citation

'''
@inproceedings{Nunez:2022,
 author = {Emanuel Nunez Sardinha, Virginia Ruiz Garate},
 title = {TobiiGlassesPySuite: An Open-source Suite for Using the Tobii Pro Glasses 2 in Eye-tracking Studies},
 booktitle = {Proceedings of the 11th ACM Symposium on Eye Tracking Research \& Applications},
 series = {ETRA '19},
 year = {2019},
 isbn = {978-1-4503-6709-7},
 location = {Denver, Colorado},
 pages = {46:1--46:5},
 articleno = {46},
 numpages = {5},
 url = {http://doi.acm.org/10.1145/3314111.3319828},
 doi = {10.1145/3314111.3319828},
 acmid = {3319828},
 publisher = {ACM},
 address = {New York, NY, USA},
 keywords = {Tobii Pro Glasses 2, eye-tracking, human-computer interaction, open-source, wearable computing, wearable eye-tracker},
}
'''
-->
