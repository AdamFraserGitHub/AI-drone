import serial

arduinoSerial = serial.Serial('/dev/ttyACM1', 115200)
def writeMult(val):
    for i in range(5):
        arduinoSerial.write(val)

while True:
    fireFan = input("enter fan number: ")
    if fireFan == "1":
        arduinoSerial.write(b"1")
    elif fireFan == "2":
        arduinoSerial.write(b"2")
    elif fireFan == "3":
        arduinoSerial.write(b"3")
    elif fireFan == "4":
        arduinoSerial.write(b"4")