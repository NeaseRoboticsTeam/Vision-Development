/*Sources:
https://stackoverflow.com/questions/22531480/how-to-use-kinect-with-openni-and-opencv
https://github.com/opencv/opencv/blob/master/samples/cpp/openni_capture.cpp
https://docs.opencv.org/2.4.13.2/doc/user_guide/ug_kinect.html
https://www.chiefdelphi.com/forums/showthread.php?t=112694

@author Christian
@author Aditya
*/

/*import important modules where
opencv is for image processing,
openni is for interacting with the kinect rgb and depth images,
and ntcore is for accessing networktables to communicate with the roboRIO*/

#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include “opencv”
#include "openni"
#include "ntcore"

//get some namespaces
using namespace std;
using namespace cv2;

int main() 
{
	//initializing stuff
  cout << “opening device(s) << endl;
  auto inst = nt::GetDefaultInstance();

	//set up the client on ntcore and get the smartdashboard to a pointer
  nt::NetworkTableInstance::StartClient(inst, "VisionServer", kDefaultPort);
  nt::NetworkTableInstance * sd;
  sd->nt::NetworkTableInstance::GetTable("SmartDashboard");

	//get a pointer to the kinect set up
  VideoCapture kinect(CV_CAP_OPENNI);
  VideoCapture * kinectPtr = &kinect;

  switch (sd->getString(“Vision”))
  {
		//do the getCube function if presented to the sd
    case “getCube” : 
	    getCube(sd, kinectPtr);

		//placeholder case
    case “placeHolder2” :
	    placeHolder2();

    default :
      Cout << “Nothing to do” << endl;
  }
}

Public void getCube (NetworkTable * smartDashboard, VideoCapture * sensor)
{
	//set up the depth and rgb images as well as the matrix to store the corners
  Mat rgb, depth, corners;
	int height = sensor->get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = sensor->get(CV_CAP_PROP_FRAME_WIDTH);
	sensor->grab();	
	sensor->retrieve(rgb, CAP_OPENNI_DEPTH_MAP);
	sensor->retrieve(bgrImage, CAP_OPENNI_BGR_IMAGE);
	cornerHarris(depth, corners, 2, 3, 0.05);
	int cornersDetected = 0;
	int yVals[3];

	float distanceToTravel;

	for (int x = width; x > 0; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (rgb(x, y) == [255, 255, 0] && corners(x, y) > 0.5)
			{
				cornersDetected++;

				yVals[cornersDetected-1] = y;
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
	sd->putNumber("Trajectory", (yVals[0]+yVals[1]+yVals[2])/3);
	sd->putNumber("Distance_To_Drive", depth(x, y));

}
