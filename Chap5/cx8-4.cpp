#include <iostream>
#include "cx8-3.h"
#include <assert.h>

template <typename StackElementType>
Stack <StackElementType> ::Stack()
{
    topIndex = -1; // 최초 생성 시 스택에 아무것도 없는 상태.
}

template <typename StackElementType>
void Stack <StackElementType>::push(StackElementType item)
{
    ++topIndex;
    // 배열 초과 방지
    assert(!isFull())
    stackArray[topIndex] = item;
}

template <typename StackElementType>
StackElementType Stack <StackElementType>::pop()
{
    assert(!isEmpty());
    int returnIndex(topIndex);
    --topIndex;
    return stackArray[returnIndex];
}
template <typename StackElementType>
StackElementType Stack<StackElementType>::top()
{
    assert(!isEmpty());
    return stackArray[topIndex];
}

template <typename StackElementType>
bool Stack<StackElementType>::isEmpty()
{
    return bool(topIndex == -1);
}

template <typename StackElementType>
bool Stack<StackElementType>::isFull()
{
    return bool(topIndex == maxStackSize - 1); // 왜 -1이지?
}