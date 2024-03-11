#define LED 10
#define SENSOR A0

void setup() {
  // 初始化串行通信并设置波特率为9600bps
  Serial.begin(9600);

  // 设置LED引脚为输出模式
  pinMode(LED, OUTPUT);
}

void loop() {
  // 读取灰度传感器（连接在模拟引脚A0）的值
  int value =  255 - analogRead(SENSOR);

  // 将读取到的值以十进制格式打印到串口监视器
  Serial.println(value, DEC);

  // 限制输出至LED的亮度值范围，避免超过最大PWM值255
  if (value < 0) {
    value = 0;
  }

  // 使用analogWrite将值写入LED，控制其亮度
  analogWrite(LED, value);

  // 延迟100毫秒后再次循环读取和控制
  delay(100);
}