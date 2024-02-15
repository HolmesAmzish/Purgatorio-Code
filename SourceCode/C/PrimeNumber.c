#include <stdio.h>
#include <math.h>

int main() {
    int isPrime(int n);
    int n;
    printf("Input the number(0 < n): ");
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }
    return 0;
}

int isPrime(int n) {
    int ret = 1;
    if (n == 1 || (n % 2 == 0 && n != 2)) {
        ret = 0;
    } else {
        for (int i = 2; i < sqrt(n); i += 2) {
            if (n % i == 0) {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}