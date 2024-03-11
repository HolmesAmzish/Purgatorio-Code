#define LED 13
#define BUTTON 12

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

bool value = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTON) == HIGH) {
    value = !value;
  }

  if (value) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
