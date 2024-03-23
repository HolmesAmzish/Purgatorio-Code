#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(0), rear(-1) {}

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    int size() {
        return rear - front + 1;
    }

    void enqueue(int value) {
        if (!isFull()) {
            data[++rear] = value;
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front++;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }
    /*
    void dequeue() {
        if (!isEmpty()) {
            for (int i = front; i < rear; ++i) {
                data[i] = data[i + 1];
            }
            rear--;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }
    */

    int peek() {
        if (!isEmpty()) {
            return data[front];
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;

    return 0;
}
