#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> sequence;
    int input;
    while (cin >> input, input != -1) {
        sequence.push_back(input);
    }
    int position, find, count = 0;
    cin >> position >> find;
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << ' ';
        if (sequence.at(i) == find) count++;
    }
    cout << endl;
    if (position > 0 && position <= sequence.size()) {
        cout << sequence.at(position - 1) << '\n';
    } else {
        cout << "error" << endl;
    }
    cout << count;
    return 0;
}