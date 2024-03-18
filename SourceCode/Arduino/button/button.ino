#include <arduino.h>
#define LED 10
#define BUTTON 0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool isActive = false;
  if (digitalRead(BUTTON)) {
    isActive = !isActive;
  }

  if (isActive) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
