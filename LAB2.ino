#define DIP_PIN1 16
#define DIP_PIN2 17

#define LED1 5
#define LED2 18
#define LED3 19
#define LED4 21

#define MOTOR_IN1 22
#define MOTOR_IN2 23
#define MOTOR_EN  4

void setup() {
  
  pinMode(DIP_PIN1, INPUT_PULLUP);
  pinMode(DIP_PIN2, INPUT_PULLUP);

 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_EN, OUTPUT);
}

void loop() {
  int mode = readDIPSwitch();

  switch (mode) {
    case 0: //00
      runningLightLeftToRight();
      break;

    case 1: //01
      runningLightRightToLeft();
      break;

    case 2: //10
      rotateMotorClockwise();
      break;

    case 3: //11
      rotateMotorCounterClockwise();
      break;
  }
}

int readDIPSwitch() {
  int bit1 = digitalRead(DIP_PIN1);
  int bit2 = digitalRead(DIP_PIN2);
  return (bit1 << 1) | bit2;
}

void runningLightLeftToRight() {
  int leds[] = {LED1, LED2, LED3, LED4};
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
    delay(500);
    digitalWrite(leds[i], LOW);
  }
}

void runningLightRightToLeft() {
  int leds[] = {LED1, LED2, LED3, LED4};
  for (int i = 3; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(500);
    digitalWrite(leds[i], LOW);
  }
}

void rotateMotorClockwise() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_EN, 255);  
  delay(1000);  
  analogWrite(MOTOR_EN, 0);
}

void rotateMotorCounterClockwise() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  analogWrite(MOTOR_EN, 255);  
  delay(1000);  
  analogWrite(MOTOR_EN, 0); 
}
