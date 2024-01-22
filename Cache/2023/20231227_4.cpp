#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<string> words;
    string input;
    while (cin >> input) words.push(input);
    cout << words.top();
    words.pop();
    while (!words.empty()) {
        cout << " " << words.top();
        words.pop();
    }
    return 0;
}
