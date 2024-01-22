// Problem name:    Helpful Maths
// Problem tags:    greedy, implementation, sortings, string
// Solve date:      2024.1.12
// Author:          Nulla

#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string expression; cin >> expression;

    int digit[3] = {0};
    // Initialize the array for the addition behind
    for (int i = 0; i < expression.length(); i += 2) {
        if (expression[i] == '1') digit[0]++;
        else if (expression[i] == '2') digit[1]++;
        else digit[2]++;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < digit[i]; j++) {
            cout << i + 1;
            // Output the number instead of index of array
            if (!(i == 2 && j== digit[i] - 1)) cout << '+';
        }
    }
    cout << endl;

    return 0;
}