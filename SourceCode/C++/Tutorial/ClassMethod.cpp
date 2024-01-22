#include<iostream>
using namespace std;

class myClass {
    public:
        void myMethod();
};

class car {
    public:
     int speed(int maxSpeed) {
        return maxSpeed;
     }
};

void myClass::myMethod() {
    cout << "My Method" << endl;
}

int main() {
    myClass object1;
    object1.myMethod();
    car object2;
    cout << object2.speed(200) << endl;
    return 0;
}