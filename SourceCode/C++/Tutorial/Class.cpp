#include<iostream>

using namespace std;

class myClass {
    public:
        int num;
        string str;
};

int main() {
    myClass obj;
    // Creat an object of myClass
    
    obj.num = 15;
    obj.str = "example";
    //Access attributes and set values

    cout << obj.num << endl;
    cout << obj.str;
    return 0;
}