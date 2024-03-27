#include <iostream>
#include <vector>
using namespace std;

// 生成杨辉三角形的函数
vector<vector<int>> generatePascalTriangle(int numRows) {
    if (numRows <= 0) {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pascalTriangle = generatePascalTriangle(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pascalTriangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
