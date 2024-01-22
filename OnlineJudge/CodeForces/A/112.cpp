// Problem name:    Petya and Strings
// Problem tags:    implementation, string
// Solve time:      2024.1.11
// Author:          Nulla

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(void) {
    string str[2];
    cin >> str[0] >> str[1];
    int len = str[0].length();
    //cout << len;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < len; j++) {
            if (isupper(str[i][j])) {
                str[i][j] = tolower(str[i][j]);
            }
        }
    }

    //cout << str[1];

    int result;
    if (str[0] > str[1]) {
        result = 1;
    } else if (str[0] < str[1]) {
        result = -1;
    } else {
        result = 0;
    }
    cout << result << endl;
    return 0;
}