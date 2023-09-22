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
	Stack();

	void push(T data);

	bool isEmpty();

	T top();

	void pop();

    ~Stack();

};




#endif


