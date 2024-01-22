// Problem name:    Beautiful matrix
// Problem tags:    implementation
// Solve date:      2024.1.10
// Author:          NULLA

#include <iostream>
#include <cmath>

using namespace std;

const int rows = 5, columns = 5;

int movesToMid(int matrix[][columns], int rows) {
    int rowCoordinate, columnCoordinate;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j]) {
                rowCoordinate = i;
                columnCoordinate = j;
                break;
            }
        }
    }
    // Find the location of 1
    
    int ret = abs(rowCoordinate - rows / 2) + abs(columnCoordinate - columns / 2);
    return ret;
}

int main(void) {
    int matrix[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << movesToMid(matrix, rows) << endl;
    return 0;
}