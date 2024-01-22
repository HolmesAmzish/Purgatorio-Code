#include <iostream>

using namespace std;

class MyClass {
    public:
        int x;    
    private:
        int y;
    
    // By default, all members of a class are private
};

int main() {
    MyClass myObject;
    myObject.x = 25;
    // Allowed (public)
    myObject.y = 50;
    // Not allowed (private)

    return 0;
}