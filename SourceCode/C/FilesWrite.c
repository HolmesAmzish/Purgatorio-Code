#include<stdio.h>

int main() {
    FILE *fptr;

    //Open a file in writing mode
    fptr = fopen("example.txt", "w");

    //Write some text to the file
    fprintf(fptr, "example text for testing");

    //Close
    fclose(fptr);

    return 0;
}