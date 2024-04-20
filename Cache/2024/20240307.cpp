#include <iostream>

using namespace std;

int main() {
    float ave = 0, max, min;
    float calave(float a[], int n) {
        max = min = a[0];
        for (int i = 0; i < n; i++) {
            ave += a[i];
            if (max < a[i]) max = a[i];
            if (min > a[i]) min = a[i];
        }
    return ave / n;
    }
}