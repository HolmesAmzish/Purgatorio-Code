// Problem name:    Next round
// Problem tags:    special problem, implementation
// Solve date:      2024.1.8
// Author:          NULLA

#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int scores[50];
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    int advancers = 0;

    // Count the number of participants with scores greater than k-th place
    for (int i = 0; i < n; i++) {
        if (scores[i] > 0 && scores[i] >= scores[k - 1]) {
            advancers++;
        } else {
            break;
        }
    }
    cout << advancers << endl;
    return 0;
}