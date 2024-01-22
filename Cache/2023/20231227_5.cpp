#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<string> words;
    string fruits[3] = { "apple", "grape", "orange" };
    for (int i = 0; i < 3; i++) {
        words.push(fruits[i]);
    }
    for (int i = 0; i < 3; i++) {
        cout << words.top() << endl;
        words.pop();
    }
    return 0;
}