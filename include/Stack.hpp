#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>

template <typename T>
class Stack {
private:
    T* elements;        // Pointer to the dynamic array
    size_t capacity;    // Current capacity of the dynamic array
    size_t stackSize;   // Number of elements in the stack

public:
    // Constructor: Initialize the stack with default capacity and size.
    Stack();

    // Push an element onto the stack.
    void push(const T& item);

    // Pop and remove the top element from the stack.
    void pop();

    // Get the top element of the stack.
    T top() const;

    // Check if the stack is empty.
    bool isEmpty() const;

    // Get the number of elements in the stack.
    size_t size() const;

    // Destructor: Free memory allocated for the dynamic array.
    ~Stack();
};


#endif


