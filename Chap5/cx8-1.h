#include <iostream>

#ifndef __MB_CX_8_1__
#define __MB_CX_8_1__

const int maxStackSize = 1000;
typedef char StackElementType;

class Stack{
    public:
        Stack();
        void push(StackElementType item);
        StackElementType pop();
        StackElementType top();
        bool isEmpty();
    
    private:
        StackElementType stackArray[maxStackSize];
        int topIndex;
};

#endif