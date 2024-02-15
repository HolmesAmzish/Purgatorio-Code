// File name:   p4_1.cpp
// Description: The usage of extern

#include <iostream>
#include "p4_2.cpp"
#include "p4_3.cpp"
using namespace std;
extern void p1dipG();
extern void p2dipG();
extern void p2dipg();

int G = 0, g = 0;
int main() {
    p1dipG();
    p2dipG();
    p2dipg();
    cout << "in p G = " << G << endl;
    cout << "in p g = " << g << endl;
    return 0; 
}