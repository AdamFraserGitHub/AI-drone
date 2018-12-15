#define motorPin2 9

bool fan2Active = false;
int fan2Power = 0 * 20; //max fan cycle time is 10ms to avoid stuttering
                          //fan power is the number of ms out of those 10 that
                          //the fan is on. basically this is PWM

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin2, OUTPUT);

}

void loop() {
  fan2();
  delay(fan2Power);
  fan2();
  delay(20 - fan2Power);
  

}

void fan2() {
  if(fan2Active) {
    digitalWrite(motorPin2, LOW);
    fan2Active = false;
  } else {
    digitalWrite(motorPin2, HIGH);
    fan2Active = true;
  }
}
