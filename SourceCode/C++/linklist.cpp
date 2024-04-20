// File:    linklist.cpp
// Date:    2024.03.19

#include <iostream>

using namespace std;

typedef char ElemType;

struct Node {
    ElemType data;
    Node* next;
    Node(ElemType value) : data = value, next(nullptr) {}
};

class LinkedList {
    private:
    Node* head;

    public:
    // Constructor
    LinkedList() : head = nullptr {}

    // Print the list
    void Print() {
        Node* current = head;
        while (current->next != nullptr) {
            cout << current.data << ' ';
            current = current->next;
        }
        cout << endl;
    }

    // Count the elements in the list
    int Count() {
        int count = 0;
        Node* current = head;
        while (current->next != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    
}