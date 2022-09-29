// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__rosidl_typesupport_introspection_c.h"
#include "tobii_glasses_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__functions.h"
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `camera_image`
#include "sensor_msgs/msg/image.h"
// Member `camera_image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `gaze_position`
#include "tobii_glasses_pkg/msg/gaze_position.h"
// Member `gaze_position`
#include "tobii_glasses_pkg/msg/detail/gaze_position__rosidl_typesupport_introspection_c.h"
// Member `gaze_position_3d`
#include "tobii_glasses_pkg/msg/gaze_position3_d.h"
// Member `gaze_position_3d`
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__rosidl_typesupport_introspection_c.h"
// Member `right_eye`
// Member `left_eye`
#include "tobii_glasses_pkg/msg/eye_data.h"
// Member `right_eye`
// Member `left_eye`
#include "tobii_glasses_pkg/msg/detail/eye_data__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tobii_glasses_pkg__msg__TobiiGlasses__init(message_memory);
}

void TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_fini_function(void * message_memory)
{
  tobii_glasses_pkg__msg__TobiiGlasses__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__TobiiGlasses, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "camera_image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__TobiiGlasses, camera_image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gaze_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__TobiiGlasses, gaze_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gaze_position_3d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__TobiiGlasses, gaze_position_3d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_eye",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__TobiiGlasses, right_eye),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_eye",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__TobiiGlasses, left_eye),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_members = {
  "tobii_glasses_pkg__msg",  // message namespace
  "TobiiGlasses",  // message name
  6,  // number of fields
  sizeof(tobii_glasses_pkg__msg__TobiiGlasses),
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array,  // message members
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_init_function,  // function to initialize message memory (memory has to be allocated)
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_type_support_handle = {
  0,
  &TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tobii_glasses_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tobii_glasses_pkg, msg, TobiiGlasses)() {
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tobii_glasses_pkg, msg, GazePosition)();
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tobii_glasses_pkg, msg, GazePosition3D)();
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tobii_glasses_pkg, msg, EyeData)();
  TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tobii_glasses_pkg, msg, EyeData)();
  if (!TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_type_support_handle.typesupport_identifier) {
    TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TobiiGlasses__rosidl_typesupport_introspection_c__TobiiGlasses_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
