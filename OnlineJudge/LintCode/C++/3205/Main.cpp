#include <string>
#include <iostream>
using namespace std;

#include "Solution.cpp"

int main() {
    string s1, s2;
    cin >> s1;
    cin.ignore();
    cin >> s2;
    cout << compareString(s1, s2) << endl;
    return 0;
}