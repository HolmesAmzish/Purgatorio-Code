//Problem Name: Way Too Long Words
//probelm Tags: strings
//Solve Date:   2024.1.7

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string words;
    while (n--) {
        cin >> words;
        if (words.length() > 10) {
            cout << words[0] << words.length() - 2 << words[words.length() - 1] << endl;
        } else {
            cout << words << endl;
        }
    }
    return 0;
}