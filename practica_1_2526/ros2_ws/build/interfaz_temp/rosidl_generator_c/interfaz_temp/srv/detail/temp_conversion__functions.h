// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interfaz_temp:srv/TempConversion.idl
// generated code does not contain a copyright notice

#ifndef INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__FUNCTIONS_H_
#define INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interfaz_temp/msg/rosidl_generator_c__visibility_control.h"

#include "interfaz_temp/srv/detail/temp_conversion__struct.h"

/// Initialize srv/TempConversion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz_temp__srv__TempConversion_Request
 * )) before or use
 * interfaz_temp__srv__TempConversion_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Request__init(interfaz_temp__srv__TempConversion_Request * msg);

/// Finalize srv/TempConversion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Request__fini(interfaz_temp__srv__TempConversion_Request * msg);

/// Create srv/TempConversion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz_temp__srv__TempConversion_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
interfaz_temp__srv__TempConversion_Request *
interfaz_temp__srv__TempConversion_Request__create();

/// Destroy srv/TempConversion message.
/**
 * It calls
 * interfaz_temp__srv__TempConversion_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Request__destroy(interfaz_temp__srv__TempConversion_Request * msg);

/// Check for srv/TempConversion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Request__are_equal(const interfaz_temp__srv__TempConversion_Request * lhs, const interfaz_temp__srv__TempConversion_Request * rhs);

/// Copy a srv/TempConversion message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Request__copy(
  const interfaz_temp__srv__TempConversion_Request * input,
  interfaz_temp__srv__TempConversion_Request * output);

/// Initialize array of srv/TempConversion messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz_temp__srv__TempConversion_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Request__Sequence__init(interfaz_temp__srv__TempConversion_Request__Sequence * array, size_t size);

/// Finalize array of srv/TempConversion messages.
/**
 * It calls
 * interfaz_temp__srv__TempConversion_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Request__Sequence__fini(interfaz_temp__srv__TempConversion_Request__Sequence * array);

/// Create array of srv/TempConversion messages.
/**
 * It allocates the memory for the array and calls
 * interfaz_temp__srv__TempConversion_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
interfaz_temp__srv__TempConversion_Request__Sequence *
interfaz_temp__srv__TempConversion_Request__Sequence__create(size_t size);

/// Destroy array of srv/TempConversion messages.
/**
 * It calls
 * interfaz_temp__srv__TempConversion_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Request__Sequence__destroy(interfaz_temp__srv__TempConversion_Request__Sequence * array);

/// Check for srv/TempConversion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Request__Sequence__are_equal(const interfaz_temp__srv__TempConversion_Request__Sequence * lhs, const interfaz_temp__srv__TempConversion_Request__Sequence * rhs);

/// Copy an array of srv/TempConversion messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Request__Sequence__copy(
  const interfaz_temp__srv__TempConversion_Request__Sequence * input,
  interfaz_temp__srv__TempConversion_Request__Sequence * output);

/// Initialize srv/TempConversion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz_temp__srv__TempConversion_Response
 * )) before or use
 * interfaz_temp__srv__TempConversion_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Response__init(interfaz_temp__srv__TempConversion_Response * msg);

/// Finalize srv/TempConversion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Response__fini(interfaz_temp__srv__TempConversion_Response * msg);

/// Create srv/TempConversion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz_temp__srv__TempConversion_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
interfaz_temp__srv__TempConversion_Response *
interfaz_temp__srv__TempConversion_Response__create();

/// Destroy srv/TempConversion message.
/**
 * It calls
 * interfaz_temp__srv__TempConversion_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Response__destroy(interfaz_temp__srv__TempConversion_Response * msg);

/// Check for srv/TempConversion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Response__are_equal(const interfaz_temp__srv__TempConversion_Response * lhs, const interfaz_temp__srv__TempConversion_Response * rhs);

/// Copy a srv/TempConversion message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Response__copy(
  const interfaz_temp__srv__TempConversion_Response * input,
  interfaz_temp__srv__TempConversion_Response * output);

/// Initialize array of srv/TempConversion messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz_temp__srv__TempConversion_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Response__Sequence__init(interfaz_temp__srv__TempConversion_Response__Sequence * array, size_t size);

/// Finalize array of srv/TempConversion messages.
/**
 * It calls
 * interfaz_temp__srv__TempConversion_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Response__Sequence__fini(interfaz_temp__srv__TempConversion_Response__Sequence * array);

/// Create array of srv/TempConversion messages.
/**
 * It allocates the memory for the array and calls
 * interfaz_temp__srv__TempConversion_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
interfaz_temp__srv__TempConversion_Response__Sequence *
interfaz_temp__srv__TempConversion_Response__Sequence__create(size_t size);

/// Destroy array of srv/TempConversion messages.
/**
 * It calls
 * interfaz_temp__srv__TempConversion_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
void
interfaz_temp__srv__TempConversion_Response__Sequence__destroy(interfaz_temp__srv__TempConversion_Response__Sequence * array);

/// Check for srv/TempConversion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Response__Sequence__are_equal(const interfaz_temp__srv__TempConversion_Response__Sequence * lhs, const interfaz_temp__srv__TempConversion_Response__Sequence * rhs);

/// Copy an array of srv/TempConversion messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz_temp
bool
interfaz_temp__srv__TempConversion_Response__Sequence__copy(
  const interfaz_temp__srv__TempConversion_Response__Sequence * input,
  interfaz_temp__srv__TempConversion_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__FUNCTIONS_H_
