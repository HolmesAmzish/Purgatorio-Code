#include <iostream>
#include <cstring>

using namespace std;

int main() {
    bool isPAT(string input);
    const int maxNumber = 64;
    int n;
    string input[maxNumber];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        if (isPAT(input[i])) cout << "YES\n";
        else cout << "NO\n";
    }
    cin.get();
    return 0;
}

bool isPAT(string input) {
    int position = 0;
    int count[3] = {0};
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'A') count[position]++;
        else if (input[i] == 'P' && position == 0) position = 1;
        else if (input[i] == 'T' && position == 1) position = 2;
        else break;
    }
    if (position == 2 && count[1] && count[2] == count[1] * count[0]) return true;
    else return false;
}