// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice
#include "tobii_glasses_pkg/msg/detail/gaze_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `glasses_header`
#include "std_msgs/msg/detail/header__functions.h"

bool
tobii_glasses_pkg__msg__GazePosition__init(tobii_glasses_pkg__msg__GazePosition * msg)
{
  if (!msg) {
    return false;
  }
  // glasses_header
  if (!std_msgs__msg__Header__init(&msg->glasses_header)) {
    tobii_glasses_pkg__msg__GazePosition__fini(msg);
    return false;
  }
  // status
  // latency
  // gaze_index
  // gaze_position
  return true;
}

void
tobii_glasses_pkg__msg__GazePosition__fini(tobii_glasses_pkg__msg__GazePosition * msg)
{
  if (!msg) {
    return;
  }
  // glasses_header
  std_msgs__msg__Header__fini(&msg->glasses_header);
  // status
  // latency
  // gaze_index
  // gaze_position
}

tobii_glasses_pkg__msg__GazePosition *
tobii_glasses_pkg__msg__GazePosition__create()
{
  tobii_glasses_pkg__msg__GazePosition * msg = (tobii_glasses_pkg__msg__GazePosition *)malloc(sizeof(tobii_glasses_pkg__msg__GazePosition));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tobii_glasses_pkg__msg__GazePosition));
  bool success = tobii_glasses_pkg__msg__GazePosition__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tobii_glasses_pkg__msg__GazePosition__destroy(tobii_glasses_pkg__msg__GazePosition * msg)
{
  if (msg) {
    tobii_glasses_pkg__msg__GazePosition__fini(msg);
  }
  free(msg);
}


bool
tobii_glasses_pkg__msg__GazePosition__Sequence__init(tobii_glasses_pkg__msg__GazePosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tobii_glasses_pkg__msg__GazePosition * data = NULL;
  if (size) {
    data = (tobii_glasses_pkg__msg__GazePosition *)calloc(size, sizeof(tobii_glasses_pkg__msg__GazePosition));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tobii_glasses_pkg__msg__GazePosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tobii_glasses_pkg__msg__GazePosition__fini(&data[i - 1]);
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
tobii_glasses_pkg__msg__GazePosition__Sequence__fini(tobii_glasses_pkg__msg__GazePosition__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tobii_glasses_pkg__msg__GazePosition__fini(&array->data[i]);
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

tobii_glasses_pkg__msg__GazePosition__Sequence *
tobii_glasses_pkg__msg__GazePosition__Sequence__create(size_t size)
{
  tobii_glasses_pkg__msg__GazePosition__Sequence * array = (tobii_glasses_pkg__msg__GazePosition__Sequence *)malloc(sizeof(tobii_glasses_pkg__msg__GazePosition__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tobii_glasses_pkg__msg__GazePosition__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tobii_glasses_pkg__msg__GazePosition__Sequence__destroy(tobii_glasses_pkg__msg__GazePosition__Sequence * array)
{
  if (array) {
    tobii_glasses_pkg__msg__GazePosition__Sequence__fini(array);
  }
  free(array);
}
