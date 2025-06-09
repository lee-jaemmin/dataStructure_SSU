#ifndef __MB_CX_8_3__
#define __MB_CX_8_3__
#include <assert.h>

template <typename StackElementType>
class Stack{
    public:
        Stack();
        void push(StackElementType item);
        StackElementType pop();
        StackElementType top();
        bool isEmpty();
    
    private:
       struct Node;
       typedef Node* Link;
       struct Node {
        StackElementType elem;
        Link next;
       };
       Link head;
};

#endif

template <class StackElementType>
StackElementType Stack <StackElementType> :: Stack()
{
    head = 0;
}

template <class StackElementType>
bool Stack <StackElementType> :: isEmpty()
{
    return (head == nullptr);
}

template <class StackElementType>
StackElementType Stack <StackElementType> :: top()
{
    assert(!isEmpty()) 

    return head->data;
}

template <class StackElementType>
StackElementType Stack <StackElementType> :: pop()
{
    assert(!isEmpty());

    Link delNode = head;
    head = head->next;
    StackElementType temp = delNode->elem;
    delete delNode;
    return temp;
}