#include<stdio.h>

int main(void) {
    char fullName[30];
    printf("Type your full name and press enter: ");
    
    fgets(fullName, sizeof(fullName), stdin);
    //fgets is better than gets because it ensure the number of characters

    printf("Hello %s", fullName);
    return 0;
}