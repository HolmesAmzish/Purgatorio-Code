#include<iostream>

using namespace std;

void bubbleSort(int *array, int size);
int main() {
    const int maxSize = 128;
    int array[maxSize];
    int size;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> *(array + i);
    }

    bubbleSort(array, size);

    for(int i = 0; i < size; i++) {
        cout << *(array + i) << " ";
    }

    getchar();
    return 0;
}

void bubbleSort(int *array, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(*(array + j) > *(array + j + 1)) {
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

/*TEST SAMPLE
Input:  9
        8 6 9 6 4 2 1 9 0
        5
        1 9 7 6 2
        20
        65 21 54 21 85 63 21 54 78 45 89 65 23 21 45 74 14 25 85 25
*/