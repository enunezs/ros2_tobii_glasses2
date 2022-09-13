// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tobii_glasses_pkg/msg/detail/gaze_position__rosidl_typesupport_introspection_c.h"
#include "tobii_glasses_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tobii_glasses_pkg/msg/detail/gaze_position__functions.h"
#include "tobii_glasses_pkg/msg/detail/gaze_position__struct.h"


// Include directives for member types
// Member `glasses_header`
#include "std_msgs/msg/header.h"
// Member `glasses_header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GazePosition__rosidl_typesupport_introspection_c__GazePosition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tobii_glasses_pkg__msg__GazePosition__init(message_memory);
}

void GazePosition__rosidl_typesupport_introspection_c__GazePosition_fini_function(void * message_memory)
{
  tobii_glasses_pkg__msg__GazePosition__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_member_array[5] = {
  {
    "glasses_header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__GazePosition, glasses_header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__GazePosition, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__GazePosition, latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gaze_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__GazePosition, gaze_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gaze_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__GazePosition, gaze_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_members = {
  "tobii_glasses_pkg__msg",  // message namespace
  "GazePosition",  // message name
  5,  // number of fields
  sizeof(tobii_glasses_pkg__msg__GazePosition),
  GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_member_array,  // message members
  GazePosition__rosidl_typesupport_introspection_c__GazePosition_init_function,  // function to initialize message memory (memory has to be allocated)
  GazePosition__rosidl_typesupport_introspection_c__GazePosition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_type_support_handle = {
  0,
  &GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tobii_glasses_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tobii_glasses_pkg, msg, GazePosition)() {
  GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_type_support_handle.typesupport_identifier) {
    GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GazePosition__rosidl_typesupport_introspection_c__GazePosition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
