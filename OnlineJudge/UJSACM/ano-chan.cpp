/*
 * File: ano-chan.cpp
 * Problem: 47. Ano Chan?
 * Author: Nulla
 * Date: 2024.04.22
 */

#include <iostream>
using namespace std;

bool BruteForceSearch(const string& text, const string& pattern, int text_length) {
    for (int i = 0; i <= text_length - pattern.length(); i++) {
        int j;
        for (j = 0; j < pattern.length(); j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == pattern.length())
            return true;
    }
    return false;
}

int main() {
    const string key = "ano";
    int length;
    string text;
    cin >> length >> text;
    if (BruteForceSearch(text, key, length))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}