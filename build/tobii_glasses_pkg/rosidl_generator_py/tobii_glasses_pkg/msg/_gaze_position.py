# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tobii_glasses_pkg:msg/GazePosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'gaze_position'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GazePosition(type):
    """Metaclass of message 'GazePosition'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tobii_glasses_pkg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tobii_glasses_pkg.msg.GazePosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gaze_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gaze_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gaze_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gaze_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gaze_position

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GazePosition(metaclass=Metaclass_GazePosition):
    """Message class 'GazePosition'."""

    __slots__ = [
        '_glasses_header',
        '_status',
        '_latency',
        '_gaze_index',
        '_gaze_position',
    ]

    _fields_and_field_types = {
        'glasses_header': 'std_msgs/Header',
        'status': 'uint8',
        'latency': 'uint32',
        'gaze_index': 'uint32',
        'gaze_position': 'float[2]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.glasses_header = kwargs.get('glasses_header', Header())
        self.status = kwargs.get('status', int())
        self.latency = kwargs.get('latency', int())
        self.gaze_index = kwargs.get('gaze_index', int())
        if 'gaze_position' not in kwargs:
            self.gaze_position = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.gaze_position = numpy.array(kwargs.get('gaze_position'), dtype=numpy.float32)
            assert self.gaze_position.shape == (2, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.glasses_header != other.glasses_header:
            return False
        if self.status != other.status:
            return False
        if self.latency != other.latency:
            return False
        if self.gaze_index != other.gaze_index:
            return False
        if all(self.gaze_position != other.gaze_position):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def glasses_header(self):
        """Message field 'glasses_header'."""
        return self._glasses_header

    @glasses_header.setter
    def glasses_header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'glasses_header' field must be a sub message of type 'Header'"
        self._glasses_header = value

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'status' field must be an unsigned integer in [0, 255]"
        self._status = value

    @property
    def latency(self):
        """Message field 'latency'."""
        return self._latency

    @latency.setter
    def latency(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'latency' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'latency' field must be an unsigned integer in [0, 4294967295]"
        self._latency = value

    @property
    def gaze_index(self):
        """Message field 'gaze_index'."""
        return self._gaze_index

    @gaze_index.setter
    def gaze_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gaze_index' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'gaze_index' field must be an unsigned integer in [0, 4294967295]"
        self._gaze_index = value

    @property
    def gaze_position(self):
        """Message field 'gaze_position'."""
        return self._gaze_position

    @gaze_position.setter
    def gaze_position(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'gaze_position' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'gaze_position' numpy.ndarray() must have a size of 2"
            self._gaze_position = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'gaze_position' field must be a set or sequence with length 2 and each value of type 'float'"
        self._gaze_position = numpy.array(value, dtype=numpy.float32)
