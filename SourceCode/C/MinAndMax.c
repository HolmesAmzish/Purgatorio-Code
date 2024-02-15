#include <stdio.h>

void minAndMax(int *a, int len, int *min, int *max);

int main(void) {
    int a[] = {3, 5, 47, 8, 98, 54, 1, 95, 99, 98};
    int min, max;
    int len = sizeof(a) / sizeof(a[0]);
    // Calculate the length of array a[]

    printf("In the function main, sizeof(a) = %lu\n", sizeof(a));
    // Output is the size of array a[]
    
    minAndMax(a, len, &min, &max);
    printf("The min = %d\nThe max = %d\n", min, max);

    return 0;
}

void minAndMax(int *a, int len, int *min, int *max) {
    printf("");
    *min = a[0];
    *max = a[0];
    // Initialize the min and max

    printf("In the function minAndMax, sizeof(a) = %d\n", sizeof(a));
    // Output is the size of pointer

    for (int i = 1; i < len; i++) {
        if (a[i] < *min) {
            *min = a[i];
        }
        if (a[i] > *max) {
            *max = a[i];
        }
    }
}