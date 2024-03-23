// File:    20240323.cpp
// Date:    2024.03.23
// Author:  Nulla

#include <iostream>
using namespace std;

const int MAX_SIZE = 12;

class UnionStack {
    private:
    int data[MAX_SIZE];
    int top_odd, top_even;

    public:
    UnionStack() : top_odd(-1), top_even(MAX_SIZE) {}

    bool isEmpty_odd() {
        if (top_odd == -1) return true;
        else return false;
    }

    bool isEmpty_even() {
        if (top_even == MAX_SIZE) return true;
        else return false;
    }

    void push_to(int num) {
        if (top_odd + 1 == top_even) {
            cout << "The stack is full!" << endl;
        } else {
            for (int i = 1; i < num; i += 2) {
                data[++top_odd] = i;
            }
            for (int i = 2; i < num; i += 2) {
                data[--top_even] = i;
            }
        }
    }

    void pop_odd() {
        if (!isEmpty_odd()) {
            cout << data[top_odd--] << endl;
        } else {
            cout << "Stack_odd underflow!" << endl;
        }
    }

    void pop_even() {
        if (!isEmpty_even()) {
            cout << data[top_even++] << endl;
        } else {
            cout << "Stack_even underflow!" << endl;
        }
    }

    void print() {
        if (!isEmpty_odd() && !isEmpty_even()) {
            int temp_1 = top_odd, temp_2 = top_even;

            // Print stack_odd
            cout << "stack1:";
            for (int i = top_odd; i > -1; i--) {
                cout << data[top_odd--] << ' ';
            }
            cout << endl;
            top_odd = temp_1;

            // Print stack_even
            cout << "stack2:";
            for (int i = top_even; i < MAX_SIZE; i++) {
                cout << data[top_even++] << ' ';
            }
            cout << endl;
            top_even = temp_2;
        }
    }
};

int main() {
    UnionStack stack;
    cout << "stack1: " << (stack.isEmpty_odd() ? "empty" : "not empty") << endl;
    cout << "stack2: " << (stack.isEmpty_even() ? "empty" : "not empty") << endl;
    int num; cin >> num;
    stack.push_to(num);
    //stack.print();
    stack.pop_odd();
    stack.pop_even();
    stack.print();
    return 0;
}