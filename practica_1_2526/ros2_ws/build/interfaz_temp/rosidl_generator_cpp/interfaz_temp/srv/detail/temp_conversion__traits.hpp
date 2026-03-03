// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaz_temp:srv/TempConversion.idl
// generated code does not contain a copyright notice

#ifndef INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__TRAITS_HPP_
#define INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaz_temp/srv/detail/temp_conversion__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaz_temp
{

namespace srv
{

inline void to_flow_style_yaml(
  const TempConversion_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: input_temp
  {
    out << "input_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.input_temp, out);
    out << ", ";
  }

  // member: conversion_type
  {
    out << "conversion_type: ";
    rosidl_generator_traits::value_to_yaml(msg.conversion_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TempConversion_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: input_temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.input_temp, out);
    out << "\n";
  }

  // member: conversion_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "conversion_type: ";
    rosidl_generator_traits::value_to_yaml(msg.conversion_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TempConversion_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaz_temp

namespace rosidl_generator_traits
{

[[deprecated("use interfaz_temp::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaz_temp::srv::TempConversion_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaz_temp::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaz_temp::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaz_temp::srv::TempConversion_Request & msg)
{
  return interfaz_temp::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaz_temp::srv::TempConversion_Request>()
{
  return "interfaz_temp::srv::TempConversion_Request";
}

template<>
inline const char * name<interfaz_temp::srv::TempConversion_Request>()
{
  return "interfaz_temp/srv/TempConversion_Request";
}

template<>
struct has_fixed_size<interfaz_temp::srv::TempConversion_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaz_temp::srv::TempConversion_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaz_temp::srv::TempConversion_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaz_temp
{

namespace srv
{

inline void to_flow_style_yaml(
  const TempConversion_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: converted_temp
  {
    out << "converted_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.converted_temp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TempConversion_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: converted_temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "converted_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.converted_temp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TempConversion_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaz_temp

namespace rosidl_generator_traits
{

[[deprecated("use interfaz_temp::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaz_temp::srv::TempConversion_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaz_temp::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaz_temp::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaz_temp::srv::TempConversion_Response & msg)
{
  return interfaz_temp::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaz_temp::srv::TempConversion_Response>()
{
  return "interfaz_temp::srv::TempConversion_Response";
}

template<>
inline const char * name<interfaz_temp::srv::TempConversion_Response>()
{
  return "interfaz_temp/srv/TempConversion_Response";
}

template<>
struct has_fixed_size<interfaz_temp::srv::TempConversion_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaz_temp::srv::TempConversion_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaz_temp::srv::TempConversion_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaz_temp::srv::TempConversion>()
{
  return "interfaz_temp::srv::TempConversion";
}

template<>
inline const char * name<interfaz_temp::srv::TempConversion>()
{
  return "interfaz_temp/srv/TempConversion";
}

template<>
struct has_fixed_size<interfaz_temp::srv::TempConversion>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaz_temp::srv::TempConversion_Request>::value &&
    has_fixed_size<interfaz_temp::srv::TempConversion_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaz_temp::srv::TempConversion>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaz_temp::srv::TempConversion_Request>::value &&
    has_bounded_size<interfaz_temp::srv::TempConversion_Response>::value
  >
{
};

template<>
struct is_service<interfaz_temp::srv::TempConversion>
  : std::true_type
{
};

template<>
struct is_service_request<interfaz_temp::srv::TempConversion_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaz_temp::srv::TempConversion_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__TRAITS_HPP_
