//Problem name: Next round
//Problem tags: special problem, implementation
//Solve date:   2024.1.8

#include <iostream>

using namespace std;

int main() {
    int participants, line;
    cin >> participants >> line;
    int participantsToNext = participants;
    int score;
    while (participants--) {
        cin >> score;
        if (score <= line) {
            participantsToNext--;
        }
    }
    cout << participantsToNext << endl;
    return 0;
}