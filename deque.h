#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>  // For exception handling

// Node struct for the doubly linked list
struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
};

// Deque class definition
class Deque {
private:
    Node* front;   // Pointer to the front node
    Node* back;    // Pointer to the back node
    int size;       // Current size of the deque
    int capacity;  // Maximum capacity of the deque

public:
    // Constructor to initialize an empty deque
    Deque(int cap = 1000);

    // Destructor to clean up memory
    ~Deque();

    // Push an element to the front of the deque
    void push_front(int value);

    //Push an element to the back of the deque
    void push_back(int value);

    //Pop and return the front element of the deque
    int pop_front();

    // Pop and return the back element of the deque
    int pop_back();

    //Peek at the front element without removing it
    int peak_front() const;

    //Peek at the back element without removing it
    int peak_back() const;

    //Remove all elements and free memory
    void remove_all();

    //Get the current size of the deque
    int get_size() const;
};

#endif
