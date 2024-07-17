import serial
import time

port = 'COM3'
boundrate = 9600
timeout = 1
ser = serial.Serial(port, boundrate, timeout=timeout)
while True: 
    if ser.isOpen() == True:  
        try:
            if ser.inWaiting():
                try:
                    command = ser.readline()
                    cmd_dec = command.decode()
                    print(cmd_dec)

                except ValueError:
                    print("value error")

                
        except IOError:
            print("IO error")