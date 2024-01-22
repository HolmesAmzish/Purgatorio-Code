#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    vector<int> numbers;
    
    // Extract numbers from the string and store them in a vector
    for (int i = 0; i < expression.length(); i += 2) {
        numbers.push_back(expression[i] - '0');
    }

    // Sort the numbers in non-decreasing order
    sort(numbers.begin(), numbers.end());

    // Output the rearranged sum
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        // Output '+' if it's not the last number
        if (i != numbers.size() - 1) {
            cout << '+';
        }
    }
    cout << endl;

    return 0;
}
