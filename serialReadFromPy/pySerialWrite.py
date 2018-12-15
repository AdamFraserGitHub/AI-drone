import serial

#set physical port on PC and baud rate (COM3 is USB3 port closest to you)
arduinoSerial = serial.Serial('/dev/ttyACM0', 9600)

arduinoSerial.write(b'this is from python!!!!')
