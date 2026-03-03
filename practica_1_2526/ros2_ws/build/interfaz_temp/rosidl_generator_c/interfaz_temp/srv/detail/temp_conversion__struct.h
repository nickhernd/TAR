// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaz_temp:srv/TempConversion.idl
// generated code does not contain a copyright notice

#ifndef INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__STRUCT_H_
#define INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'conversion_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TempConversion in the package interfaz_temp.
typedef struct interfaz_temp__srv__TempConversion_Request
{
  double input_temp;
  rosidl_runtime_c__String conversion_type;
} interfaz_temp__srv__TempConversion_Request;

// Struct for a sequence of interfaz_temp__srv__TempConversion_Request.
typedef struct interfaz_temp__srv__TempConversion_Request__Sequence
{
  interfaz_temp__srv__TempConversion_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaz_temp__srv__TempConversion_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TempConversion in the package interfaz_temp.
typedef struct interfaz_temp__srv__TempConversion_Response
{
  double converted_temp;
} interfaz_temp__srv__TempConversion_Response;

// Struct for a sequence of interfaz_temp__srv__TempConversion_Response.
typedef struct interfaz_temp__srv__TempConversion_Response__Sequence
{
  interfaz_temp__srv__TempConversion_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaz_temp__srv__TempConversion_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__STRUCT_H_
