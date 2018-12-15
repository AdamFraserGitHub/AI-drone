#define motorPin0 13
#define motorPin1 12
#define motorPin2 11
#define motorPin3 10

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps

  pinMode(motorPin0, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
}

int incomingByte;
int focussedMotor;

void loop() {
//  Serial.write("huh\n");/
  //only do stuff when you recieve a signal
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    digitalWrite(motorPin2, HIGH);
    delay(100);
    digitalWrite(motorPin2, LOW);
  }
  delay(50);

}
