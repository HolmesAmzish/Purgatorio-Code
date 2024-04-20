#include <Servo.h>

// 舵机控制相关常量
#define SERVO_PIN 9 // 舵机连接的引脚
#define SERVO_MIN_ANGLE 0 // 舵机的最小角度
#define SERVO_MAX_ANGLE 180 // 舵机的最大角度

// PID控制相关常量
#define KP 1.0 // 比例增益
#define KI 0.1 // 积分增益
#define KD 0.05 // 微分增益
#define SETPOINT 90 // 期望位置

// 定义舵机对象
Servo servo;

// PID控制变量
double input, output, setpoint;
double error, last_error;
double ITerm, last_input;

unsigned long last_time;
unsigned long sample_time = 10; // PID控制采样时间间隔

void setup() {
  // 设置舵机引脚为输出
  pinMode(SERVO_PIN, OUTPUT);

  // 初始化串口通信
  Serial.begin(9600);

  // 附加舵机对象到指定的引脚
  servo.attach(SERVO_PIN);

  // 初始化PID控制变量
  input = analogRead(A0); // 读取当前舵机位置
  setpoint = SETPOINT;
  last_input = input;
  last_error = 0;
  ITerm = 0;

  // 设置定时器
  last_time = millis();
}

void loop() {
  // 获取当前时间
  unsigned long now = millis();
  // 计算时间间隔
  unsigned long time_change = (now - last_time);
  // 如果时间间隔大于采样时间，执行PID计算
  if (time_change >= sample_time) {
    // 读取当前舵机位置
    input = analogRead(A0);
    // 计算误差
    error = setpoint - input;
    // 计算积分项
    ITerm += (KI * error);
    // 限制积分项的范围
    if (ITerm > 1023) ITerm = 1023;
    else if (ITerm < -1023) ITerm = -1023;
    // 计算微分项
    double dInput = (input - last_input);
    // 计算PID输出
    output = KP * error + ITerm - KD * dInput;
    // 限制输出范围
    if (output > 180) output = 180;
    else if (output < 0) output = 0;
    // 将PID输出转换为舵机角度
    servo.write(output);
    // 保存上一次的输入
    last_input = input;
    last_time = now;
  }
}

