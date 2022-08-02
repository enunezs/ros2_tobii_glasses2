#include "TobiiGlasses2.hpp"
//#include <math.h>
#include <string>


class TobiiGlasses {

  public:
    TobiiGlasses();
    tobiiGlassesConnect();
    tobiiGlassesConnect(const std::string videoStreamAddress);

    void getFrame(cv::Mat &frame);
    //void getEyeFocus2D();
    //void getEyeFocus3D();
    //void getLeftEye();

  private:
    std::string videoStreamAddress;

    bool emulation_mode;
    //camera id (for sim)


}

void TobiiGlasses::TobiiGlasses(){
  const std::string videoStreamAddress = "rtsp://192.168.71.50:8554/live/scene";
  return TobiiGlasses(videoStreamAddress);

}

bool TobiiGlasses::tobiiGlassesConnect(){


}

bool TobiiGlasses::tobiiGlassesConnect(const std::string videoStreamAddress)
  {
    //const std::string videoStreamAddress = "rtsp://192.168.71.50:8554/live/scene";
    capture = cv::VideoCapture(videoStreamAddress);

    if (!capture.open(videoStreamAddress))
    {
      RCLCPP_INFO(this->get_logger(), "Could not connect to Tobii Glasses. Video stream could not open");
      return 1;
    }

    RCLCPP_INFO(this->get_logger(), "Succesfully connected to Tobii Glasses");
    return 0;
  }


void TobiiGlasses::getFrame(cv::Mat &frame)
{
    // Image capturing
    cv::Mat _frame; // OpenCv native format for images
    // http://wiki.ros.org/cv_bridge/Tutorials/UsingCvBridgeToConvertBetweenROSImagesAndOpenCVImages
    if (!capture.read(_frame))
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

    if (!_frame->empty())
    {
      // Code for too slow/too fast framerate here
    }
        return sqrt(d);
}


