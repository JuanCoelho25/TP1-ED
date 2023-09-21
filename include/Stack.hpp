#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>

template <typename T>
class Stack {
private:
    T* elements;
    size_t capacity;
    size_t stackSize;

public:
    Stack();
    void push(const T& item);
    void pop();
    T top() const;
    bool isEmpty() const;
    size_t size() const;
    ~Stack();
};

#endif  // STACK_HPP


