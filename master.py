#in this file, the co-processor (Jetson) will listen in on the SmartDashboard where the OI will display if automated controls are
#pressed, and the co-processor will then execute a file with the necessary algorithm for automation

#import libraries and modules
import sys
import time
import logging
import cv2
from networktables import NetworkTables

#setup logging
logging.basicConfig(level=logging.DEBUG)

#setup ip address
if len(sys.argv) != 2:
    print("Error: specify an IP to connect to!")
    exit(0)

#initializations and setup
NetworkTables.initialize(server='roborio-6468-frc.local')
sd = NetworkTables.getTable("SmartDashboard")
camera = cv2.VideoCapture(0)

#repeat this action forever
while true:
    #if the placeholder1 button is pressed
    if sd.getString("Automation_Controls") == "Get_Power_Cube_Trajectory":
        centroidOfCorners[1] = getCubeTrajectory()
        sd.putString("Automation_Controls", "Co-Processor Reply: Function Executed")
        sd.putString("Go To (X,Y)", str(centroidofCorners[0]) + str(centroidOfCorners[1]))

def getCubeTrajectory():
    ret, frame = camera.read()
    corners = cv2.cornerHarris(frame, 5, 4, 0.04)
    corner = 0
    xVals[2]
    yVals[2]
    for x in range (0, corners.width):
        for y in range (corners.height, corners.height/2):
            if frame(x, y) == [255, 255, 0]:
                if corners(x, y) > 0.5:
                    corner = corner + 1
                    xVals[counter-1] = x
                    yVals[counter-1] = y            
        if corner = 3:
            break
    averages[1]
    averages[0] = (xVals[1] + xVals[2] + xVals[3])/3
    averages[1] = (yVals[1] + yVals[2] + yVals[3])/3
    return averages