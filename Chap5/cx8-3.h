#ifndef __MB_CX_8_3__
#define __MB_CX_8_3__

const int maxStackSize = 1000;

template <typename StackElementType>
class Stack{
    public:
        Stack();
        void push(StackElementType item);
        StackElementType pop();
        StackElementType top();
        bool isEmpty();
        bool isFull();
    
    private:
        StackElementType stackArray[maxStackSize];
        int topIndex;
};

#endif