
#define BEEP_PIN 10

// 定义音符频率
#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494

// 简化的欢乐颂旋律（仅展示一小段）
// 音符-时长对列表，例如(C, 500)代表播放C音500毫秒
int melodyNotes[][2] = {
    {C, 1000}, {E, 1000}, {G, 1000}, {C, 1000}, {E, 1000}, {G, 1000},
    {A, 500}, {G, 500}, {F, 1000}, {E, 1000}, {D, 1000}, {C, 1000},
    // ... 这里继续添加完整的欢乐颂旋律
};

void setup() {
  pinMode(BEEP_PIN, OUTPUT);
}

void playNote(int pin, int frequency, int duration) {
  tone(pin, frequency);
  delay(duration);
  noTone(pin); // 结束音符播放
}

void loop() {
  for (int i = 0; i < sizeof(melodyNotes) / sizeof(melodyNotes[0]); i++) {
    playNote(BEEP_PIN, melodyNotes[i][0], melodyNotes[i][1]);
  }
  // 若要循环播放整个旋律，可在此处留空或增加延时后重置指针
}