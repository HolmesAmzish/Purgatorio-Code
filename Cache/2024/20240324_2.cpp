#include <iostream>
using namespace std;

// 定义队列类
class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue() {
        while (!isEmpty())
            deQueue();
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enQueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return -1; // 返回一个特殊值表示错误
        }
        return front->data;
    }
};

int main() {
    Queue PascalTriangle;
    int n; 
    cin >> n;
    PascalTriangle.enQueue(1); // 添加第一个元素
    cout << "1\n"; // 三角形的顶部
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int num;
            int prevNum_1, prevNum_2;
            if (j == 0 || j == i) {
                num = 1;
            } else {
                if (PascalTriangle.isEmpty()) {
                    cout << "Error: Unexpected condition while computing Pascal's Triangle." << endl;
                    return -1; // 或者相应地处理错误
                }
                prevNum_2 = PascalTriangle.getFront();
                PascalTriangle.deQueue();
                if (PascalTriangle.isEmpty()) {
                    cout << "Error: Unexpected condition while computing Pascal's Triangle." << endl;
                    return -1; // 或者相应地处理错误
                }
                prevNum_1 = PascalTriangle.getFront();
                PascalTriangle.deQueue();
                num = prevNum_1 + prevNum_2;
            }
            PascalTriangle.enQueue(num);
            cout << num << ' ';
        }
        cout << endl;
    }
}
