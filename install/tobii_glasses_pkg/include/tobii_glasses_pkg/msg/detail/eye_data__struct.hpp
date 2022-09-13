// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__STRUCT_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tobii_glasses_pkg__msg__EyeData __attribute__((deprecated))
#else
# define DEPRECATED__tobii_glasses_pkg__msg__EyeData __declspec(deprecated)
#endif

namespace tobii_glasses_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EyeData_
{
  using Type = EyeData_<ContainerAllocator>;

  explicit EyeData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->name = "";
      std::fill<typename std::array<float, 3>::iterator, float>(this->pupil_center.begin(), this->pupil_center.end(), 0.0f);
      this->pupil_diameter = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->gaze_direction.begin(), this->gaze_direction.end(), 0.0f);
    }
  }

  explicit EyeData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    pupil_center(_alloc),
    gaze_direction(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->name = "";
      std::fill<typename std::array<float, 3>::iterator, float>(this->pupil_center.begin(), this->pupil_center.end(), 0.0f);
      this->pupil_diameter = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->gaze_direction.begin(), this->gaze_direction.end(), 0.0f);
    }
  }

  // field types and members
  using _status_type =
    uint8_t;
  _status_type status;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _pupil_center_type =
    std::array<float, 3>;
  _pupil_center_type pupil_center;
  using _pupil_diameter_type =
    float;
  _pupil_diameter_type pupil_diameter;
  using _gaze_direction_type =
    std::array<float, 3>;
  _gaze_direction_type gaze_direction;

  // setters for named parameter idiom
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__pupil_center(
    const std::array<float, 3> & _arg)
  {
    this->pupil_center = _arg;
    return *this;
  }
  Type & set__pupil_diameter(
    const float & _arg)
  {
    this->pupil_diameter = _arg;
    return *this;
  }
  Type & set__gaze_direction(
    const std::array<float, 3> & _arg)
  {
    this->gaze_direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> *;
  using ConstRawPtr =
    const tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tobii_glasses_pkg__msg__EyeData
    std::shared_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tobii_glasses_pkg__msg__EyeData
    std::shared_ptr<tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EyeData_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->pupil_center != other.pupil_center) {
      return false;
    }
    if (this->pupil_diameter != other.pupil_diameter) {
      return false;
    }
    if (this->gaze_direction != other.gaze_direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const EyeData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EyeData_

// alias to use template instance with default allocator
using EyeData =
  tobii_glasses_pkg::msg::EyeData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__STRUCT_HPP_
