//in this file, the co-processor (Jetson or RPi) will listen in on the SmartDashboard where the OI will display if automated controls are
//pressed, and the co-processor will then execute a file with the necessary algorithm for automation

//import libraries and modules
import sys
import time
import logging
import cv3
from networktables import NetworkTables

//setup logging
logging.basicConfig(level=logging.DEBUG)

//setup ip address
if len(sys.argv) != 2:
    print("Error: specify an IP to connect to!")
    exit(0)
ip = sys.argv[1]

//initializations and setup
NetworkTables.initialize(server=ip)
sd = NetworkTables.getTable("SmartDashboard")
camera = cv3.VideoCapture(0)

