const int INFRARED_PIN = 2;
const int LED_PIN = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(INFRARED_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(INFRARED_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
