#define BEEP_PIN 10

#define C 30
#define D 60
#define E 120
#define F 160
#define G 200
#define A 240
#define B 666

int music[] = {C, D, E, F, G, A, B};

void setup() {
  pinMode(BEEP_PIN, OUTPUT);
}
  int i = 0;
void loop() {
  if (i < 7) {
    analogWrite(BEEP_PIN, music[i]);
    delay(1000);
    i++;
  } else {
    i = 0;
  }
}