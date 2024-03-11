#define BEEP 10
#define LED 11
#define KNOB 0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int inputValue = analogRead(KNOB);
  int outputValue = inputValue * 40/1024;
  analogWrite(LED, outputValue);
}
