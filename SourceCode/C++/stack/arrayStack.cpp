// File:    stack.cpp
// Date:    2024.03.20
// Author:  Nulla

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
    private:
    int data[MAX_SIZE];
    int top;

    public:
    // Constructor
    Stack() : top (-1) {}

    // Check is the stack empty
    bool isEmpty() {
        return top == -1;
    }

    // Check is the stack full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    int size() {
        return top + 1;
    }

    // Push the stack
    void push(int value) {
        if (!isFull()) {
            top++;
            data[top] = value;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    // Pop the stack
    void pop() {
        if (!isEmpty()) {
            top--;
        } else {
            cout << "Stack underflow!" << endl;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return data[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
};

int main() {
    Stack stack;

    for (int i = 0; i < 3; i++) {
        stack.push(i + 1);
    }

    cout << "The top element: " << stack.peek() << endl;

    stack.pop();
    cout << "The top element after pop: " << stack.peek() << endl;

    for (int i = 0; i < 3; i++) {
        stack.pop();
    }

    return 0;
}