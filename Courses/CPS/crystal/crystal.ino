//DFRobot.com
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

uint8_t bell[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
uint8_t note[8]  = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};
uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
uint8_t duck[8]  = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
uint8_t check[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
uint8_t cross[8] = {0x0,0x1b,0xe,0x4,0xe,0x1b,0x0};
uint8_t retarrow[8] = { 0x1,0x1,0x5,0x9,0x1f,0x8,0x4};

LiquidCrystal_I2C lcd(0x20, 20, 4); // 20个字符宽，4行高的LCD（所有跳线都应连接！）

int scrollPos = 0;

void setup()
{
//  Serial.begin(57600);
  lcd.init();                      // initialize the lcd
  lcd.backlight();

  lcd.createChar(0, bell);
  lcd.createChar(1, note);
  lcd.createChar(2, clock);
  lcd.createChar(3, heart);
  lcd.createChar(4, duck);
  lcd.createChar(5, check);
  lcd.createChar(6, cross);
  lcd.createChar(7, retarrow);
  lcd.home();

  lcd.setCursor(0, 0);
  for(int i = 0;i < 20; i++)  lcd.printByte(6);
  lcd.setCursor(0, 1);
  lcd.printByte(6);
  lcd.print("   Hello world    ");
  lcd.printByte(6);
  lcd.setCursor(0, 2);
  lcd.printByte(6);
  lcd.print(" I ");
  lcd.printByte(3);
  lcd.print(" KOBE   ");
  lcd.printByte(6);
  lcd.setCursor(0, 3);
  for(int i = 0;i < 20; i++)  lcd.printByte(6);
//  lcd.clear();
  lcd.home();

  // 初始化滚动显示的位置

  
  // 在LCD上预加载初始内容
  lcd.setCursor(0, 1);
  lcd.print("   WDW is SB    ");
  
  // 可选地清空其他行
  lcd.setCursor(0, 0);
  lcd.printByte(6); // 或者使用lcd.clear()清屏
  lcd.setCursor(0, 2);
  lcd.printByte(6);
  lcd.setCursor(0, 3);
  lcd.printByte(6);

}

void loop() {
  if (scrollPos > 3) { // 当已经滚过3个字符位置时，回到起始位置
    scrollPos = 0;
  }

  lcd.setCursor(0, 1);
  lcd.print("   "); // 清除开始的三个空格
  lcd.print("MAN,What can I say?"); // 显示完整消息
  lcd.print("   "); // 添加额外的空格以模拟滚动效果
  lcd.scrollDisplayLeft(); // 向左滚动一行
  
  scrollPos++; // 增加滚动位置计数器
  
  delay(600); // 控制滚动速度，这里设置为每100毫秒滚动一次
}