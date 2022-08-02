#ifndef TOBIIGLASSES_H
#define TOBIIGLASSES_H

#include <string>
using namespace std;

#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc.hpp>

//#include "cv_bridge/cv_bridge.h"
//#include "opencv2/highgui/highgui.hpp"
//#include "image_transport/image_transport.hpp"
//using namespace cv;

//namespace tobii_glasses

class TobiiGlasses {

  public:
    TobiiGlasses();
    bool tobiiGlassesConnect();
    bool tobiiGlassesConnect(const std::string videoStreamAddress);

    void getFrame(cv::Mat & frame);
    //void getEyeFocus2D();
    //void getEyeFocus3D();
    //void getLeftEye();

  private:
    std::string videoStreamAddress;

    bool emulation_mode;
    //camera id (for sim)
};

#endif