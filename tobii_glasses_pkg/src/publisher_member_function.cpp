#include <chrono>
#include <functional>
#include <memory>
#include <string>

// ROS2
#include "rclcpp/rclcpp.hpp"
#include <rclcpp/qos.hpp>
//#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/header.hpp"

// CV
//#include <opencv2/opencv.hpp>
//#include <opencv/cv.h>
#include "cv_bridge/cv_bridge.h"
#include <opencv2/opencv.hpp>
// #include <sensor_msgs/msg/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <stdio.h>

// Messages
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"

#include <image_transport/image_transport.hpp>

//#include <cv_bridge/cv_bridge.h>

// /#include "Tobii_Glasses_2_Python3_And_C/"

using namespace std::chrono_literals;
using namespace cv;
using namespace std;

// Parameters
int publish_rate = 0.01;

// TODO: Send compressed?
// Research first

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

cv::VideoCapture capture; //(videoStreamAddress);

/**
class TobiiGlasses {

  public:
    std::string videoStreamAddress = "rtsp://192.168.71.50:8554/live/scene";


};
**/

//    camera_info_pub_ = image_transport::create_camera_publisher(this, "image", custom_qos_profile);

class TobiiGlassesPublisher : public rclcpp::Node
{
public:
  TobiiGlassesPublisher()
      : Node("tobii_glasses_publisher_node"), count_(0)
  { // Initialization
    // Send custom msg for glasses, packaging all needed elements
    // Start simple first, independent parts
    // Compressed Image for camera feed
    video_stream_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("tobii_glasses/camera_compressed", 1); // TODO: Change to custom msg
    // String for eye info
    eye_stream_publisher_ = this->create_publisher<std_msgs::msg::String>("tobii_glasses/eye_info", 1); // TODO: Change to custom msg
    // Eye feed exisgts as well?

    timer_ = this->create_wall_timer(
        500ms, std::bind(&TobiiGlassesPublisher::timer_callback, this));

    tobii_glasses_connect();
  }

private:
  void timer_callback() // Callback function
  {
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    eye_stream_publisher_->publish(message);

    // Image capturing
    cv::Mat frame; // OpenCv native format for images

    // http://wiki.ros.org/cv_bridge/Tutorials/UsingCvBridgeToConvertBetweenROSImagesAndOpenCVImages

    if (!capture.read(frame))
    {

      RCLCPP_INFO(this->get_logger(), "No image ");
      return;
    }
    else
    {
      // success
      RCLCPP_INFO(this->get_logger(), "got image!");

      // cv::imshow("scene", frame);
      // cv::waitKey(30);
    }

    if (!frame.empty())
    {
      // Code for too slow/too fast framerate here
    }

    // Image editting here, for resizing and optimizing
    // copy to get a mutable CvImage

    // frame
    // void toImageMsg(sensor_msgs::Image& ros_image) const;

    // Image conversion
    // sensor_msgs::ImagePtr ros_img = toImageMsg(&frame);

    // Pack messqages for sending
    ConvertFrameToMessage(frame);

    cv_bridge::CvImage cv_ptr;

    if (!frame.empty())
    {
      // msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
      video_stream_publisher_.publish(msg);
    }

    auto image_msg_ = ConvertFrameToMessage(frame);

    // auto message = sensor_msgs::msg::Image();
    // frame
  }

  int tobii_glasses_connect()
  {

    const std::string videoStreamAddress = "rtsp://192.168.71.50:8554/live/scene";
    capture = cv::VideoCapture(videoStreamAddress);

    if (!capture.open(videoStreamAddress))
    {

      return 1;
    }

    // cv::Mat frame;

    return 0;
  }

  std::shared_ptr<sensor_msgs::msg::Image> ConvertFrameToMessage(cv::Mat &frame)
  {

    std_msgs::msg::Header header_;
    sensor_msgs::msg::Image ros_image;

    // Make sure output in the size the user wants even if it is not native
    /*
    if (frame.rows != image_width_ || frame.cols != image_height_)
    {
      cv::resize(frame, frame, cv::Size(image_width_, image_height_));
    }
    */

    /* To remove CV-bridge and boost-python3 dependencies, this is pretty much a copy of the toImageMsg method in cv_bridge. */
    ros_image.header = header_;
    ros_image.height = frame.rows;
    ros_image.width = frame.cols;
    ros_image.encoding = "bgr8";

    /* FIXME c++20 has std::endian */
    // ros_image.is_bigendian = (std::endian::native == std::endian::big);
    ros_image.is_bigendian = false;
    ros_image.step = frame.cols * frame.elemSize();
    size_t size = ros_image.step * frame.rows;
    ros_image.data.resize(size);

    auto msg_ptr_ = std::make_shared<sensor_msgs::msg::Image>(ros_image);
    return msg_ptr_;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr video_stream_publisher_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr eye_stream_publisher_;
  size_t count_;
};

int main(int argc, char *argv[])
{
  // Init
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);
  rclcpp::init(argc, argv);

  // QoS
  //  https://github.com/ros2/ros2/wiki/About-Quality-of-Service-Settings
  rclcpp::QoS video_qos(1);
  video_qos.keep_last(1);
  video_qos.best_effort();
  video_qos.durability_volatile();

  rclcpp::executors::SingleThreadedExecutor exec;

  // const rclcpp::NodeOptions options;
  // exec.add_node(usb_camera_driver);
  // exec.spin();

  // auto node

  // Run node
  rclcpp::spin(std::make_shared<TobiiGlassesPublisher>());

  // Shutdown if the node is stopped using Ctrl+C
  rclcpp::shutdown();
  return 0;
}
