// Problem name:    Domino piling
// Problem tags:    greedy, math
// Solve date:      2024.1.8
// Author:          NULLA

#include <iostream>

using namespace std;

int main() {
    int domino(int m, int n);
    int m, n;
    cin >> m >> n;
    int result = domino(m, n);
    cout << result << endl;
    return 0;
}

int domino(int m, int n) {
    return (m * n) / 2;
}