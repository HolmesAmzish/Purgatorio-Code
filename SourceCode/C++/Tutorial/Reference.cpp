#include<iostream>

using namespace std;

int main() {

    string food = "pizza";
    string &meal = food;
    // Set meal a referrence of food.
    cout << food << endl;
    cout << meal << endl;

    return 0;
}