// File name:   MyClock.cpp
// Date:        2024.2.1
// Author:      NULLA

#include <iostream>

using namespace std;

class Clock {
private:
    int hour, min, sec;
public:
    Clock(int h = 0, int m = 0, int s = 0) {
        hour = h;
        min = m;
        sec = s;
    }
    void SetClock(int h = 0, int m = 0, int s = 0) {
        hour = h;
        min = m;
        sec = s;
    }
    void DisplayClock(void) {
        cout << hour << ":" << min << ":" << sec << endl;
    }
};

int main() {
    Clock MyClock;
    MyClock.DisplayClock();
    MyClock.SetClock(21, 8, 30);
    MyClock.DisplayClock();

    Clock Clock2(9, 38, 10);
    Clock2.DisplayClock();
    return 0;
}