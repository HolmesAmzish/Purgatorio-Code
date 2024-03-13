// Date: 2024.03.13
// Author: Nulla

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

    public:
    LinkedList(void) {
        head = nullptr;
    }

    void Insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void Print(void) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }

    int CountByElement(int element) {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == element) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    Node* Locate(int index) {
        if (index <= 0) {
            return nullptr;
        }

        Node* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }
};

int main() {
    int input;
    LinkedList list;
    while (cin >> input, input != -1) {
        list.Insert(input);
    }
    list.Print();
    int location, element;
    cin >> location >> element;
    cout << "The location(" << location << ") is: " << list.Locate(location) << '\n'
    << "The number of element(" << element << ") is: " << list.CountByElement(element) << endl;
    return 0;
}