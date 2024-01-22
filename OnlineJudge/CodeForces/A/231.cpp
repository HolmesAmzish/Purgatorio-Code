//Problem name: Team
//Solve date:   2013.7.3
//User: fuwutu

#include <iostream>

using namespace std;

int main() {
    int n, Petya, Vasya, Tonya, number(0);
    cin >> n;
    while (n--) {
        cin >> Petya >> Vasya >> Tonya;
        if (Petya + Vasya + Tonya >= 2) {
            number++;
        }
    }
    cout << number << endl;
    return 0;
}