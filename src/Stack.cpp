#include "Stack.hpp"

template <typename T>
Stack<T>::Stack() : capacity(10), stackSize(0) {
    elements = new T[capacity];
}

template <typename T>
void Stack<T>::push(const T& item) {
    if (stackSize >= capacity) {
        size_t newCapacity = capacity * 2;
        T* newElements = new T[newCapacity];

        for (size_t i = 0; i < stackSize; i++) {
            newElements[i] = elements[i];
        }

        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

    elements[stackSize++] = item;
}

template <typename T>
void Stack<T>::pop() {
    if (!isEmpty()) {
        stackSize--;
    }
}

template <typename T>
T Stack<T>::top() const {
    if (!isEmpty()) {
        return elements[stackSize - 1];
    }
    return T();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return stackSize == 0;
}

template <typename T>
size_t Stack<T>::size() const {
    return stackSize;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] elements;
}

template class Stack<char>;
template class Stack<bool>;
