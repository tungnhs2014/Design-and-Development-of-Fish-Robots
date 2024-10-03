import serial
import os
f = os.popen('ls /dev/ttyS0')
now = f.read()
now=now[:-1]
ser = serial.Serial(now,9600)
ser.write("5")