// File:    20240323_2.cpp
// Date:    2024.03.23
// Author:  Nulla

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
    private:
    int array[MAX_SIZE];
    int front;
    int rear;

    public:
    Queue() : front(0), rear(0) {}

    bool isNull() {
        return front == rear;
    }

    bool isFull() {
        return !(MAX_SIZE - 1 - front);
    }

    void enQueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
        } else {
            array[rear++] = value;
        }
    }

    void deQueue() {
        if (isNull()) {
            cout << "Queue is empty!" << endl;
        } else {
            front++;
        }
    }

    int getFront() {
        if (isNull()) {
            cout << "Queue is empty!" << endl;
            return -1;
        } else {
            return array[front];
        }
    }
};

int main(void) {
    Queue PascalTriangle;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int value = 1;
            if (j > 0 && j < i) {
                PascalTriangle.enQueue(PascalTriangle.getFront() * (i - j) / j);
                PascalTriangle.deQueue();
            }
            cout << value << (j < i ? ' ' : '\n');
        }
    }
    return 0;
}