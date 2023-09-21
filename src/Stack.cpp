#include "Stack.hpp"

    bool Stack::empty()
    {
        if (top <= 0) {
            return true;
        }
        else return false;    
    }

    void Stack::push(int x)
    {
        // If stack is empty
        if (empty()) {
            minEle = x;
            arr[top] = x;
            top++;
        }
        // If array is full
        else if (top == Max) {
            Max = 2 * Max;
 
            int* temp = new int(Max);
 
            // Traverse the array arr[]
            for (int i = 0; i < top; i++) {
                temp[i] = arr[i];
            }

            if (x < minEle) {
                temp[top] = 2 * x - minEle;
                minEle = x;
                top++;
            }
            else {
                temp[top] = x;
                top++;
            }
            arr = temp;
        }
        else {
            if (x < minEle) {
                arr[top] = 2 * x - minEle;
                top++;
                minEle = x;
            }
            else {
                arr[top] = x;
                top++;
            }
        }
    }
    

    void Stack::pop()
    {
        // If stack is empty
        if (empty()) {
            cout << "Underflow" << endl;
            return;
        }
        int t = arr[top - 1];
        if (t < minEle) {
            cout << "Popped element : " << minEle << endl;
            minEle = 2 * minEle - t;
        }
        else {
            cout << "Popped element : " << t << endl;
        }
        top--;
        return;
    }
 
    int Stack::peek()
    {
        if (empty()) {
            cout << "Underflow" << endl;
            return -1;
        }
        int t = arr[top - 1];
        if (t < minEle) {
            return minEle;
        }
        else {
            return t;
        }
    }

    int Stack::getMin()
    {
        if (empty()) {
            cout << "Underflow" << endl;
            return -1;
        }
        else {
            return minEle;
        }
    }