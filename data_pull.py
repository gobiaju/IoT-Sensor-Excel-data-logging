#Import modules
import serial
import datetime
import time
#connect the serial port to  the arduino and the baud rate
arduino_port = "/dev/cu.usbmodem141101"
baud = 9600
serial = serial.Serial(arduino_port, baud)
#set the file name
file_name = "sensor_data_log.csv"
file = open(file_name, "w")

while True:
    time_stamp = datetime.datetime.now()
    get_data = str(serial.readline(),'utf-8')
    data = [str(time_stamp),get_data.strip()]
    print(data)
    file = open(file_name, "a")
    file.write(",".join(data) + "\n")
file.close()
