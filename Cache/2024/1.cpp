#include <iostream>
#include <vector>

using namespace std;

// Function to read matrix elements
void readMatrix(vector<vector<int>>& matrix, int n) {
    matrix.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }
}

// Function to print 1D array as matrix
void printArrayAsMatrix(const vector<int>& array, int n) {
    for (int i = 0; i < n * n; ++i) {
        cout << array[i] << ' ';
        if ((i + 1) % n == 0)
            cout << endl;
    }
}

// Function to convert matrix to snake format and store in 1D array
void matrixToSnake(const vector<vector<int>>& matrix, vector<int>& array, int n) {
    array.resize(n * n);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                array[index++] = matrix[i][j];
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                array[index++] = matrix[i][j];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix;
    readMatrix(matrix, n);

    printMatrix(matrix);

    vector<int> snakeArray;
    matrixToSnake(matrix, snakeArray, n);

    printArrayAsMatrix(snakeArray, n);

    return 0;
}
