#include <Servo.h>
#define SERVO 9
#define KNOB A1

Servo servo;

int position = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
  int inputValue = analogRead(KNOB);
  int outputValue = inputValue * 30/1024;
  servo.write(outputValue);
}
