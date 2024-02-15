// File name:   destructor.cpp
// Date:        2024.2.13
// Author:      Nulla
// Description: Figure out the difference between constructor and destructor

#include <iostream>

class Clock {
    private:
    int H, M, S;
    public:
    Clock(int h = 0, int m = 0, int s = 0) {
        H = h, M = m, S = s;
        std::cout << "constructor: " << H << ':' << M << ':' << S << std::endl;
    }
    ~Clock() {
        std::cout << "destructor: " << H << ':' << M << ':' << S << std::endl;
    }
};

Clock C1(9, 30, 0);

int main() {
    Clock C2(10, 0, 0);
    return 0;
}