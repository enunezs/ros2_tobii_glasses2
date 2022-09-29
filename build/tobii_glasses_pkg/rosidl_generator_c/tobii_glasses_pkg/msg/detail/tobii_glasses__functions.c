// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `camera_image`
#include "sensor_msgs/msg/detail/image__functions.h"
// Member `gaze_position`
#include "tobii_glasses_pkg/msg/detail/gaze_position__functions.h"
// Member `gaze_position_3d`
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__functions.h"
// Member `right_eye`
// Member `left_eye`
#include "tobii_glasses_pkg/msg/detail/eye_data__functions.h"

bool
tobii_glasses_pkg__msg__TobiiGlasses__init(tobii_glasses_pkg__msg__TobiiGlasses * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tobii_glasses_pkg__msg__TobiiGlasses__fini(msg);
    return false;
  }
  // camera_image
  if (!sensor_msgs__msg__Image__init(&msg->camera_image)) {
    tobii_glasses_pkg__msg__TobiiGlasses__fini(msg);
    return false;
  }
  // gaze_position
  if (!tobii_glasses_pkg__msg__GazePosition__init(&msg->gaze_position)) {
    tobii_glasses_pkg__msg__TobiiGlasses__fini(msg);
    return false;
  }
  // gaze_position_3d
  if (!tobii_glasses_pkg__msg__GazePosition3D__init(&msg->gaze_position_3d)) {
    tobii_glasses_pkg__msg__TobiiGlasses__fini(msg);
    return false;
  }
  // right_eye
  if (!tobii_glasses_pkg__msg__EyeData__init(&msg->right_eye)) {
    tobii_glasses_pkg__msg__TobiiGlasses__fini(msg);
    return false;
  }
  // left_eye
  if (!tobii_glasses_pkg__msg__EyeData__init(&msg->left_eye)) {
    tobii_glasses_pkg__msg__TobiiGlasses__fini(msg);
    return false;
  }
  return true;
}

void
tobii_glasses_pkg__msg__TobiiGlasses__fini(tobii_glasses_pkg__msg__TobiiGlasses * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // camera_image
  sensor_msgs__msg__Image__fini(&msg->camera_image);
  // gaze_position
  tobii_glasses_pkg__msg__GazePosition__fini(&msg->gaze_position);
  // gaze_position_3d
  tobii_glasses_pkg__msg__GazePosition3D__fini(&msg->gaze_position_3d);
  // right_eye
  tobii_glasses_pkg__msg__EyeData__fini(&msg->right_eye);
  // left_eye
  tobii_glasses_pkg__msg__EyeData__fini(&msg->left_eye);
}

tobii_glasses_pkg__msg__TobiiGlasses *
tobii_glasses_pkg__msg__TobiiGlasses__create()
{
  tobii_glasses_pkg__msg__TobiiGlasses * msg = (tobii_glasses_pkg__msg__TobiiGlasses *)malloc(sizeof(tobii_glasses_pkg__msg__TobiiGlasses));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tobii_glasses_pkg__msg__TobiiGlasses));
  bool success = tobii_glasses_pkg__msg__TobiiGlasses__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tobii_glasses_pkg__msg__TobiiGlasses__destroy(tobii_glasses_pkg__msg__TobiiGlasses * msg)
{
  if (msg) {
    tobii_glasses_pkg__msg__TobiiGlasses__fini(msg);
  }
  free(msg);
}


bool
tobii_glasses_pkg__msg__TobiiGlasses__Sequence__init(tobii_glasses_pkg__msg__TobiiGlasses__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tobii_glasses_pkg__msg__TobiiGlasses * data = NULL;
  if (size) {
    data = (tobii_glasses_pkg__msg__TobiiGlasses *)calloc(size, sizeof(tobii_glasses_pkg__msg__TobiiGlasses));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tobii_glasses_pkg__msg__TobiiGlasses__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tobii_glasses_pkg__msg__TobiiGlasses__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tobii_glasses_pkg__msg__TobiiGlasses__Sequence__fini(tobii_glasses_pkg__msg__TobiiGlasses__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tobii_glasses_pkg__msg__TobiiGlasses__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tobii_glasses_pkg__msg__TobiiGlasses__Sequence *
tobii_glasses_pkg__msg__TobiiGlasses__Sequence__create(size_t size)
{
  tobii_glasses_pkg__msg__TobiiGlasses__Sequence * array = (tobii_glasses_pkg__msg__TobiiGlasses__Sequence *)malloc(sizeof(tobii_glasses_pkg__msg__TobiiGlasses__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tobii_glasses_pkg__msg__TobiiGlasses__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tobii_glasses_pkg__msg__TobiiGlasses__Sequence__destroy(tobii_glasses_pkg__msg__TobiiGlasses__Sequence * array)
{
  if (array) {
    tobii_glasses_pkg__msg__TobiiGlasses__Sequence__fini(array);
  }
  free(array);
}
