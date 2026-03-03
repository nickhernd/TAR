// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaz_temp:srv/TempConversion.idl
// generated code does not contain a copyright notice

#ifndef INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__BUILDER_HPP_
#define INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaz_temp/srv/detail/temp_conversion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaz_temp
{

namespace srv
{

namespace builder
{

class Init_TempConversion_Request_conversion_type
{
public:
  explicit Init_TempConversion_Request_conversion_type(::interfaz_temp::srv::TempConversion_Request & msg)
  : msg_(msg)
  {}
  ::interfaz_temp::srv::TempConversion_Request conversion_type(::interfaz_temp::srv::TempConversion_Request::_conversion_type_type arg)
  {
    msg_.conversion_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaz_temp::srv::TempConversion_Request msg_;
};

class Init_TempConversion_Request_input_temp
{
public:
  Init_TempConversion_Request_input_temp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TempConversion_Request_conversion_type input_temp(::interfaz_temp::srv::TempConversion_Request::_input_temp_type arg)
  {
    msg_.input_temp = std::move(arg);
    return Init_TempConversion_Request_conversion_type(msg_);
  }

private:
  ::interfaz_temp::srv::TempConversion_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaz_temp::srv::TempConversion_Request>()
{
  return interfaz_temp::srv::builder::Init_TempConversion_Request_input_temp();
}

}  // namespace interfaz_temp


namespace interfaz_temp
{

namespace srv
{

namespace builder
{

class Init_TempConversion_Response_converted_temp
{
public:
  Init_TempConversion_Response_converted_temp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaz_temp::srv::TempConversion_Response converted_temp(::interfaz_temp::srv::TempConversion_Response::_converted_temp_type arg)
  {
    msg_.converted_temp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaz_temp::srv::TempConversion_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaz_temp::srv::TempConversion_Response>()
{
  return interfaz_temp::srv::builder::Init_TempConversion_Response_converted_temp();
}

}  // namespace interfaz_temp

#endif  // INTERFAZ_TEMP__SRV__DETAIL__TEMP_CONVERSION__BUILDER_HPP_
