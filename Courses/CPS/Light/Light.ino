#define LED 13
#define LIGHT_SENSOR A1
#define SOUND_SENSOR A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(LIGHT_SENSOR, INPUT);
  pinMode(SOUND_SENSOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(LIGHT_SENSOR) <= 50) {
    if(analogRead(SOUND_SENSOR) >= 250) {
      digitalWrite(LED, HIGH);
      delay(3000);
      digitalWrite(LED, LOW);
    }
  }
}
