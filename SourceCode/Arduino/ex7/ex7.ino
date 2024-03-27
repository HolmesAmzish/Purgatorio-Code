#define LED_PIN 9
#define LIGHT_SENSOR A0
#define SOUND_SENSOR A1

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); // 初始化串口通信
}

void loop() {
  char receive;
  if (Serial.available()) {
    receive = Serial.read();
    if (receive == 's') { // 如果接收到字符 's'
      int value = analogRead(SOUND_SENSOR) * 255 / 1023;
      analogWrite(LED_PIN, value);
    } else if (receive == 'l') { // 如果接收到字符 'l'
      int value = 255 - analogRead(LIGHT_SENSOR) * 255 / 1023;
      analogWrite(LED_PIN, value);
    }
  }
}
