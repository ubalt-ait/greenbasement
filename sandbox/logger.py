import serial
import time

print("Logger")

ser = serial.Serial('/dev/ttyACM0')

time.sleep(5)

print("Ready...")

while True:
    print("Sending...")
    ser.write("{\"cmd\":\"Temp\"}".encode())
    #ser.write('5'.encode('ascii')+'\r\n')
    print("Sent...")
    incoming = ser.readline()
    print("Reading...");
    print(incoming.decode())
    time.sleep(1)
