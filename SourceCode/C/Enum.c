#include<stdio.h>

enum level {
    LOW = 1,
    MEDIUM,
    HIGH
};

int main() {
    enum level var = MEDIUM;
    // Create an enum variable and assign a value to it
    printf("%d", var);
    return 0;
}