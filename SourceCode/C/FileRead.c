#include<stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("example.txt", "r");
    // Open a file in read mode
    
    char string[128];
    fgets(string, 128, fptr);
    printf("%s", string);

    fclose(fptr);
    return 0;
}