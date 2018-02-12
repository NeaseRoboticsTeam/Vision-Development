#include <iostream>
#include <opencv2/opencv.hpp>
#include <OpenNI2>
#include <SensorKinect>

int main()
{
  VideoCapture capture(CAP_OPENNI);
  while(true)
  {
    Mat depthMap;
    Mat bgrImage;
    capture.grab();
    capture.retrieve( depthMap, CAP_OPENNI_DEPTH_MAP );
    capture.retrieve( bgrImage, CAP_OPENNI_BGR_IMAGE );
    if( waitKey( 30 ) >= 0 )
        break;
  }
}
