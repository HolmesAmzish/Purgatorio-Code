#include <iostream>
using namespace std;
extern int G;
extern int g;
void p2dipG() {
    G = 22;
    cout << "in p2 G = " << G << endl;
}
void p2dipg() {
    g = 33;
    cout << "in p2 g = " << g << endl;
}