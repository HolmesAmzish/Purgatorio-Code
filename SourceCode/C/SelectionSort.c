#include <stdio.h>

int main() {
    int array[10] = {9, 3, 2, 5, 6, 1, 8, 3, 7, 6};
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}