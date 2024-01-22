#include <iostream>

using namespace std;

int main() {
    int digital[64][3], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> digital[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (digital[i][0] + digital[i][1] > digital[i][2]) cout << "Case #" << i + 1 << ": true\n";
        else cout << "Case #" << i + 1 << ": false\n";
    }

    return 0;
}

/*TEST SAMPLE
Input:
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
*/