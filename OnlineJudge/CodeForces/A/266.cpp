// Problem name:    Stones on the Table
// Problem tags:    implementation
// Solve date:      2024.1.14
// Author:          Nulla

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string stones; cin >> stones;
    int count = 0;
    char previous = stones[0];
    for (int i = 1; i < stones.length(); i++) {
        char current = stones[i];
        if (previous == current) {
            count++;
        }
        previous = current;
    }
    cout << count << endl;
    return 0;
}