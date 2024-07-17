import serial
import time

port = 'COM3'
boundrate = 9600
timeout = 1
ser = serial.Serial(port, boundrate, timeout=timeout)
while 1:
    message = 'a1245b'
    ser.write(message.encode('utf-8'))
    print('uga')
    time.sleep(2)
ser.close()