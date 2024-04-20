#define LED_PIN 9
#define SENSOR_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(SENSOR_PIN) * 255 / 1023;
  analogWrite(LED_PIN, value);
}