# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TobiiGlasses(type):
    """Metaclass of message 'TobiiGlasses'."""

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
                'tobii_glasses_pkg.msg.TobiiGlasses')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tobii_glasses
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tobii_glasses
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tobii_glasses
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tobii_glasses
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tobii_glasses

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from tobii_glasses_pkg.msg import EyeData
            if EyeData.__class__._TYPE_SUPPORT is None:
                EyeData.__class__.__import_type_support__()

            from tobii_glasses_pkg.msg import GazePosition
            if GazePosition.__class__._TYPE_SUPPORT is None:
                GazePosition.__class__.__import_type_support__()

            from tobii_glasses_pkg.msg import GazePosition3D
            if GazePosition3D.__class__._TYPE_SUPPORT is None:
                GazePosition3D.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TobiiGlasses(metaclass=Metaclass_TobiiGlasses):
    """Message class 'TobiiGlasses'."""

    __slots__ = [
        '_header',
        '_camera_image',
        '_gaze_position',
        '_gaze_position_3d',
        '_right_eye',
        '_left_eye',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'camera_image': 'sensor_msgs/Image',
        'gaze_position': 'tobii_glasses_pkg/GazePosition',
        'gaze_position_3d': 'tobii_glasses_pkg/GazePosition3D',
        'right_eye': 'tobii_glasses_pkg/EyeData',
        'left_eye': 'tobii_glasses_pkg/EyeData',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tobii_glasses_pkg', 'msg'], 'GazePosition'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tobii_glasses_pkg', 'msg'], 'GazePosition3D'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tobii_glasses_pkg', 'msg'], 'EyeData'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tobii_glasses_pkg', 'msg'], 'EyeData'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from sensor_msgs.msg import Image
        self.camera_image = kwargs.get('camera_image', Image())
        from tobii_glasses_pkg.msg import GazePosition
        self.gaze_position = kwargs.get('gaze_position', GazePosition())
        from tobii_glasses_pkg.msg import GazePosition3D
        self.gaze_position_3d = kwargs.get('gaze_position_3d', GazePosition3D())
        from tobii_glasses_pkg.msg import EyeData
        self.right_eye = kwargs.get('right_eye', EyeData())
        from tobii_glasses_pkg.msg import EyeData
        self.left_eye = kwargs.get('left_eye', EyeData())

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
        if self.header != other.header:
            return False
        if self.camera_image != other.camera_image:
            return False
        if self.gaze_position != other.gaze_position:
            return False
        if self.gaze_position_3d != other.gaze_position_3d:
            return False
        if self.right_eye != other.right_eye:
            return False
        if self.left_eye != other.left_eye:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def camera_image(self):
        """Message field 'camera_image'."""
        return self._camera_image

    @camera_image.setter
    def camera_image(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'camera_image' field must be a sub message of type 'Image'"
        self._camera_image = value

    @property
    def gaze_position(self):
        """Message field 'gaze_position'."""
        return self._gaze_position

    @gaze_position.setter
    def gaze_position(self, value):
        if __debug__:
            from tobii_glasses_pkg.msg import GazePosition
            assert \
                isinstance(value, GazePosition), \
                "The 'gaze_position' field must be a sub message of type 'GazePosition'"
        self._gaze_position = value

    @property
    def gaze_position_3d(self):
        """Message field 'gaze_position_3d'."""
        return self._gaze_position_3d

    @gaze_position_3d.setter
    def gaze_position_3d(self, value):
        if __debug__:
            from tobii_glasses_pkg.msg import GazePosition3D
            assert \
                isinstance(value, GazePosition3D), \
                "The 'gaze_position_3d' field must be a sub message of type 'GazePosition3D'"
        self._gaze_position_3d = value

    @property
    def right_eye(self):
        """Message field 'right_eye'."""
        return self._right_eye

    @right_eye.setter
    def right_eye(self, value):
        if __debug__:
            from tobii_glasses_pkg.msg import EyeData
            assert \
                isinstance(value, EyeData), \
                "The 'right_eye' field must be a sub message of type 'EyeData'"
        self._right_eye = value

    @property
    def left_eye(self):
        """Message field 'left_eye'."""
        return self._left_eye

    @left_eye.setter
    def left_eye(self, value):
        if __debug__:
            from tobii_glasses_pkg.msg import EyeData
            assert \
                isinstance(value, EyeData), \
                "The 'left_eye' field must be a sub message of type 'EyeData'"
        self._left_eye = value
