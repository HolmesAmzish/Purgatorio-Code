#define LED 10

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for (int value = 0; value < 255; value++) {
    analogWrite(LED, value);
    delay(1);
  }
  for (int value = 255; value > 0; value--) {
    analogWrite(LED, value);
    delay(1);
  }
}