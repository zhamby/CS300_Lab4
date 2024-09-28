#include "deque.h"

// Constructor to initialize an empty deque
Deque::Deque(int cap) : front(nullptr), back(nullptr), size(0), capacity(cap) {}

// Destructor to clean up memory
Deque::~Deque() {
    remove_all();
}


void Deque::push_front(int value) {
    if (size == capacity) {
        throw std::overflow_error("Deque is full");
    }

    Node* new_node = new Node(value);
    
    if (size == 0) {
        front = back = new_node;  // If deque is empty, front and back are the same
    } else {
        new_node->next = front;
        front->prev = new_node;
        front = new_node;
    }

    size++;
}

void Deque::push_back(int value) {
    if (size == capacity) {
        throw std::overflow_error("Deque is full");
    }

    Node* new_node = new Node(value);

    if (size == 0) {
        front = back = new_node;  // If deque is empty, front and back are the same
    } else {
        new_node->prev = back;
        back->next = new_node;
        back = new_node;
    }

    size++;
}

int Deque::pop_front() {
    if (size == 0) {
        throw std::underflow_error("Deque is empty");
    }

    int value = front->value;
    Node* temp = front;

    if (front == back) {
        front = back = nullptr;  // If there's only one node, deque becomes empty
    } else {
        front = front->next;
        front->prev = nullptr;
    }

    delete temp; //free memory
    size--;

    return value;
}

// Pop and return the back element of the deque
int Deque::pop_back() {
    if (size == 0) {
        throw std::underflow_error("Deque is empty");
    }

    int value = back->value;
    Node* temp = back;

    if (front == back) {
        front = back = nullptr;  // If there's only one node, deque becomes empty
    } else {
        back = back->prev;
        back->next = nullptr;
    }

    delete temp;
    size--;

    return value;
}

// Peek at the front element without removing it
int Deque::peak_front() const {
    if (size == 0) {
        throw std::underflow_error("Deque is empty");
    }

    return front->value;
}

// Peek at the back element without removing it
int Deque::peak_back() const {
    if (size == 0) {
        throw std::underflow_error("Deque is empty");
    }

    return back->value;
}

// Remove all elements and free memory
void Deque::remove_all() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
    size = 0;
}

// Get the current size of the deque
int Deque::get_size() const {
    return size;
}

