/*Sources:
https://stackoverflow.com/questions/22531480/how-to-use-kinect-with-openni-and-opencv
https://github.com/opencv/opencv/blob/master/samples/cpp/openni_capture.cpp
https://docs.opencv.org/2.4.13.2/doc/user_guide/ug_kinect.html
https://www.chiefdelphi.com/forums/showthread.php?t=112694*/


#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include “opencv2”
#include <>
#include <Chrono>

using namespace std;
using namespace cv2;

int main() 
{
  cout << “opening device(s) << endl;

  //Initialize NetworkTables with Smart Dashboard
  NetworkTable::SetIPAddress("//teamIP");//driverstation IP
  NetworkTable::SetClientMode();
  NetworkTable::SetTeam(6468);
  NetworkTable::Initialize()

  //setup the smart dashboard (sd)
  NetworkTable * sd;
  sd->GetTable(“SmartDashboard”);

  VideoCapture kinect;
  sensor1.open(CV_CAP_OPENNI);

  switch(sd->getString(“Vision”))
  {
    case “getCube” : 
	    getCube();

    case “placeHolder2” :
	    placeHolder2();

    default :
      Cout << “Do nothing” << endl;
  }
}

Public void getCube(NetworkTable * smartDashboard, VideoCapture sensor)
{
  sensor.open(CV_MAP_OPENNI);
  Mat rgb, depth;
  for(;;)
  {
	  kinect.grab();	
		capture.retrieve(rgb, CAP_OPENNI_DEPTH_MAP);
		capture.retrieve( bgrImage, CAP_OPENNI_BGR_IMAGE);
  }
}






















