# ros2_tobii_glasses2

```
ros2 run tobii_glasses_pkg 
devel_cam.py        tobii_glasses.py 
```

## Running


"""
sudo docker run -it \ 
    --env="DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --net=host --privileged\
    osrf/ros:foxy-desktop
export containerId=$(docker ps -l -q)

"""




