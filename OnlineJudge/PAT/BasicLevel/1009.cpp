#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    stack<string> words;
    string input;
    getline(cin, input, '\n');

    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        words.push(input.substr(0, pos));
        // Push the word onto the stack

        input.erase(0, pos + 1);
        // Delete the word and space before the next word
    }
    words.push(input);

    while (!words.empty()) {
        cout << words.top() << ' ';
        // Output the top word on the stack

        words.pop();
        // Delete the word on the top
    }
    return 0;
}