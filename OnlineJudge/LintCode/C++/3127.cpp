#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n; cin >> n;

    int i = 0; // Initialize variable i
    while (pow(2, i) <= n) {
        i++;
    }
    cout << fixed << setprecision(0) << pow(2, i) <<endl;
    return 0;
}