#include <iostream>

using namespace std;

int main(void) {
    int shipLocation[4][4] = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    int numberOfTurn, hits, row, column;
    numberOfTurn = 0;
    hits = 4;

    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << shipLocation[i][j] << " ";
        }
        cout << endl;
    }

    while (hits) {
        cout << "Selecting coordinates:" << endl;
        cout << "Choose a row number between 0 and 3:";
        cin >> row;
        cout << "Choose a column number between 0 and 3:";
        cin >> column;
        if (shipLocation[row][column]) {
            shipLocation[row][column] = 0;
            hits--;
            cout << "Hits! " << (hits) << " left." << endl << endl;
        } else {
        cout << "Miss!" << endl << endl;
        }
        numberOfTurn++;
    }
    cout << "Victory!" << endl << "You won in " << numberOfTurn << " hits" << endl;
    return 0;
}