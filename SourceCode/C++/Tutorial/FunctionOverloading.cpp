#include <iostream>

using namespace std;

int plusFunction(int x, int y)
{
    return x + y;
}

float plusFunction(float x, float y)
{
    return x + y;
}

int main()
{
    int sum1 = plusFunction(8, 5);
    float sum2 = plusFunction(4.3f, 6.26f);

    cout << "Plus function int: " << sum1 << endl;
    cout << "Plus function float: " << sum2 << endl;

    return 0;
}