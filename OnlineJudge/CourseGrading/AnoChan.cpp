#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n; cin >> n;
    string input; cin >> input;
    size_t found = input.find("ano");
    if (found != string::npos) cout << "Yes";
    else cout << "No";
    return 0;
}