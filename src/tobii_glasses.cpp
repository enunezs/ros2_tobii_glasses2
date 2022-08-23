#include "tobii_glasses.hpp"
//#include <math.h>
#include <string>
#include <iostream>
using namespace std;



/*
// * CV
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
*/


namespace tobii_glasses {


//TobiiGlasses::TobiiGlasses(){
//}

bool TobiiGlasses::tobiiGlassesConnect(){
  const std::string videoStreamAddress = "rtsp://192.168.71.50:8554/live/scene";
  return tobiiGlassesConnect(videoStreamAddress);
}

// make a function that starts connection to the  webcam


// Send 0 for webcam mode
bool TobiiGlasses::tobiiGlassesConnect(const std::string videoStreamAddress){

  // * Start connection
  cv::VideoCapture capture; //(videoStreamAddress);
    // *Debug mode
    if (videoStreamAddress == "0") {
      capture = cv::VideoCapture(0);
  }
  else{
    // *Connection to glasses
    //const std::string videoStreamAddress = "rtsp://192.168.71.50:8554/live/scene";
    capture = cv::VideoCapture(videoStreamAddress);
  }
    
  // *Check and return if succesful
    if (!capture.open(videoStreamAddress))
    {
      //RCLCPP_INFO(this->get_logger(), "Could not connect to Tobii Glasses. Video stream could not open");
      return 1;
    }
      //RCLCPP_INFO(this->get_logger(), "Succesfully connected to Tobii Glasses");
    return 0;

}

} //namespace TobiiGlasses


/*
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
}
*/

//#include "rclcpp_components/register_node_macro.hpp"
//RCLCPP_COMPONENTS_REGISTER_NODE(tobii_glasses::TobiiGlasses)