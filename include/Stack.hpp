#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>

template <typename T>

class Node {
public:
	T data;
	Node* link;

	Node(T n)
	{
		this->data = n;
		this->link = NULL;
	}
};

template <typename T>
class Stack {
private:
	Node <T>* top_;

public:
    // Constructor: Initialize the stack with a nullptr
	Stack();

	// Pushes an element onto the stack
	void push(T data);

	// Checks if the stack is empty
	bool isEmpty();

	// Returns the top element of the stack without removing it
	T top();

	// Removes the top element from the stack
	void pop();

	// Destructor for the Stack class
    ~Stack();

};




#endif


