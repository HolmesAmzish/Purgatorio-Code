#define SENSOR A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value =  analogRead(SENSOR);
  Serial.println(value);
  delay(500);
}