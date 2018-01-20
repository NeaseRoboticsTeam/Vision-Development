#in this file, the co-processor (Jetson) will listen in on the SmartDashboard where the OI will display if automated controls are
#pressed, and the co-processor will then execute a file with the necessary algorithm for automation

#import libraries and modules
import sys
import time
import logging
import cv3
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
camera = cv3.VideoCapture(0)

#repeat this action forever
while true:
    #if the placeholder1 button is pressed
    if sd.getBoolean("placeholder1") == true:
        
