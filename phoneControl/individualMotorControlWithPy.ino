#define motorPin0 9
#define motorPin1 12
#define motorPin2 11
#define motorPin3 10

void setup() {
  pinMode(motorPin0, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);

  Serial.begin(115200); //115,200 refreshes per seccond
}

int incomingByte;

void loop() {
  if(Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.write(incomingByte);
    if(incomingByte == '1') {
      fan1();
    } else if(incomingByte == '2') {
      fan2();
    } else if(incomingByte == '3') {
      fan3();
    } else if(incomingByte == '4') {
      fan4();
    }
  }
}

void fan1() {
  digitalWrite(motorPin2, HIGH);
  delay(100);
  digitalWrite(motorPin2, LOW);  
}
void fan2() {
  digitalWrite(motorPin0, HIGH);
  delay(100);
  digitalWrite(motorPin0, LOW);  
}
void fan3() {
  digitalWrite(motorPin1, HIGH);
  delay(100);
  digitalWrite(motorPin1, LOW);  
}
void fan4() {
  digitalWrite(motorPin3, HIGH);
  delay(100);
  digitalWrite(motorPin3, LOW);  
}
