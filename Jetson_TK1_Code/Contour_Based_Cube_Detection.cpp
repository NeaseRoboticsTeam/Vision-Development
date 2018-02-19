/*Sources:
Convert a Kinect color image to HSV, filter the image so that only yellow is visible, extract contours, and then get the biggest
contour. This contour detection would then return the coordinates of the closest cube.

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
#include <opencv2>
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

  //kinect set up
  VideoCapture kinect(CAP_OPENNI2);
  
  switch (sd->getString(“Vision”))
  {
		//do the getCube function if presented to the sd
    case “getCube” : 
	    vals[2] = getCube(kinectPtr);
    	    sd->putData(vals[0], "Autonomous X Vals");
	    sd->putData(vals[1], "Autonomous Y Vals");
		  
    //placeholder case
    case “placeHolder2” :
	    placeHolder2();

    default :
      Cout << “Nothing to do” << endl;
  }
}

public array getCube (VideoCapture &sensor)
{
	//set up the depth and rgb images as well as the matrix to store the corners
 	Mat bgr, depth;
	Rect bounding_rect;
	
	//get kinect frame height and width
	int height = sensor->get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = sensor->get(CV_CAP_PROP_FRAME_WIDTH);
	
	//get the depth and bgr image from kinect
	sensor->grab();
	depth = sensor->retrieve(rgb, CAP_OPENNI_DEPTH_MAP);
	bgr = sensor->retrieve(bgrImage, CAP_OPENNI_BGR_IMAGE);
	
	//convert bgr image from kinect to hsv for better contours and filter out for yellow
	Mat hsv = cvtColor(bgr, hsv, BGR2RGB);
	Mat thresholdHsv = cvInRangeS(hsv, cvScalar(20, 100, 100), cvScalar(30, 255, 255), thresholdHsv);
	
	// Vector for storing contour
	let contours = new cv.MatVector();
	let hierarchy = new cv.Mat();
	
	// Find the contours in the image
    	findContours(thresholdHsv, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE); 
  
	// iterate through each contour.
     	for( int i = 0; i< contours.size(); i++ )  
      	{
		//  Find the area of contour
       		double a=contourArea( contours[i],false);  
       		if(a>largest_area)
		{
			largest_area=a;
			//Store the index of largest contour
       			largest_contour_index=i;                
			// Find the bounding rectangle for biggest contour
       			bounding_rect=boundingRect(contours[i]);
		}
       	}

	//getting the center of the contour
	//save opposite corners of bounding rectangle
	Point * p1 = bounding_rect.pt1;
	Point * p2 = bounding_rect.pt2;
	
	//store the average x and y values to an array and output it
	int xy[2];
	xy[0] = ((p1->x) + (p2->x))/2;
	xy[1] = ((p1->y) + (p2->y))/2;
	Point * point = Point((p1->x) + (p2->x)/2, (p1->y) + (p2->y)/2);
	return xy;
}
