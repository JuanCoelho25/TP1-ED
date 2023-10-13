#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include "../include/Node.hpp"

/**
 * @brief Represents a generic stack data structure with basic operations.
 *
 * The Stack class is a template class that provides functionality for a stack, including
 * push, pop, top, and isEmpty operations. It uses a linked list-based implementation.
 *
 * @tparam T The type of data stored in the stack.
 */
template <typename T>
class Stack {
	private:
		StackNode <T>* top_; // Pointer to the top of the stack

	public:
		/**
		 * @brief Constructor: Initializes the stack with a nullptr.
		 */
		Stack();

		/**
		 * @brief Pushes an element onto the stack.
		 *
		 * @param data The data to be pushed onto the stack.
		 */
		void push(T data);

		/**
		 * @brief Checks if the stack is empty.
		 *
		 * @return True if the stack is empty, false otherwise.
		 */
		bool isEmpty();

		/**
		 * @brief Returns the top element of the stack without removing it.
		 *
		 * @return The top element of the stack.
		 */
		T top();

		/**
		 * @brief Removes the top element from the stack.
		 */
		void pop();

		/**
		 * @brief Destructor for the Stack class.
		 */
		~Stack();
};

#endif
