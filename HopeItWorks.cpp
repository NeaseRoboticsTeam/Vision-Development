/*Sources:
https://stackoverflow.com/questions/22531480/how-to-use-kinect-with-openni-and-opencv
https://github.com/opencv/opencv/blob/master/samples/cpp/openni_capture.cpp
https://docs.opencv.org/2.4.13.2/doc/user_guide/ug_kinect.html
https://www.chiefdelphi.com/forums/showthread.php?t=112694

@author Christian
@author Aditya
*/


#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include “opencv2”
#include <>

using namespace std;
using namespace cv2;

int main() 
{
  cout << “opening device(s) << endl;

  //Initialize NetworkTables with Smart Dashboard
  nt::NetworkTableInstance::SetIPAddress("//teamIP");//driverstation IP
  nt::NetworkTableInstance::SetClientMode();
  nt::NetworkTableInstance::SetTeam(6468);
  nt::NetworkTableInstance::Initialize();

  //setup the smart dashboard (sd)
  nt::NetworkTableInstance * sd;
  sd->GetTable(“SmartDashboard”);

  VideoCapture kinect;
  sensor1.open(CV_CAP_OPENNI);

  switch (sd->getString(“Vision”))
  {
    case “getCube” : 
	    getCube();

    case “placeHolder2” :
	    placeHolder2();

    default :
      Cout << “Nothing to do” << endl;
  }
}

Public void getCube (NetworkTable * smartDashboard, VideoCapture sensor)
{
  sensor.open(CV_MAP_OPENNI);
  Mat rgb, depth;
	Mat corners;
	int height = kinect.get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = kinect.get(CV_CAP_PROP_FRAME_WIDTH);
  for(;;)
  {
	  kinect.grab();	
		capture.retrieve(rgb, CAP_OPENNI_DEPTH_MAP);
		capture.retrieve( bgrImage, CAP_OPENNI_BGR_IMAGE);
  }
	corners = cornerHarris(mat, depth, 2, 3, 0.05);
	
	int cornersDetected = 0;
	
	for (int x = width; x > 0; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (rgb(x, y) == [255, 255, 0] && corners(x, y) > 0.5)
			{
				cornersDetected++;
			}
			if (cornersDetected == 6)
			{
				cout << "Maximum amount of corners detected, breaking loop." << endl;
				break;
			}
		}
		if (cornersDetected == 6)
		{
			cout << "Follow through with loop break for corners" << endl;
			break;
		}
	}
	cout << "Loop broken" << endl;
}
