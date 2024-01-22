// Filename:    1008.cpp
// Date:        2024/1/1
// Description: Input an array and move it forward by certain steps

#include <iostream>

using namespace std;

int main() {
    int len,step;
    int array[256];
    cin >> len >> step;
    for (int i = 0; i < len; i++) {
        cin >> array[i];
    }

    void move(int array[], int len, int step);
    move(array, len, step);
    
    for (int i = 0; i < len; i++) {
        cout << array[i];
        if (i < len - 1) {
            cout << ' ';
        }
    }
    cout << endl;

    return 0;
}

void move(int array[], int len, int step) {
    for (int i = 0; i < step; i++) {
        for (int j = len - 1; j > 0; j--) {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
        }
    }
}

/*
TEST SAMPLE
Input:
6 2
1 2 3 4 5 6
*/