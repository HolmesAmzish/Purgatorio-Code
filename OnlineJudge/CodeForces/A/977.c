// Problem name:    Wrong Subtraction
// Problem tags:    implementation
// Solve time:      2024.1.17
// Author:          Nulla

#include <stdio.h>

int main() {
    int number, decrease;
    scanf("%d%d", &number, &decrease);
    for (int i = 0; i < decrease; i++) {
        if (number % 10) number--;
        else number /= 10;
    }
    printf("%d", number);
    return 0;
}