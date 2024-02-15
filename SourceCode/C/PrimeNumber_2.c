#include <stdio.h>
#define maxNumber 25

int main() {
    int isPrime[maxNumber];
    int x;
    for (int i = 0; i < maxNumber; i++) {
        isPrime[i] = 1;
    }
    for (x = 2; x < maxNumber; x++) {
        if (isPrime[x]) {
            for ( int i = 2; i * x < maxNumber; i++) {
                isPrime[i * x] = 0;
            }
        }
    }
    for (int i = 2; i < maxNumber; i++) {
        if (isPrime[i]) {
            printf("%d\t", i);
        }
    }
    printf("\n");
    return 0;
}