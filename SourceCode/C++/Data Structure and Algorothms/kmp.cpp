// File: kmp.cc
// Date: 2024.03.27
// Author: Nulla

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildNext(string pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        next[i] = j;
    }
    return next;
}

int kmp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> next = buildNext(pattern);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            return i - m + 1; //Pattern found at index i - m + 1
        }
    }
    return -1; //Pattern not found
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    int index = kmp(text, pattern);

    if (index != -1) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }
    return 0;
}