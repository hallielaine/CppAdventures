#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

class Stack {
    public:
        Stack();
        ~Stack();
        
        // Tests whether or not the stack is empty
        bool Empty();
        //Gets the size of the stack
        int Size();
        // Get the element from the top of the Stack
        int Top();
        //Add an element to the top of the Stack
        void Push(int value);
        // Remove the element fromt he top of the Stack
        int Pop();
        
    private:
        int *data;
        int size;
        int capacity;
};
        