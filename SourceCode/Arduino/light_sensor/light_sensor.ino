#define SENSOR A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value =  analogRead(SENSOR);
  if (value >= 250) {
    Serial.println("Light intensity value is large!");
  } else if (value <= 50) {
    Serial.println("Light intensity value is small!");
  }
  delay(500);
}