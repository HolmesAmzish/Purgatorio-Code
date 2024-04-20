#define LED_PIN 5
#define BEEP 10

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BEEP, OUTPUT);
}

int timeDelay = 1000;

void loop() {
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BEEP, HIGH);
  delay(timeDelay);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BEEP, HIGH);
  delay(100);

  if (timeDelay != 100) {
    timeDelay -= 100;
  } else {
    timeDelay = 1000;
  }
}
