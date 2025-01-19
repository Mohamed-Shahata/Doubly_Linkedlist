#ifndef  Doubly_Linkedlist
#define Doubly_Linkedlist

#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedlist {
private:
	struct Node {
		T data;
		Node* prev, * next;

	};
	Node* first, * last;
	int length;

public:
	DoublyLinkedlist();

	~DoublyLinkedlist();

	bool isListEmpty();

	void insertAtFront(T value);

	void insertAtEnd(T value);

	int getSize();

	void insertAtPosition(int pos, T value);

	void removeFromFront();

	void removeFromEnd();

	void removeAtPosition(int pos);

	T getFront();

	T getBack();

	void clearList();

	void reverseList();

	bool contains(T value);

	int indexOf(T value);

	void updateAtPosition(int position, T newValue);

	void printForward();

	void printBackward();

};

// Constructor: Initializes an empty doubly linked list.
template <class T>
DoublyLinkedlist<T>::DoublyLinkedlist() : first(nullptr), last(nullptr), length(0) {};

// Destructor: Cleans up all nodes in the list.
template <class T>
DoublyLinkedlist<T>::~DoublyLinkedlist() {
	clearList();
}

// isListEmpty: Checks if the list is empty.
template <class T>
bool DoublyLinkedlist<T>::isListEmpty() {
	return length == 0;
}

// insertAtFront: Inserts a new element at the front of the list.
template <class T>
void DoublyLinkedlist<T>::insertAtFront(T value) {
	Node* newNode = new Node;
	newNode->data = value;
	if (isListEmpty()) {
		first = newNode;
		last = newNode;
		newNode->prev = nullptr;
		newNode->next = nullptr;
		length++;
	}
	else {
		first->prev = newNode;
		newNode->next = first;
		newNode->prev = nullptr;
		first = newNode;
		length++;
	}
}

// insertAtEnd: Inserts a new element at the end of the list.
template <class T>
void DoublyLinkedlist<T>::insertAtEnd(T value) {
	Node* newNode = new Node;
	newNode->data = value;
	if (isListEmpty()) {
		first = newNode;
		last = newNode;
		newNode->prev = nullptr;
		newNode->next = nullptr;
		length++;
	}

	else {
		last->next = newNode;
		newNode->prev = last;
		newNode->next = nullptr;
		last = newNode;
		length++;
	}
}

// getSize: Returns the current size of the list.
template <class T>
int DoublyLinkedlist<T>::getSize() {
	return length;
}

// insertAtPosition: Inserts a new element at a specific position in the list.
template <class T>
void DoublyLinkedlist<T>::insertAtPosition(int pos, T value) {
	Node* newNode = new Node;
	newNode->data = value;
	if (pos < 0 || pos > length) {
		throw out_of_range("Position out of range.");
	}
	else {

		if (pos == 0) {
			insertAtFront(value);
		}
		else if (pos == length) {
			insertAtEnd(value);
		}
		else {
			Node* current = first;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			Node* temp = current->prev;
			newNode->prev = temp;
			temp->next = newNode;
			newNode->next = current;
			current->prev = newNode;
			length++;
		}

	}
}

// removeFromFront: Removes the element at the front of the list.
template <class T>
void DoublyLinkedlist<T>::removeFromFront() {
	if (isListEmpty()) {
		throw runtime_error("The list is empty.");
	}
	else {
		if (first == last) {
			delete first;
			first = last = nullptr;
		}
		else {
			Node* current = first;
			first = current->next;
			first->prev = nullptr;
			delete current;
			length--;
		}

	}
}

// removeFromEnd: Removes the element at the end of the list.
template <class T>
void DoublyLinkedlist<T>::removeFromEnd() {
	if (isListEmpty()) {
		throw runtime_error("The list is empty.");
	}
	else {
		if (first == last) {
			delete first;
			first = last = nullptr;
		}
		else {
			Node* current = last;
			last = current->prev;
			last->next = nullptr;
			delete current;
			length--;
		}

	}
}

// removeAtPosition: Removes the element at a specific position in the list.
template <class T>
void DoublyLinkedlist<T>::removeAtPosition(int pos) {
	if (pos < 0 || pos > length - 1) {
		throw out_of_range("Position out of range.");
	}
	else {

		if (pos == 0) {
			removeFromFront();
		}
		else if (pos == length - 1) {
			removeFromEnd();
		}
		else {
			Node* current = first;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			Node* prevNode = current->prev;
			prevNode->next = current->next;
			current->next->prev = prevNode;
			delete current;
			length--;
		}

	}
}

// getFront: Returns the element at the front of the list.
template <class T>
T DoublyLinkedlist<T>::getFront() {
	if (isListEmpty()) {
		throw runtime_error("Cannot get element from an empty list.");
	}
	else {
		return first->data;
	}
}

// getBack: Returns the element at the end of the list.
template <class T>
T DoublyLinkedlist<T>::getBack() {
	if (isListEmpty()) {
		throw runtime_error("Cannot get element from an empty list.");
	}
	else {
		return last->data;
	}
}

// clearList: Clears all the elements in the list.
template <class T>
void DoublyLinkedlist<T>::clearList() {
	if (isListEmpty()) {
		return;
	}
	else {
		Node* current;
		while (first != nullptr) {
			current = first;
			first = current->next;
			delete current;
		}
		length = 0;
	}
}

// reverseList: Reverses the order of the elements in the list.
template <class T>
void DoublyLinkedlist<T>::reverseList() {
	if (isListEmpty()) {
		throw runtime_error("Cannot reverse an empty list.");
	}
	else {
		Node* current = first;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;
		}
		temp = first;
		first = last;
		last = temp;
	}
}

// contains: Checks if a specific value is present in the list.
template <class T>
bool DoublyLinkedlist<T>::contains(T value) {
	if (isListEmpty()) {
		throw runtime_error("The list is empty.");
	}
	else {
		Node* current = first;
		while (current != nullptr) {
			if (current->data == value) {
				return true;
			}
			current = current->next;
		}
	}
	return false;
}

// indexOf: Returns the index of a specific value in the list, or -1 if not found.
template <class T>
int DoublyLinkedlist<T>::indexOf(T value) {
	if (isListEmpty()) {
		throw runtime_error("The list is empty.");
	}
	else {
		int count = 0;
		Node* current = first;
		while (current != nullptr) {
			if (current->data == value) {
				return count;
			}
			count++;
			current = current->next;
		}
		return -1;
	}
}

// updateAtPosition: Updates the value of an element at a specific position in the list.
template <class T>
void DoublyLinkedlist<T>::updateAtPosition(int position, T newValue) {
	if (isListEmpty()) {
		throw runtime_error("The list is empty.");
	}
	else {
		if (position < 0 || position >= length) {
			throw out_of_range("Position out of range.");
		}
		else {
			Node* current = first;
			for (int i = 0; i < position; i++) {
				current = current->next;
			}
			current->data = newValue;
		}
	}
}

// printForward: Prints all the elements of the list from the front to the end.
template <class T>
void DoublyLinkedlist<T>::printForward() {
	if (isListEmpty()) {
		throw runtime_error("The list is empty.");
	}
	else {
		Node* current = first;
		cout << "[ ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << "]" << endl;
	}
}

// printBackward: Prints all the elements of the list from the end to the front.
template <class T>
void DoublyLinkedlist<T>::printBackward() {
	if (isListEmpty()) {
		throw runtime_error("The list is empty.");
	}
	else {
		Node* current = last;
		cout << "[ ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << "]" << endl;
	}
}

#endif