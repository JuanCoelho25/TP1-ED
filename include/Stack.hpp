#ifndef STACK_HPP
#define STACK_HPP

template <typename T>

class Stack {
private:
    int Max = 5;
    T* arr = new int(Max);
    T minEle = 0;
    int top = 0;
    
public:

    // Method to check whether
    // stack is empty or not
    bool empty();

    // Method to push elements
    // to the Special Stack
    void push(T x);
    
    // Method to pop the elements
    // from the stack.
    void pop();
 
    // Method to find the topmost
    // element of the stack
    T peek();

    // Method to find the Minimum
    // element of the Special stack
    T getMin();
};


#endif