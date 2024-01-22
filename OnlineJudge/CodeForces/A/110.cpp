// Problem name:    Nearly Luchky Number
// Problem tags:    implementation
// Solve date:      2024.1.19
// Author:          Nulla

#include <iostream>
#include <sstream>

using namespace std;

bool isLuckyNumber(int number) {
    for (; number;) {
        int digit = number % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        number /= 10;
    }
    return true;
}

bool nearLuckyNumber(int number) {
    int countLuckyNumber = 0;
    while (number) {
        int digit = number % 10;
        if (digit == 4 || digit == 7) {
            countLuckyNumber++;
        }
        number /= 10;
    }
    return isLuckyNumber(countLuckyNumber);
}

int main() {
    long int number; cin >> number;
    if (nearLuckyNumber(number)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}