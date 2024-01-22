// Problem name:    Word Capitalization
// Problem tags:    implementation, strings
// Solve time:      2024.1.13
// Author:          Nulla

#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string input; cin >> input;
    if (islower(input[0])) {
        input[0] = toupper(input[0]);
    }
    cout << input;
    return 0;
}