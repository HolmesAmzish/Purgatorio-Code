#define LED 2
#define BEEP 3

int time[3] = {200, 800, 200};

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BEEP, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      digitalWrite(LED, HIGH);
      digitalWrite(BEEP, HIGH);
      delay(time[i]);
      digitalWrite(LED, LOW);
      digitalWrite(BEEP, LOW);
      delay(100);
    }
  }
  delay(1000);
}
