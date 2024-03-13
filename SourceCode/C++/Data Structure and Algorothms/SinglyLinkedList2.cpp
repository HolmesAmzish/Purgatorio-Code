#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail; // 新增尾指针
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr; // 初始化尾指针为空
    }

    void Insert(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            // 如果链表为空，将新节点设置为头尾节点
            head = newNode;
            tail = newNode;
        } else {
            // 否则，将新节点插入到尾节点之后，并更新尾指针
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr; // 在析构函数中清除尾指针
    }
};

int main() {
    LinkedList list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Print();
    return 0;
}
