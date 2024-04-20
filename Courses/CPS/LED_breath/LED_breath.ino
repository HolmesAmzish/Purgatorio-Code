#define LED_PIN 9
#define SENSOR_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  int pwmValue = map(sensorValue, 0, 1024, 255, 0);
  analogWrite(LED_PIN, pwmValue);
}
