# Values roughly correspond to:
# ts (timestamp)
# s (status)
# gidx (gaze index)
# l (latency)
# gp (gaze position)


#'gp': {'ts':                    1493630785, 's': 0, 'gidx': 126842, 'l': 71271, 'gp': [0.6345, 0.5532]}, 


std_msgs/Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

sensor_msgs/Image camera_image    # Front camera image
GazePosition gaze_position
#float32[2] gaze_position 
GazePosition3D gaze_position_3d
#float32[3] gaze_position_3d
EyeData right_eye
EyeData left_eye
#Acelerometer
float32[3] Acelerometer 
#Gyroscope
float32[3] Gyroscope
#PTS

# 'gp': {'ts': 1493630785, 's': 0, 'gidx': 126842, 'l': 71271, 'gp': [0.6345, 0.5532]}, 

