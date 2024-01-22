// Problem name:    Bear and Big Brother
// Problem tags:    implementation
// Solve time:      2024.1.15
// Author:          Nulla

#include <iostream>

using namespace std;

int main() {
    int limak, bob;
    cin >> limak >> bob;
    int year;
    for (year = 0; limak <= bob; year++) {
        limak *= 3;
        bob *= 2;
    }
    cout << year << endl;
    return 0;
}