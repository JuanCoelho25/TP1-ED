#ifndef STACK_HPP
#define STACK_HPP


class Stack {
private:
    int Max = 5;
    int* arr = new int(Max);
    int minEle = 0;
    int top = 0;
    
 
public:

    // Method to check whether
    // stack is empty or not
    bool empty();

    // Method to push elements
    // to the Special Stack
    void push(int x);
    
    // Method to pop the elements
    // from the stack.
    void pop();
 
    // Method to find the topmost
    // element of the stack
    int peek();

    // Method to find the Minimum
    // element of the Special stack
    int getMin();
};


#endif