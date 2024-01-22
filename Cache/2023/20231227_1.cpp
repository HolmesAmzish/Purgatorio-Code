#include <iostream>

using namespace std;

int main() {
    string input; cin >> input;
    int position = 0, count[3] = {0};
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++) {
        if (input[i] == 'A') count[position]++;
        else if (input[i] == 'P' && position == 0) position = 1;
        else if (input[i] == 'T' && position == 1) position = 2;
        else break;
    }
    if (position == 2 && count[1] && count[2] == count[0] * count[1]) cout << "YES\n";
    else cout << "NO\n";
    cin.get();
    return 0;
}