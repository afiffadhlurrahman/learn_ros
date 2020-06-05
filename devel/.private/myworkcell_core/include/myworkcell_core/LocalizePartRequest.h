// Generated by gencpp from file myworkcell_core/LocalizePartRequest.msg
// DO NOT EDIT!


#ifndef MYWORKCELL_CORE_MESSAGE_LOCALIZEPARTREQUEST_H
#define MYWORKCELL_CORE_MESSAGE_LOCALIZEPARTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace myworkcell_core
{
template <class ContainerAllocator>
struct LocalizePartRequest_
{
  typedef LocalizePartRequest_<ContainerAllocator> Type;

  LocalizePartRequest_()
    : base_frame()  {
    }
  LocalizePartRequest_(const ContainerAllocator& _alloc)
    : base_frame(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _base_frame_type;
  _base_frame_type base_frame;





  typedef boost::shared_ptr< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> const> ConstPtr;

}; // struct LocalizePartRequest_

typedef ::myworkcell_core::LocalizePartRequest_<std::allocator<void> > LocalizePartRequest;

typedef boost::shared_ptr< ::myworkcell_core::LocalizePartRequest > LocalizePartRequestPtr;
typedef boost::shared_ptr< ::myworkcell_core::LocalizePartRequest const> LocalizePartRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator1> & lhs, const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator2> & rhs)
{
  return lhs.base_frame == rhs.base_frame;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator1> & lhs, const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace myworkcell_core

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c5742700117844b07d72df47ca3da17d";
  }

  static const char* value(const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc5742700117844b0ULL;
  static const uint64_t static_value2 = 0x7d72df47ca3da17dULL;
};

template<class ContainerAllocator>
struct DataType< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "myworkcell_core/LocalizePartRequest";
  }

  static const char* value(const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"string base_frame\n"
;
  }

  static const char* value(const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.base_frame);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LocalizePartRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::myworkcell_core::LocalizePartRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::myworkcell_core::LocalizePartRequest_<ContainerAllocator>& v)
  {
    s << indent << "base_frame: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.base_frame);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MYWORKCELL_CORE_MESSAGE_LOCALIZEPARTREQUEST_H
