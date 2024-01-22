#include <iostream>

using namespace std;

enum words {
    Sieg,
    Heil,
    Mine = 4,
    Futher
};

int main() {
    int n;
    cout << "Input a number(" << Sieg - 1 << " to exit):\n";
    cin >> n;
    while (n >= Sieg) {
        switch(n) {
            case Sieg: cout << "Sieg "; break;
            case Heil: cout << "Heil "; break;
            case Mine: cout << "Mine "; break;
            case Futher: cout << "Futher "; break;
            default: cout << "Invalid number\n";   
        }
        cin >> n;
    }
    return 0;
}