#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void Insert(int data) {
        Node* newNode = new Node(data);
        if (head != nullptr) {
            Node* tempNode = head;
            while (tempNode->next != nullptr) {
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        } else {
            head = newNode;
        }
    }

    void Print() {
        Node* tempNode = head;
        while (tempNode != nullptr) {
            cout << tempNode->data << ' ';
            tempNode = tempNode->next;
        }
        cout << endl;
    }

    bool FindMid() {
        Node *slowPtr = head;
        Node *fastPtr = head;
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        cout << slowPtr->data << endl;

        return true;
    }

    bool FindFromEnd(int k) {
        Node* fastPtr = head;
        Node* slowPtr = head;

        for (int i = 0; i < k; i++) {
            if (fastPtr == nullptr) {
                cout << "error" << endl;
                return false;
            }
            fastPtr = fastPtr->next;
        }
        while (fastPtr != nullptr) {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        cout << slowPtr->data << endl;
        return true;
    }
};

int main() {
    LinkedList List;
    int input;
    while (cin >> input, input != -1) {
        List.Insert(input);
    }

    List.Print();
    List.FindMid();

    int k; cin >> k;
    List.FindFromEnd(k);

    return 0;
}