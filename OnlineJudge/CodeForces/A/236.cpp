#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string username; cin >> username;

    bool distinctCharacters[26] = {false};
    // Initialize the marks of characters seen

    for (char character : username) {
        // Assign every character in the string to the variable 'character'
        distinctCharacters[character - 'a'] = true;
    }

    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (distinctCharacters[i]) {
            count++;
        }
    }

    if (count % 2) {
        cout << "IGNORE HIM!" << endl;
    } else {
        cout << "CHAT WITH HER!" << endl;
    }
    return 0;
}