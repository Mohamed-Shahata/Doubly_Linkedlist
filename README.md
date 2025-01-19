# Doubly Linked List

This repository contains a comprehensive implementation of a **Doubly Linked List** in C++ as a templated class. Below is a detailed explanation of the class functionality and how it behaves in different scenarios.

---

## Features and Behaviors

### 1. **Constructor**
```cpp
DoublyLinkedlist();
```
- **Description:** Initializes an empty doubly linked list.
- **Behavior:**
  - Sets `first` and `last` pointers to `nullptr`.
  - Sets the `length` to 0.

---

### 2. **Destructor**
```cpp
~DoublyLinkedlist();
```
- **Description:** Cleans up all nodes in the list by deallocating memory.
- **Behavior:**
  - Calls `clearList()` to remove all nodes and reset the list to an empty state.

---

### 3. **Check if List is Empty**
```cpp
bool isListEmpty();
```
- **Description:** Checks if the list is empty.
- **Behavior:**
  - Returns `true` if `length == 0`.
  - Returns `false` otherwise.

---

### 4. **Insert at Front**
```cpp
void insertAtFront(T value);
```
- **Description:** Inserts a new element at the front of the list.
- **Behavior:**
  - If the list is empty:
    - Creates a new node and sets both `first` and `last` to point to it.
    - Sets `prev` and `next` pointers of the node to `nullptr`.
  - If the list is not empty:
    - Creates a new node.
    - Links it to the current `first` node.
    - Updates `first` to point to the new node.
  - Increments the `length` by 1.

---

### 5. **Insert at End**
```cpp
void insertAtEnd(T value);
```
- **Description:** Inserts a new element at the end of the list.
- **Behavior:**
  - If the list is empty:
    - Behaves like `insertAtFront()`.
  - If the list is not empty:
    - Creates a new node.
    - Links it to the current `last` node.
    - Updates `last` to point to the new node.
  - Increments the `length` by 1.

---

### 6. **Get List Size**
```cpp
int getSize();
```
- **Description:** Returns the current size of the list.
- **Behavior:**
  - Simply returns the value of `length`.

---

### 7. **Insert at a Specific Position**
```cpp
void insertAtPosition(int pos, T value);
```
- **Description:** Inserts a new element at a specific position in the list.
- **Behavior:**
  - If `pos < 0` or `pos > length`:
    - Throws an `out_of_range` exception.
  - If `pos == 0`:
    - Calls `insertAtFront()`.
  - If `pos == length`:
    - Calls `insertAtEnd()`.
  - Otherwise:
    - Traverses the list to the specified position.
    - Inserts the new node between the nodes at `pos-1` and `pos`.
  - Increments the `length` by 1.

---

### 8. **Remove from Front**
```cpp
void removeFromFront();
```
- **Description:** Removes the element at the front of the list.
- **Behavior:**
  - If the list is empty:
    - Throws a `runtime_error`.
  - If the list has only one node:
    - Deletes the node and sets `first` and `last` to `nullptr`.
  - Otherwise:
    - Deletes the first node.
    - Updates `first` to point to the second node.
    - Sets the `prev` pointer of the new `first` node to `nullptr`.
  - Decrements the `length` by 1.

---

### 9. **Remove from End**
```cpp
void removeFromEnd();
```
- **Description:** Removes the element at the end of the list.
- **Behavior:**
  - If the list is empty:
    - Throws a `runtime_error`.
  - If the list has only one node:
    - Behaves like `removeFromFront()`.
  - Otherwise:
    - Deletes the last node.
    - Updates `last` to point to the second-to-last node.
    - Sets the `next` pointer of the new `last` node to `nullptr`.
  - Decrements the `length` by 1.

---

### 10. **Remove at a Specific Position**
```cpp
void removeAtPosition(int pos);
```
- **Description:** Removes the element at a specific position in the list.
- **Behavior:**
  - If `pos < 0` or `pos >= length`:
    - Throws an `out_of_range` exception.
  - If `pos == 0`:
    - Calls `removeFromFront()`.
  - If `pos == length - 1`:
    - Calls `removeFromEnd()`.
  - Otherwise:
    - Traverses the list to the specified position.
    - Removes the node at `pos` and updates the links of adjacent nodes.
  - Decrements the `length` by 1.

---

### 11. **Get Front Element**
```cpp
T getFront();
```
- **Description:** Returns the element at the front of the list.
- **Behavior:**
  - If the list is empty:
    - Throws a `runtime_error`.
  - Otherwise:
    - Returns the `data` of the `first` node.

---

### 12. **Get Back Element**
```cpp
T getBack();
```
- **Description:** Returns the element at the end of the list.
- **Behavior:**
  - If the list is empty:
    - Throws a `runtime_error`.
  - Otherwise:
    - Returns the `data` of the `last` node.

---

### 13. **Clear List**
```cpp
void clearList();
```
- **Description:** Clears all the elements in the list.
- **Behavior:**
  - Traverses the list, deleting each node.
  - Resets `first`, `last`, and `length` to their initial states.

---

### 14. **Reverse List**
```cpp
void reverseList();
```
- **Description:** Reverses the order of the elements in the list.
- **Behavior:**
  - Traverses the list, swapping the `prev` and `next` pointers for each node.
  - Swaps `first` and `last` pointers.
  - Throws a `runtime_error` if the list is empty.

---

### 15. **Check if Value Exists**
```cpp
bool contains(T value);
```
- **Description:** Checks if a specific value is present in the list.
- **Behavior:**
  - Traverses the list to find the value.
  - Returns `true` if the value exists, `false` otherwise.
  - Throws a `runtime_error` if the list is empty.

---

### 16. **Find Index of Value**
```cpp
int indexOf(T value);
```
- **Description:** Returns the index of a specific value in the list, or `-1` if not found.
- **Behavior:**
  - Traverses the list to find the value.
  - Returns the index if found, or `-1` if not.
  - Throws a `runtime_error` if the list is empty.

---

### 17. **Update Value at Position**
```cpp
void updateAtPosition(int position, T newValue);
```
- **Description:** Updates the value of an element at a specific position.
- **Behavior:**
  - If `position < 0` or `position >= length`:
    - Throws an `out_of_range` exception.
  - Traverses the list to the specified position and updates the `data` of the node.

---

### 18. **Print Forward**
```cpp
void printForward();
```
- **Description:** Prints all elements of the list from front to end.
- **Behavior:**
  - Traverses the list from `first` to `last`.
  - Throws a `runtime_error` if the list is empty.

---

### 19. **Print Backward**
```cpp
void printBackward();
```
- **Description:** Prints all elements of the list from end to front.
- **Behavior:**
  - Traverses the list from `last` to `first`.
  - Throws a `runtime_error` if the list is empty.

---

## Testing
You can write test cases in a `main.cpp` file to verify the behavior of this doubly linked list implementation. Ensure to cover edge cases like empty list operations, inserting at boundaries, and reversing a single-element list.

