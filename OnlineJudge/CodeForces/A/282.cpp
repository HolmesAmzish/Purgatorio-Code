// Problem name:    Bit++
// Problem tags:    implementation
// Author:          NULLA
// Solve date:      2024.1.8

#include <iostream>

using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        if (input == "++X" || input == "X++") {
            x++;
        } else if (input == "--X" || input == "X--"){
            x--;
        }
    }
    cout << x << endl;
    return 0;
}