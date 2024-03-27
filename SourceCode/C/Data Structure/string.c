// File: string.cc
// Author: Nulla
// Date: 2024.03.27

#include <stdio.h>
#include <string.h>
#define kMaxSize 100

typedef struct {
    char data[kMaxSize];
    int length;
} SequenceString;

void StringAssign(SequenceString *string, char input_string[]) {
    (*string).length = strlen(input_string);
    for (int i = 0; i < (*string).length; i++) {
        (*string).data[i] = input_string[i];
    }
}

int StringCompare(SequenceString string_1, SequenceString string_2) {

}

SequenceString InsertString(SequenceString string_1, int position, SequenceString string_2) {
    SequenceString string;
    string.length = 0;
    if (position <= 0 || position > string_1.length + 1)
        return string;
    int i;
    for (i = 0; i < position - 1; i++)
        string.data[i] = string_1.data[i];
    for (i = 0; i < string_2.length; i++)
        string.data[position = i - 1] = string_2.data[i];
    for (i = position - 1; i < string_1.length; i++)
        string.data[string_2.length + i] = string_1.data[i];
    string.length = string_1.length + string_2.length;
    return string;
}

void PrintString(SequenceString string) {
    for (int i = 0; i < string.length; i++)
        printf("%c", string.data[i]);
    printf("\n");
}

int main() {
    char string_1[kMaxSize], string_2[kMaxSize];
    printf("Input the first string: ");
    scanf("%s", string_1);
    printf("Input the second string: ");
    scanf("%s", string_2);

    SequenceString sq_string_1, sq_string_2;
    StringAssign(&sq_string_1, string_1);
    StringAssign(&sq_string_2, string_2);
    PrintString(sq_string_1);
    
    return 0;
}