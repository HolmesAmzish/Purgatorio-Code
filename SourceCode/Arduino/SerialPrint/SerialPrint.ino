void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, World!");
}

int sec = 2100000;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(sec);
  Serial.println(" seconds past!");
  delay(1);
  sec++;
}
