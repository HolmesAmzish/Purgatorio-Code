//Problem name: Next round
//Problem tags: special problem, implementation
//Solve date:   2024.1.8
//User: NULLA

#include <iostream>

using namespace std;

int main() {
    int participants, line;
    cin >> participants >> line;
    int scores[100];
    for (int i = 0; i < participants; i++) {
        cin >> scores[i];
    }
    if (scores[0] > 0 && line > 1){
        while(scores[line - 1] == scores[line]) {
            line++;
        }
        cout << line << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}