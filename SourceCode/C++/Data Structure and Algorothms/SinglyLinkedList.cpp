// File: SinglyLinkedList.cpp
// Date: 2024.03.13
// Author:  Nulla

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
        // nullptr means a NULL pointer
    }
};

class LinkedList {
    private:
    Node* head;
    public:

    LinkedList() {
        head = nullptr;
    }

    void Insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
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