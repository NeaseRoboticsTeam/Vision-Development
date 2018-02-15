/*Sources:
https://stackoverflow.com/questions/22531480/how-to-use-kinect-with-openni-and-opencv
https://github.com/opencv/opencv/blob/master/samples/cpp/openni_capture.cpp
https://docs.opencv.org/2.4.13.2/doc/user_guide/ug_kinect.html
https://www.chiefdelphi.com/forums/showthread.php?t=112694

@author Christian
@author Aditya
@author Rishabh
*/

/*import important modules where
opencv is for image processing,
openni is for interacting with the kinect rgb and depth images,
and ntcore is for accessing networktables to communicate with the roboRIO*/

#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <opencv2>
#include "OpenNi2"
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

public void getCube (VideoCapture &sensor)
{
	//set up the depth and rgb images as well as the matrix to store the corners
 	Mat rgb, depth;
	Rect bounding_rect;
	
	int height = sensor->get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = sensor->get(CV_CAP_PROP_FRAME_WIDTH);
		
	depth = sensor->retrieve(rgb, CAP_OPENNI_DEPTH_MAP);
	rgb = sensor->retrieve(bgrImage, CAP_OPENNI_BGR_IMAGE);
	
	// Vector for storing contour
	vector<vector<Point>> contours; 
    	vector<Vec4i> hierarchy;

	// Find the contours in the image
    	findContours(rgb, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE); 
  
     	for( int i = 0; i< contours.size(); i++ ) // iterate through each contour. 
      	{
       		double a=contourArea( contours[i],false);  //  Find the area of contour
       		if(a>largest_area){
       		largest_area=a;
		//Store the index of largest contour
       		largest_contour_index=i;                
		// Find the bounding rectangle for biggest contour
       		bounding_rect=boundingRect(contours[i]);
       }
		
}
