// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interfaz:action/BatteryAction.idl
// generated code does not contain a copyright notice

#ifndef INTERFAZ__ACTION__DETAIL__BATTERY_ACTION__FUNCTIONS_H_
#define INTERFAZ__ACTION__DETAIL__BATTERY_ACTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interfaz/msg/rosidl_generator_c__visibility_control.h"

#include "interfaz/action/detail/battery_action__struct.h"

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_Goal
 * )) before or use
 * interfaz__action__BatteryAction_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Goal__init(interfaz__action__BatteryAction_Goal * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Goal__fini(interfaz__action__BatteryAction_Goal * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_Goal *
interfaz__action__BatteryAction_Goal__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Goal__destroy(interfaz__action__BatteryAction_Goal * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Goal__are_equal(const interfaz__action__BatteryAction_Goal * lhs, const interfaz__action__BatteryAction_Goal * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Goal__copy(
  const interfaz__action__BatteryAction_Goal * input,
  interfaz__action__BatteryAction_Goal * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Goal__Sequence__init(interfaz__action__BatteryAction_Goal__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Goal__Sequence__fini(interfaz__action__BatteryAction_Goal__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_Goal__Sequence *
interfaz__action__BatteryAction_Goal__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Goal__Sequence__destroy(interfaz__action__BatteryAction_Goal__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Goal__Sequence__are_equal(const interfaz__action__BatteryAction_Goal__Sequence * lhs, const interfaz__action__BatteryAction_Goal__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Goal__Sequence__copy(
  const interfaz__action__BatteryAction_Goal__Sequence * input,
  interfaz__action__BatteryAction_Goal__Sequence * output);

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_Result
 * )) before or use
 * interfaz__action__BatteryAction_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Result__init(interfaz__action__BatteryAction_Result * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Result__fini(interfaz__action__BatteryAction_Result * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_Result *
interfaz__action__BatteryAction_Result__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Result__destroy(interfaz__action__BatteryAction_Result * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Result__are_equal(const interfaz__action__BatteryAction_Result * lhs, const interfaz__action__BatteryAction_Result * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Result__copy(
  const interfaz__action__BatteryAction_Result * input,
  interfaz__action__BatteryAction_Result * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Result__Sequence__init(interfaz__action__BatteryAction_Result__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Result__Sequence__fini(interfaz__action__BatteryAction_Result__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_Result__Sequence *
interfaz__action__BatteryAction_Result__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Result__Sequence__destroy(interfaz__action__BatteryAction_Result__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Result__Sequence__are_equal(const interfaz__action__BatteryAction_Result__Sequence * lhs, const interfaz__action__BatteryAction_Result__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Result__Sequence__copy(
  const interfaz__action__BatteryAction_Result__Sequence * input,
  interfaz__action__BatteryAction_Result__Sequence * output);

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_Feedback
 * )) before or use
 * interfaz__action__BatteryAction_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Feedback__init(interfaz__action__BatteryAction_Feedback * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Feedback__fini(interfaz__action__BatteryAction_Feedback * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_Feedback *
interfaz__action__BatteryAction_Feedback__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Feedback__destroy(interfaz__action__BatteryAction_Feedback * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Feedback__are_equal(const interfaz__action__BatteryAction_Feedback * lhs, const interfaz__action__BatteryAction_Feedback * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Feedback__copy(
  const interfaz__action__BatteryAction_Feedback * input,
  interfaz__action__BatteryAction_Feedback * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Feedback__Sequence__init(interfaz__action__BatteryAction_Feedback__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Feedback__Sequence__fini(interfaz__action__BatteryAction_Feedback__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_Feedback__Sequence *
interfaz__action__BatteryAction_Feedback__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_Feedback__Sequence__destroy(interfaz__action__BatteryAction_Feedback__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Feedback__Sequence__are_equal(const interfaz__action__BatteryAction_Feedback__Sequence * lhs, const interfaz__action__BatteryAction_Feedback__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_Feedback__Sequence__copy(
  const interfaz__action__BatteryAction_Feedback__Sequence * input,
  interfaz__action__BatteryAction_Feedback__Sequence * output);

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_SendGoal_Request
 * )) before or use
 * interfaz__action__BatteryAction_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Request__init(interfaz__action__BatteryAction_SendGoal_Request * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Request__fini(interfaz__action__BatteryAction_SendGoal_Request * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_SendGoal_Request *
interfaz__action__BatteryAction_SendGoal_Request__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Request__destroy(interfaz__action__BatteryAction_SendGoal_Request * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Request__are_equal(const interfaz__action__BatteryAction_SendGoal_Request * lhs, const interfaz__action__BatteryAction_SendGoal_Request * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Request__copy(
  const interfaz__action__BatteryAction_SendGoal_Request * input,
  interfaz__action__BatteryAction_SendGoal_Request * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Request__Sequence__init(interfaz__action__BatteryAction_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Request__Sequence__fini(interfaz__action__BatteryAction_SendGoal_Request__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_SendGoal_Request__Sequence *
interfaz__action__BatteryAction_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Request__Sequence__destroy(interfaz__action__BatteryAction_SendGoal_Request__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Request__Sequence__are_equal(const interfaz__action__BatteryAction_SendGoal_Request__Sequence * lhs, const interfaz__action__BatteryAction_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Request__Sequence__copy(
  const interfaz__action__BatteryAction_SendGoal_Request__Sequence * input,
  interfaz__action__BatteryAction_SendGoal_Request__Sequence * output);

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_SendGoal_Response
 * )) before or use
 * interfaz__action__BatteryAction_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Response__init(interfaz__action__BatteryAction_SendGoal_Response * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Response__fini(interfaz__action__BatteryAction_SendGoal_Response * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_SendGoal_Response *
interfaz__action__BatteryAction_SendGoal_Response__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Response__destroy(interfaz__action__BatteryAction_SendGoal_Response * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Response__are_equal(const interfaz__action__BatteryAction_SendGoal_Response * lhs, const interfaz__action__BatteryAction_SendGoal_Response * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Response__copy(
  const interfaz__action__BatteryAction_SendGoal_Response * input,
  interfaz__action__BatteryAction_SendGoal_Response * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Response__Sequence__init(interfaz__action__BatteryAction_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Response__Sequence__fini(interfaz__action__BatteryAction_SendGoal_Response__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_SendGoal_Response__Sequence *
interfaz__action__BatteryAction_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_SendGoal_Response__Sequence__destroy(interfaz__action__BatteryAction_SendGoal_Response__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Response__Sequence__are_equal(const interfaz__action__BatteryAction_SendGoal_Response__Sequence * lhs, const interfaz__action__BatteryAction_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_SendGoal_Response__Sequence__copy(
  const interfaz__action__BatteryAction_SendGoal_Response__Sequence * input,
  interfaz__action__BatteryAction_SendGoal_Response__Sequence * output);

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_GetResult_Request
 * )) before or use
 * interfaz__action__BatteryAction_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Request__init(interfaz__action__BatteryAction_GetResult_Request * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Request__fini(interfaz__action__BatteryAction_GetResult_Request * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_GetResult_Request *
interfaz__action__BatteryAction_GetResult_Request__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Request__destroy(interfaz__action__BatteryAction_GetResult_Request * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Request__are_equal(const interfaz__action__BatteryAction_GetResult_Request * lhs, const interfaz__action__BatteryAction_GetResult_Request * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Request__copy(
  const interfaz__action__BatteryAction_GetResult_Request * input,
  interfaz__action__BatteryAction_GetResult_Request * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Request__Sequence__init(interfaz__action__BatteryAction_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Request__Sequence__fini(interfaz__action__BatteryAction_GetResult_Request__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_GetResult_Request__Sequence *
interfaz__action__BatteryAction_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Request__Sequence__destroy(interfaz__action__BatteryAction_GetResult_Request__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Request__Sequence__are_equal(const interfaz__action__BatteryAction_GetResult_Request__Sequence * lhs, const interfaz__action__BatteryAction_GetResult_Request__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Request__Sequence__copy(
  const interfaz__action__BatteryAction_GetResult_Request__Sequence * input,
  interfaz__action__BatteryAction_GetResult_Request__Sequence * output);

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_GetResult_Response
 * )) before or use
 * interfaz__action__BatteryAction_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Response__init(interfaz__action__BatteryAction_GetResult_Response * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Response__fini(interfaz__action__BatteryAction_GetResult_Response * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_GetResult_Response *
interfaz__action__BatteryAction_GetResult_Response__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Response__destroy(interfaz__action__BatteryAction_GetResult_Response * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Response__are_equal(const interfaz__action__BatteryAction_GetResult_Response * lhs, const interfaz__action__BatteryAction_GetResult_Response * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Response__copy(
  const interfaz__action__BatteryAction_GetResult_Response * input,
  interfaz__action__BatteryAction_GetResult_Response * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Response__Sequence__init(interfaz__action__BatteryAction_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Response__Sequence__fini(interfaz__action__BatteryAction_GetResult_Response__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_GetResult_Response__Sequence *
interfaz__action__BatteryAction_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_GetResult_Response__Sequence__destroy(interfaz__action__BatteryAction_GetResult_Response__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Response__Sequence__are_equal(const interfaz__action__BatteryAction_GetResult_Response__Sequence * lhs, const interfaz__action__BatteryAction_GetResult_Response__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_GetResult_Response__Sequence__copy(
  const interfaz__action__BatteryAction_GetResult_Response__Sequence * input,
  interfaz__action__BatteryAction_GetResult_Response__Sequence * output);

/// Initialize action/BatteryAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaz__action__BatteryAction_FeedbackMessage
 * )) before or use
 * interfaz__action__BatteryAction_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_FeedbackMessage__init(interfaz__action__BatteryAction_FeedbackMessage * msg);

/// Finalize action/BatteryAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_FeedbackMessage__fini(interfaz__action__BatteryAction_FeedbackMessage * msg);

/// Create action/BatteryAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaz__action__BatteryAction_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_FeedbackMessage *
interfaz__action__BatteryAction_FeedbackMessage__create();

/// Destroy action/BatteryAction message.
/**
 * It calls
 * interfaz__action__BatteryAction_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_FeedbackMessage__destroy(interfaz__action__BatteryAction_FeedbackMessage * msg);

/// Check for action/BatteryAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_FeedbackMessage__are_equal(const interfaz__action__BatteryAction_FeedbackMessage * lhs, const interfaz__action__BatteryAction_FeedbackMessage * rhs);

/// Copy a action/BatteryAction message.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_FeedbackMessage__copy(
  const interfaz__action__BatteryAction_FeedbackMessage * input,
  interfaz__action__BatteryAction_FeedbackMessage * output);

/// Initialize array of action/BatteryAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaz__action__BatteryAction_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_FeedbackMessage__Sequence__init(interfaz__action__BatteryAction_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_FeedbackMessage__Sequence__fini(interfaz__action__BatteryAction_FeedbackMessage__Sequence * array);

/// Create array of action/BatteryAction messages.
/**
 * It allocates the memory for the array and calls
 * interfaz__action__BatteryAction_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
interfaz__action__BatteryAction_FeedbackMessage__Sequence *
interfaz__action__BatteryAction_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/BatteryAction messages.
/**
 * It calls
 * interfaz__action__BatteryAction_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
void
interfaz__action__BatteryAction_FeedbackMessage__Sequence__destroy(interfaz__action__BatteryAction_FeedbackMessage__Sequence * array);

/// Check for action/BatteryAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_FeedbackMessage__Sequence__are_equal(const interfaz__action__BatteryAction_FeedbackMessage__Sequence * lhs, const interfaz__action__BatteryAction_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/BatteryAction messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interfaz
bool
interfaz__action__BatteryAction_FeedbackMessage__Sequence__copy(
  const interfaz__action__BatteryAction_FeedbackMessage__Sequence * input,
  interfaz__action__BatteryAction_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INTERFAZ__ACTION__DETAIL__BATTERY_ACTION__FUNCTIONS_H_
