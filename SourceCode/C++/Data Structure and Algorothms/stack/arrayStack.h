#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

class Stack {
    private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int top;

    public:
    Stack();
    bool isEmpty();
    bool isFull();
    int size();
    void push(int value);
    void pop();
    int peek();
};

#endif