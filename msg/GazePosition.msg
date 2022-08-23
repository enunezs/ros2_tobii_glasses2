# Values roughly correspond to:
# ts (timestamp)
# s (status)
# gidx (gaze index)
# l (latency)
# gp (gaze position)


std_msgs/Header glasses_header        # Header timestamp should be acquisition time of image

uint8 status        #
uint32 latency
uint32 gaze_index
float32[2] gaze_position 

                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined
