#include <stdio.h>

int main(void)
{
    FILE *fptr;
    // Create a file on your computer (example.txt)
    fptr = fopen("example.txt", "w");

    // If you want to create the file in a specific folder, just provide an absolute path:
    // fptr = fopen("C:\directoryname\filename.txt", "w")

    fprintf(fptr, "This is testing for fprintf\n");
    fputs("This is testing for fputs\n", fptr);

    // Close the file
    fclose(fptr);

    return 0;
}