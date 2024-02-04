// File name:   MyClock.cpp
// Date:        2024.2.1
// Author:      NULLA

#include <iostream>

using namespace std;

class MyClock {
    private:
        int hour, min, sec;
    public:
        void SetClock(int h, int m, int s) {
            hour = h;
            min = m;
            sec = s;
        }
        void DisplayClock(void) {
            cout << hour << ":" << min << ":" << sec;
        }
};

int main() {
    MyClock MyClock;
    MyClock.SetClock(21, 8, 30);
    MyClock.DisplayClock();
    return 0;
}