// LinkedList.h
#pragma once

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

    // Add other linked list functions as needed

    // Destructor to free memory
    ~LinkedList();
};

// Implementation of the add to front function
template <typename T>
void LinkedList<T>::addToFront(const T& data) {
    Node<T>* newNode = new Node<T>{data, nullptr};

    // Add to the beginning of the linked list
    newNode->next = head;
    head = newNode;
}

// Implementation of the destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    // Add code to deallocate linked list nodes
}
