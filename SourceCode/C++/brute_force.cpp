// File: brute_force.cpp
// Date: 2024.03.27
// Author: Nulla

#include <iostream>
#include <string>

using namespace std;

int bruteForce(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i; // Pattern found at index i
        }
    }
    return -1; // Pattern not found
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    int index = bruteForce(text, pattern);

    if (index != -1) {
        cout << "Pattern found at index : " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}