#include <iostream>
using namespace std;

const int MAX_SIZE = 12;

class UnionStack {
private:
    int data[MAX_SIZE];
    int top_odd, top_even;

public:
    UnionStack() : top_odd(-1), top_even(MAX_SIZE) {}

    bool isFull() {
        return top_even - 1 == top_odd;
    }

    bool isEmpty_odd() {
        return top_odd == -1;
    }

    bool isEmpty_even() {
        return top_even == MAX_SIZE;
    }

    void push_to(int num) {
        for (int i = 1; i < num; i += 2) {
            if (!isFull())
                data[++top_odd] = i;
            else {
                cout << "full" << endl;
                return;
            }
        }
        for (int i = 2; i < num; i += 2) {
            if (!isFull())
                data[--top_even] = i;
            else {
                cout << "full" << endl;
                return;
            }
        }
    }

    void pop() {
        if (!isEmpty_odd()) {
            cout << data[top_odd--] << endl;
        }

        if (!isEmpty_even()) {
            cout << data[top_even++] << endl;
        } else {
            cout << "error" << endl;
        }
    }

    void print() {
        cout << "stack1:";
        if (!isEmpty_odd()) {
            for (int i = top_odd; i >= 0; i--) {
                cout << data[i] << " ";
            }
        } else {
            cout << "empty";
        }
        cout << endl;

        cout << "stack2:";
        if (!isEmpty_even()) {
            for (int i = top_even; i < MAX_SIZE; i++) {
                cout << data[i] << " ";
            }
        } else {
            cout << "empty";
        }
        cout << endl;
    }
};

int main() {
    UnionStack stack;

    int num;
    cin >> num;

    cout << "stack1:empty\nstack2:empty\n";

    stack.push_to(num);

    stack.pop();
    stack.print();

    return 0;
}
