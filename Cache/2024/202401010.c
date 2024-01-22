#include <stdio.h>

int main() {
    int array[6] = {1, 2, 3, 4, 5, 6};
    int *ptr = array;
    *(ptr + 3) += 2;
    printf("%d", *(++ptr));
    return 0;
}