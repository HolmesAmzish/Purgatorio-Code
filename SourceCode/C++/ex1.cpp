// File:    ex1.cpp
// Author:  Nulla
// Date:    2024.03.16
// Description: sequential list, array list

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
// Define the maximum capacity of the sequential list

class SeqList {
private:
    int data[MAX_SIZE];
    // Set an array to store data in the sequential list
    int length;

public:
    // Constructor
    SeqList() : length(0) {}

    // Insert an element
    bool Insert(int pos, int value) {
        if (pos < 0 || pos > length || length >= MAX_SIZE) {
            return false;
            // Invalid insetion position or the list is full
        }
        for (int i = length; i > pos; i--) {
            data[i] = data[i - 1];
            // Shift elements to make space for the new element
        }
        data[pos] = value; // Insert the new element
        length++; // Increment the length
        return true;
    }

    // Remove an element
    bool Remove(int pos) {
        if (pos < 0 || pos >= length) {
            return false; // Invalid removal position
        }
        for (int i = pos; i < length - 1; i++) {
            data[i] = data[i + 1]; // Shift elements to cover the deleted element
        }
        length--; // Decrement the length
        return true;
    }

    // Get an element
    int Get(int pos) {
        if (pos < 0 || pos >= length) {
            return -1; // Invalid position, return a special value -1
        }
        return data[pos];
    }

    // Display all elements
    void display() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    SeqList list;
    for (int i = 0; i < 10; i++) {
        list.Insert(i, i + 1); 
    }
    list.Remove(1);
    cout << "The array after deleting the element at position: 1" << endl;
    list.display();
    cout << "Element at position 1: " << list.Get(1) << endl;
    return 0;
}