// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__FUNCTIONS_H_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tobii_glasses_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "tobii_glasses_pkg/msg/detail/gaze_position__struct.h"

/// Initialize msg/GazePosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tobii_glasses_pkg__msg__GazePosition
 * )) before or use
 * tobii_glasses_pkg__msg__GazePosition__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
bool
tobii_glasses_pkg__msg__GazePosition__init(tobii_glasses_pkg__msg__GazePosition * msg);

/// Finalize msg/GazePosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
void
tobii_glasses_pkg__msg__GazePosition__fini(tobii_glasses_pkg__msg__GazePosition * msg);

/// Create msg/GazePosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tobii_glasses_pkg__msg__GazePosition__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
tobii_glasses_pkg__msg__GazePosition *
tobii_glasses_pkg__msg__GazePosition__create();

/// Destroy msg/GazePosition message.
/**
 * It calls
 * tobii_glasses_pkg__msg__GazePosition__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
void
tobii_glasses_pkg__msg__GazePosition__destroy(tobii_glasses_pkg__msg__GazePosition * msg);


/// Initialize array of msg/GazePosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * tobii_glasses_pkg__msg__GazePosition__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
bool
tobii_glasses_pkg__msg__GazePosition__Sequence__init(tobii_glasses_pkg__msg__GazePosition__Sequence * array, size_t size);

/// Finalize array of msg/GazePosition messages.
/**
 * It calls
 * tobii_glasses_pkg__msg__GazePosition__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
void
tobii_glasses_pkg__msg__GazePosition__Sequence__fini(tobii_glasses_pkg__msg__GazePosition__Sequence * array);

/// Create array of msg/GazePosition messages.
/**
 * It allocates the memory for the array and calls
 * tobii_glasses_pkg__msg__GazePosition__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
tobii_glasses_pkg__msg__GazePosition__Sequence *
tobii_glasses_pkg__msg__GazePosition__Sequence__create(size_t size);

/// Destroy array of msg/GazePosition messages.
/**
 * It calls
 * tobii_glasses_pkg__msg__GazePosition__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tobii_glasses_pkg
void
tobii_glasses_pkg__msg__GazePosition__Sequence__destroy(tobii_glasses_pkg__msg__GazePosition__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__FUNCTIONS_H_
