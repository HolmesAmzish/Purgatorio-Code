// Problem Name:    Watermelon
// Problem Tags:    brute force, math
// Solve Date:      2024.1.7
// Author:          NULLA

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    if (n % 2 == 0 && n > 2) cout << "YES";
    else cout << "NO";
    return 0;
}