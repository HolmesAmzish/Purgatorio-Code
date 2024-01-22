#include <iostream>
#include <string>

using namespace std;

int main() {
    string number;
    cin >> number;
    int sum = 0;
    for(int i = 0; number[i] != '\0'; i++) {
        sum += number[i] - '0';
        // Convert character to its integer equivalent using ASCII offset.
    }
    cout << "Sum : " << sum << endl;
    
    string read[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int index[32];
    int i;
    for(i = 0; sum > 0; i++) {
        index[i] = sum % 10;
        sum /= 10;
    }
    cout << "Read by : ";
    for(i = i - 1; i >= 0; i--) {
        cout << read[index[i]] << ' ';
    }

    cin.get();
    return 0;
}