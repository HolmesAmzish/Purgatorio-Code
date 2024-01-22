#include<iostream>

using namespace std;

void swapNums(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int firstNum = 10;
    int secondNum = 20;

    cout << "Before swap: " << firstNum << ' ' << secondNum << endl;

    swapNums(firstNum, secondNum);

    cout << "After swap: " << firstNum << ' ' << secondNum << endl;

    return 0;
}