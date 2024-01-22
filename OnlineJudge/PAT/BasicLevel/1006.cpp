#include <iostream>

using namespace std;

int main() {
    int input;
    cin >> input;
    int digit[3];
    for (int i = 0; i < 3; i++) {
        digit[i] = input % 10;
        input /= 10;
    }
    for (int i = 0; i < digit[2]; i++) {
        cout << 'B';
    }
    for (int i = 0; i < digit[1]; i++) {
        cout << 'S';
    }
    for (int i = 1; i <= digit[0]; i++) {
        cout << i;
    }
    return 0;
}