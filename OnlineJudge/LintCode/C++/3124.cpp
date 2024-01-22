#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        bool seven = false;
        // Initialize the bool value to false

        if (i % 7 == 0) seven = true;
        // Wether it can be divided by seven

        int temp = i;
        while (temp) {
            if (temp % 10 == 7) {
                seven = true; break;
            } else {
                temp /= 10;
            }
        }
        // Wether there is a digit is the number seven

        if (seven) {
            cout << "pass" << endl;
        } else {
            cout << i << endl;
        }
        // Print the result
    }

    cin.get();
    return 0;
}