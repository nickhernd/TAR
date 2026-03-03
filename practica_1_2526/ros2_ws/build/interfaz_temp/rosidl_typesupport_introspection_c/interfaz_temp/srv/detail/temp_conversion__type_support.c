// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interfaz_temp:srv/TempConversion.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interfaz_temp/srv/detail/temp_conversion__rosidl_typesupport_introspection_c.h"
#include "interfaz_temp/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interfaz_temp/srv/detail/temp_conversion__functions.h"
#include "interfaz_temp/srv/detail/temp_conversion__struct.h"


// Include directives for member types
// Member `conversion_type`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interfaz_temp__srv__TempConversion_Request__init(message_memory);
}

void interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_fini_function(void * message_memory)
{
  interfaz_temp__srv__TempConversion_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_member_array[2] = {
  {
    "input_temp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaz_temp__srv__TempConversion_Request, input_temp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "conversion_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaz_temp__srv__TempConversion_Request, conversion_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_members = {
  "interfaz_temp__srv",  // message namespace
  "TempConversion_Request",  // message name
  2,  // number of fields
  sizeof(interfaz_temp__srv__TempConversion_Request),
  interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_member_array,  // message members
  interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_type_support_handle = {
  0,
  &interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interfaz_temp
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaz_temp, srv, TempConversion_Request)() {
  if (!interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_type_support_handle.typesupport_identifier) {
    interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &interfaz_temp__srv__TempConversion_Request__rosidl_typesupport_introspection_c__TempConversion_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "interfaz_temp/srv/detail/temp_conversion__rosidl_typesupport_introspection_c.h"
// already included above
// #include "interfaz_temp/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "interfaz_temp/srv/detail/temp_conversion__functions.h"
// already included above
// #include "interfaz_temp/srv/detail/temp_conversion__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interfaz_temp__srv__TempConversion_Response__init(message_memory);
}

void interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_fini_function(void * message_memory)
{
  interfaz_temp__srv__TempConversion_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_member_array[1] = {
  {
    "converted_temp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaz_temp__srv__TempConversion_Response, converted_temp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_members = {
  "interfaz_temp__srv",  // message namespace
  "TempConversion_Response",  // message name
  1,  // number of fields
  sizeof(interfaz_temp__srv__TempConversion_Response),
  interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_member_array,  // message members
  interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_type_support_handle = {
  0,
  &interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interfaz_temp
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaz_temp, srv, TempConversion_Response)() {
  if (!interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_type_support_handle.typesupport_identifier) {
    interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &interfaz_temp__srv__TempConversion_Response__rosidl_typesupport_introspection_c__TempConversion_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interfaz_temp/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "interfaz_temp/srv/detail/temp_conversion__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_service_members = {
  "interfaz_temp__srv",  // service namespace
  "TempConversion",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_Request_message_type_support_handle,
  NULL  // response message
  // interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_Response_message_type_support_handle
};

static rosidl_service_type_support_t interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_service_type_support_handle = {
  0,
  &interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaz_temp, srv, TempConversion_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaz_temp, srv, TempConversion_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interfaz_temp
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaz_temp, srv, TempConversion)() {
  if (!interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_service_type_support_handle.typesupport_identifier) {
    interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaz_temp, srv, TempConversion_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaz_temp, srv, TempConversion_Response)()->data;
  }

  return &interfaz_temp__srv__detail__temp_conversion__rosidl_typesupport_introspection_c__TempConversion_service_type_support_handle;
}
