# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tobii_glasses_pkg:msg/EyeData.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'pupil_center'
# Member 'gaze_direction'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EyeData(type):
    """Metaclass of message 'EyeData'."""

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
                'tobii_glasses_pkg.msg.EyeData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__eye_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__eye_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__eye_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__eye_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__eye_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EyeData(metaclass=Metaclass_EyeData):
    """Message class 'EyeData'."""

    __slots__ = [
        '_status',
        '_name',
        '_pupil_center',
        '_pupil_diameter',
        '_gaze_direction',
    ]

    _fields_and_field_types = {
        'status': 'uint8',
        'name': 'string',
        'pupil_center': 'float[3]',
        'pupil_diameter': 'float',
        'gaze_direction': 'float[3]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        self.name = kwargs.get('name', str())
        if 'pupil_center' not in kwargs:
            self.pupil_center = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.pupil_center = numpy.array(kwargs.get('pupil_center'), dtype=numpy.float32)
            assert self.pupil_center.shape == (3, )
        self.pupil_diameter = kwargs.get('pupil_diameter', float())
        if 'gaze_direction' not in kwargs:
            self.gaze_direction = numpy.zeros(3, dtype=numpy.float32)
        else:
            self.gaze_direction = numpy.array(kwargs.get('gaze_direction'), dtype=numpy.float32)
            assert self.gaze_direction.shape == (3, )

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
        if self.status != other.status:
            return False
        if self.name != other.name:
            return False
        if all(self.pupil_center != other.pupil_center):
            return False
        if self.pupil_diameter != other.pupil_diameter:
            return False
        if all(self.gaze_direction != other.gaze_direction):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @property
    def pupil_center(self):
        """Message field 'pupil_center'."""
        return self._pupil_center

    @pupil_center.setter
    def pupil_center(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'pupil_center' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'pupil_center' numpy.ndarray() must have a size of 3"
            self._pupil_center = value
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
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'pupil_center' field must be a set or sequence with length 3 and each value of type 'float'"
        self._pupil_center = numpy.array(value, dtype=numpy.float32)

    @property
    def pupil_diameter(self):
        """Message field 'pupil_diameter'."""
        return self._pupil_diameter

    @pupil_diameter.setter
    def pupil_diameter(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pupil_diameter' field must be of type 'float'"
        self._pupil_diameter = value

    @property
    def gaze_direction(self):
        """Message field 'gaze_direction'."""
        return self._gaze_direction

    @gaze_direction.setter
    def gaze_direction(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'gaze_direction' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'gaze_direction' numpy.ndarray() must have a size of 3"
            self._gaze_direction = value
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
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'gaze_direction' field must be a set or sequence with length 3 and each value of type 'float'"
        self._gaze_direction = numpy.array(value, dtype=numpy.float32)
