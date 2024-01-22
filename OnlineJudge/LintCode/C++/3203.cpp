// File: 3203.cpp
// Author: Amzish
// Description: ......

#include <iostream>

using namespace std;

int main() {
    string input;
    int index;

    cin >> input >> index;
    cout << input[index - 1] << endl;
    
    cin.get();
    return 0;
}

/*
    TEST SAMPLE
    Input : abcdefghil 5
    Output : e
*/