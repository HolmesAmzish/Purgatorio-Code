#define BEEP_PIN 10

#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494

int music[] = {C, D, E, F, G, A, B};

void setup() {
  pinMode(BEEP_PIN, OUTPUT);
}
  int i = 0;
void loop() {
  if (i < 7) {
    analogWrite(BEEP_PIN, music[i]);
    delay(10);
    i++;
  } else {
    i = 0;
  }
}