// Problem name:    Soldier and Bananas
// Problem tags:    brute force, implementation, math
// Solve time:      2024.1.16
// Author:          Nulla

#include <iostream>

using namespace std;

int main() {
    int price, money, number;
    cin >> price >> money >> number;
    int sum = 0;
    for (int i = 0; i < number; i++) {
        sum += price * (i + 1);
    }
    cout << max(0, sum - money);
    return 0;
}