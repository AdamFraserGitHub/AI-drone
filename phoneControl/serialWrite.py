import serial

arduinoSerial = serial.Serial('/dev/ttyACM0', 115200)
# def writeMult(val):
#     for i in range(5):
#         arduinoSerial.write(val)

# while True:
#     fireFan = input("enter fan number: ")
#     if fireFan == "1":
#         arduinoSerial.write(b"1")
#     elif fireFan == "2":
#         arduinoSerial.write(b"2")
#     elif fireFan == "3":
#         arduinoSerial.write(b"3")
#     elif fireFan == "4":
#         arduinoSerial.write(b"4")

from flask import Flask, request
import json
    
app = Flask(__name__)
    
@app.route('/postdata', methods = ['POST'])
def postdata():
    # data = request.get_json()
    command2Send = request.get_json()['command']
    print(command2Send)
    arduinoSerial.write(command2Send.encode('utf-16be'))
    return "message recieved!"
    # do something with this data variable that contains the data from the node server
    
if __name__ == "__main__":
    app.run(port=5000)