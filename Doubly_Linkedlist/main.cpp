#include "Doubly_Linkedlist.h"
#include <iostream>
using namespace std;

int main() {
    // Create a DoublyLinkedList of integers
    DoublyLinkedlist<int> list;

    // Insert elements
    list.insertAtFront(10);
    list.insertAtEnd(20);
    list.insertAtPosition(1, 15);

    // Print the list
    cout << "List (Forward): ";
    list.printForward(); // Output: [ 10 15 20 ]

    cout << "List (Backward): ";
    list.printBackward(); // Output: [ 20 15 10 ]

    // Check size
    cout << "Size: " << list.getSize() << endl; // Output: 3

    // Check if list contains a value
    cout << "Contains 15: " << (list.contains(15) ? "Yes" : "No") << endl; // Output: Yes

    // Get index of a value
    cout << "Index of 15: " << list.indexOf(15) << endl; // Output: 1

    // Update value at a position
    list.updateAtPosition(1, 25);
    cout << "List after update: ";
    list.printForward(); // Output: [ 10 25 20 ]

    // Remove elements
    list.removeFromFront();
    list.removeAtPosition(1);
    list.removeFromEnd();

    // Check if list is empty
    cout << "Is list empty? " << (list.isListEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}