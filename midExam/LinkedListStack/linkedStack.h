#include <assert.h>
template <class StackElementType>
class Stack
{
    public: 
        Stack();
        void insert(const StackElementType& elem);
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

template <class StackElementType>
Stack <StackElementType> :: Stack()
{
    head = nullptr;
}

template <class StackElementType>
bool Stack <StackElementType>::isEmpty()
{
    return (head == nullptr);
}

template <class StackElementType>
StackElementType Stack <StackElementType>::pop()
{
    assert(!isEmpty());
    Link delNode = head;
    StackElementType temp = delNode->elem;
    head = head->next;
    delete delNode;
    return temp;
}

template <class StackElementType>
void Stack <StackElementType> :: insert(const StackElementType &elem)
{
    Link addedNode = new Node;
    addedNode->elem = elem;
    addedNode->next = head;
    head = addedNode;    
}

template <class StackElementType>
StackElementType Stack<StackElementType>::top()
{
    assert(!isEmpty());
    return (head->elem);
}