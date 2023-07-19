// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/Falconpos.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/falconpos__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/falconpos__functions.h"
#include "tutorial_interfaces/msg/detail/falconpos__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__Falconpos__init(message_memory);
}

void tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__Falconpos__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__Falconpos, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__Falconpos, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__Falconpos, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "Falconpos",  // message name
  3,  // number of fields
  sizeof(tutorial_interfaces__msg__Falconpos),
  tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_member_array,  // message members
  tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_init_function,  // function to initialize message memory (memory has to be allocated)
  tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_type_support_handle = {
  0,
  &tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, Falconpos)() {
  if (!tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_type_support_handle.typesupport_identifier) {
    tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tutorial_interfaces__msg__Falconpos__rosidl_typesupport_introspection_c__Falconpos_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
