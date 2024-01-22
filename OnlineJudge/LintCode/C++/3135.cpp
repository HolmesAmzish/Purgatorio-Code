#include <iostream>

using namespace std;

// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// Please define the function [add, sub, mul and divi] in the position between these two comments.
// write your code here
int add(int n1, int n2) {
    return n1 + n2;
}

int sub(int n1, int n2) {
    return n1 - n2;
}

int mul(int n1, int n2) {
    return n1 * n2;
}

int divi(int n1, int n2) {
    return n1 / n2;
}
// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

int main() {
    
    int n1, n2; char sign;
    cin >> n1 >> sign >> n2;
    switch (sign) {
        case '+': cout << add(n1, n2) << endl; break;
        case '-': cout << sub(n1, n2) << endl; break;
        case '*': cout << mul(n1, n2) << endl; break;
        case '/':
                  if (n2) cout << divi(n1, n2) << endl;
                  else cout << "Divide zero error!" << endl;
                  break;
        default: cout << "Unknown operation..." << endl;
    }

    return 0;
}