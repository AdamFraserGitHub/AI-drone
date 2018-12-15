#define motorPin0 9
#define motorPin1 12
#define motorPin2 11
#define motorPin3 10

bool fan1Active = false;
bool fan2Active = false;
bool fan3Active = false;
bool fan4Active = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin0, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  fan2();
//  fan4();
//  fan1();
//  delay(10);
//  fan1();
//  fan2();
//  delay(10);
//  fan2();
//  fan3();
//  delay(10);
//  fan3();
//  fan4();
//  delay(10);
  

}

void fan1() {
  if(fan3Active) {
    digitalWrite(motorPin2, LOW);
    fan3Active = false;
  } else {
    digitalWrite(motorPin2, HIGH);
    fan3Active = true;
  }
}
void fan2() {
  if(fan1Active) {
    digitalWrite(motorPin0, LOW);
    fan1Active = false;
  } else {
    digitalWrite(motorPin0, HIGH);
    fan1Active = true;
  }
}
void fan3() {
  if(fan2Active) {
    digitalWrite(motorPin1, LOW);
    fan2Active = false;
  } else {
    digitalWrite(motorPin1, HIGH);
    fan2Active = true;
  }
}
void fan4() {
  if(fan4Active) {
    digitalWrite(motorPin3, LOW);
    fan4Active = false;
  } else {
    digitalWrite(motorPin3, HIGH);
    fan4Active = true;
  } 
}
