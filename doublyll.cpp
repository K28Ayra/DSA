#include <iostream>

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

   
    // Function to insert a node at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Otherwise, insert the new node at the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to display the elements of the list in reverse order
    void displayReverse() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example usage of the DoublyLinkedList
    DoublyLinkedList dll;

    dll.insertEnd(1);
    dll.insertEnd(2);
    dll.insertEnd(3);
    dll.insertEnd(4);

    std::cout << "Doubly Linked List: ";
    dll.display();

    std::cout << "Doubly Linked List in Reverse: ";
    dll.displayReverse();

    return 0;
}
