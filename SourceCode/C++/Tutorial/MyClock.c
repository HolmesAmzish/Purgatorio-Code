// File name:   MyClock.c
// Date:        2024.2.1
// Author:      NULLA

#include <stdio.h>

struct Clock {
    int hour, min, sec;
};

struct Clock MyClock;

void SetTime(int hour, int min, int sec) {
    MyClock.hour = hour;
    MyClock.min = min;
    MyClock.sec = sec;
}

void DisplayTime(void) {
    printf("%d:%d:%d", MyClock.hour, MyClock.min, MyClock.sec);
}

int main() {
    SetTime(8, 20, 30);
    DisplayTime();
    return 0;
}