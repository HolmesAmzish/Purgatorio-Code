// Filename:    StringFunction.cpp
// File tag:    p3_5
// Date:        2023/12/29
// Description: Sorting and searching of string

#include <iostream>
#include <string>

using namespace std;

const int nameLen = 32;

void order(string nameList[], int listLen) {
    for (int i = 0; i < listLen - 1; i++) {
        for (int j = i + 1; j < listLen; j++) {
            if (nameList[i].compare(nameList[j]) > 0) {
                string temp;
                temp = nameList[i];
                nameList[i] = nameList[j];
                nameList[j] = temp;
            }
        }
    }
}
// Sort all the name in the list by alpha ordaer

int find(string nameList[], int listLen, string searchName) {
    int i = 0;
    for (i = 0; i < listLen; i++) {
        if (nameList[i].compare(searchName) == 0) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    string nameList[5] = {"Adolf Hitler",
                          "Holmes Amzish",
                          "Mizimi Lias",
                          "Inferno Nulla",
                          "Bizon Yorit"};
    order(nameList, 5);
    for (int i = 0; i < 5; i++) {
        cout << "ID: " << i + 1 << '\t' << nameList[i] << endl;
    }
    // Output all the sorted data

    string searchName;
    cout << "Input a name witch you want to search: ";
    getline(cin, searchName);
    // Get a line of string which contains a space

    int id = find(nameList, 5, searchName);
    if (id) cout << "The name could be found at ID " << id << endl;
    else cout << "The name could not be found" << endl;
    return 0;
}