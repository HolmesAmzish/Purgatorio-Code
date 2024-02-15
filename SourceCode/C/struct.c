#include<stdio.h>

//Create a structure called myStructure
struct myStructure {
    int myNum;
    char myLetter;
};

int main(void) {
    //Create a structure variable of myStructure called s1
    struct myStructure s1;

    //Assign values to members of s1
    s1.myLetter = 'A';
    s1.myNum = 11;

    printf("My number: %d\n", s1.myNum);
    printf("My letter: %c\n", s1.myLetter);

    return 0;
}