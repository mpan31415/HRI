// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tutorial_interfaces:msg/Falconpos.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__FALCONPOS__FUNCTIONS_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__FALCONPOS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tutorial_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tutorial_interfaces/msg/detail/falconpos__struct.h"

/// Initialize msg/Falconpos message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tutorial_interfaces__msg__Falconpos
 * )) before or use
 * tutorial_interfaces__msg__Falconpos__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
bool
tutorial_interfaces__msg__Falconpos__init(tutorial_interfaces__msg__Falconpos * msg);

/// Finalize msg/Falconpos message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
void
tutorial_interfaces__msg__Falconpos__fini(tutorial_interfaces__msg__Falconpos * msg);

/// Create msg/Falconpos message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tutorial_interfaces__msg__Falconpos__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
tutorial_interfaces__msg__Falconpos *
tutorial_interfaces__msg__Falconpos__create();

/// Destroy msg/Falconpos message.
/**
 * It calls
 * tutorial_interfaces__msg__Falconpos__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
void
tutorial_interfaces__msg__Falconpos__destroy(tutorial_interfaces__msg__Falconpos * msg);

/// Check for msg/Falconpos message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
bool
tutorial_interfaces__msg__Falconpos__are_equal(const tutorial_interfaces__msg__Falconpos * lhs, const tutorial_interfaces__msg__Falconpos * rhs);

/// Copy a msg/Falconpos message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
bool
tutorial_interfaces__msg__Falconpos__copy(
  const tutorial_interfaces__msg__Falconpos * input,
  tutorial_interfaces__msg__Falconpos * output);

/// Initialize array of msg/Falconpos messages.
/**
 * It allocates the memory for the number of elements and calls
 * tutorial_interfaces__msg__Falconpos__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
bool
tutorial_interfaces__msg__Falconpos__Sequence__init(tutorial_interfaces__msg__Falconpos__Sequence * array, size_t size);

/// Finalize array of msg/Falconpos messages.
/**
 * It calls
 * tutorial_interfaces__msg__Falconpos__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
void
tutorial_interfaces__msg__Falconpos__Sequence__fini(tutorial_interfaces__msg__Falconpos__Sequence * array);

/// Create array of msg/Falconpos messages.
/**
 * It allocates the memory for the array and calls
 * tutorial_interfaces__msg__Falconpos__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
tutorial_interfaces__msg__Falconpos__Sequence *
tutorial_interfaces__msg__Falconpos__Sequence__create(size_t size);

/// Destroy array of msg/Falconpos messages.
/**
 * It calls
 * tutorial_interfaces__msg__Falconpos__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
void
tutorial_interfaces__msg__Falconpos__Sequence__destroy(tutorial_interfaces__msg__Falconpos__Sequence * array);

/// Check for msg/Falconpos message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
bool
tutorial_interfaces__msg__Falconpos__Sequence__are_equal(const tutorial_interfaces__msg__Falconpos__Sequence * lhs, const tutorial_interfaces__msg__Falconpos__Sequence * rhs);

/// Copy an array of msg/Falconpos messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
bool
tutorial_interfaces__msg__Falconpos__Sequence__copy(
  const tutorial_interfaces__msg__Falconpos__Sequence * input,
  tutorial_interfaces__msg__Falconpos__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__FALCONPOS__FUNCTIONS_H_
