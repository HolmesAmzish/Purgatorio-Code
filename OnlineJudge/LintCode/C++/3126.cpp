#include <iostream>

using namespace std;

int main() {
    int num, guess;
    cin >> num >> guess;
    if (guess == num) cout << "Congratulations, you guessed right!\n";
    else if (guess > num) cout << "Guess it's too big.\n";
    else cout << "Guess it's too small.\n";
    cin.get();
    return 0;
}