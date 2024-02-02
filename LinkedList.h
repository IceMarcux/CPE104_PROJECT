// LinkedList.h
#pragma once

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;

public:
    // Function to add data to the front of the linked list
    void addToFront(const T& data);

    // Function to insert data at the end of the linked list
    void addToEnd(const T& data);

    // Function to insert data after a specified node
    void insertAfter(Node<T>* prevNode, const T& data);

    // Function to delete the node at the front of the linked list
    void deleteFront();

    // Function to delete the node at the end of the linked list
    void deleteEnd();

    // Function to delete a specified node from the linked list
    void deleteNode(Node<T>* nodeToDelete);

    // Function to search for a node with the given data
    Node<T>* search(const T& data);

    // Function to retrieve the data of the node at the front
    T getFront() const;

    // Function to get the size of the linked list
    int size() const;

    // Function to check if the linked list is empty
    bool isEmpty() const;

    // Function to print the contents of the linked list
    void print() const;

    // Function to clear the entire linked list, freeing memory
    void clear();

    // Function to reverse the order of nodes in the linked list
    void reverse();

    // Destructor to free memory
    ~LinkedList();
};

// Implementation of the addToFront function
template <typename T>
void LinkedList<T>::addToFront(const T& data) {
    Node<T>* newNode = new Node<T>{data, nullptr};

    // Add to the beginning of the linked list
    newNode->next = head;
    head = newNode;
}

// Implementation of the addToEnd function
template <typename T>
void LinkedList<T>::addToEnd(const T& data) {
    Node<T>* newNode = new Node<T>{data, nullptr};

    // If the list is empty, add to the front
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the end and add the new node
    Node<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Implementation of the insertAfter function
template <typename T>
void LinkedList<T>::insertAfter(Node<T>* prevNode, const T& data) {
    if (prevNode == nullptr) {
        std::cerr << "Cannot insert after a null node." << std::endl;
        return;
    }

    Node<T>* newNode = new Node<T>{data, nullptr};
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Implementation of the deleteFront function
template <typename T>
void LinkedList<T>::deleteFront() {
    if (head == nullptr) {
        std::cerr << "Cannot delete from an empty list." << std::endl;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

// Implementation of the deleteEnd function
template <typename T>
void LinkedList<T>::deleteEnd() {
    if (head == nullptr) {
        std::cerr << "Cannot delete from an empty list." << std::endl;
        return;
    }

    if (head->next == nullptr) {
        // If there's only one node, delete it
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

// Implementation of the deleteNode function
template <typename T>
void LinkedList<T>::deleteNode(Node<T>* nodeToDelete) {
    if (nodeToDelete == nullptr) {
        std::cerr << "Cannot delete a null node." << std::endl;
        return;
    }

    if (nodeToDelete == head) {
        // If the node to delete is the head, delete the head
        head = head->next;
        delete nodeToDelete;
        return;
    }

    // Find the node before the one to delete
    Node<T>* current = head;
    while (current->next != nullptr && current->next != nodeToDelete) {
        current = current->next;
    }

    if (current->next == nullptr) {
        std::cerr << "Node to delete not found in the list." << std::endl;
        return;
    }

    // Delete the node
    current->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Implementation of the search function
template <typename T>
Node<T>* LinkedList<T>::search(const T& data) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Implementation of the getFront function
template <typename T>
T LinkedList<T>::getFront() const {
    if (head == nullptr) {
        std::cerr << "Cannot get data from an empty list." << std::endl;
        throw std::out_of_range("Empty list");
    }
    return head->data;
}

// Implementation of the size function
template <typename T>
int LinkedList<T>::size() const {
    int count = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Implementation of the isEmpty function
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

// Implementation of the print function
template <typename T>
void LinkedList<T>::print() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Implementation of the clear function
template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Implementation of the reverse function
template <typename T>
void LinkedList<T>::reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// Implementation of the destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}
