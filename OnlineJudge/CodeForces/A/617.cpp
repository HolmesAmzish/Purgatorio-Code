// Problem name:    Elephant
// Problem tags:    math
// Solve time:      2024.1.15
// Author:          Nulla

#include <iostream>

using namespace std;

int main() {
    int location; cin >> location;
    int steps = location / 5;
    if (location % 5) {
        steps++;
    }
    cout << steps << endl;
}