// File:    stack.c
// Date:    2024.03.20
// Author:  Nulla

#include <stdio.h>
#define MAX_SIZE 100

typedef struct SequenceStack {
    int data[MAX_SIZE];
    int top;
} SqStack;

void Initial(SqStack *& s) {
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
}