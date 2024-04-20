#define LED 13
#define BUTTON 2
#define BEEP 3

#define TONE_DING 523
#define TONE_DONG 262

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BEEP, OUTPUT);
}

bool isActive = false;
bool isLight = false;

void loop() {
  if (digitalRead(BUTTON)) {
    isActive = !isActive;
    isLight = !isLight;
  }

  if (isActive) {
    tone(BEEP, TONE_DING, 100);
    delay(200);
    tone(BEEP, TONE_DONG, 100);
    isActive = !isActive;
  }

  if (isLight) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
