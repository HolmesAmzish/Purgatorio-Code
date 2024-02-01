// File name:   vector.cpp
// Date:        2024.1.31
// Author:      Nulla
// Description: Learning containers about vector

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<double> scoreVector;
    float max, input;

    cout << "Input -1 to stop" << endl;
    cout << "Enter the original score 1: ";
    cin >> max;
    scoreVector.push_back(max);
    for (int i = 1; true; i++) {
        cout << "Enter the original score " << i + 1 << ": ";
        cin >> input;
        if (input == -1)
            break;
        scoreVector.push_back(input);
        if (input > max)
            max = input;
    }
    max /= 100;
    cout << "The final scores are: " << endl;
    for (int i = 0; i < scoreVector.size(); i++) {
        scoreVector[i] /= max;
        cout << fixed << setprecision(2) << scoreVector[i] << "\t";
    }
    cout << endl;
    cin.get();
    return 0;
}