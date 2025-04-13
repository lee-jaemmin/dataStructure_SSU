#include <iostream>
#include "cx8-1.h"
#include <assert.h>

Stack::Stack()
{
    topIndex = -1; // 최초 생성 시 스택에 아무것도 없는 상태.
}

void Stack::push(StackElementType item)
{
    ++topIndex;
    // 배열 초과 방지
    assert(topIndex < maxStackSize);
    stackArray[topIndex] = item;
}

StackElementType Stack::pop()
{
    assert(topIndex >= 0);
    int returnIndex(topIndex);
    --topIndex;
    return stackArray[returnIndex];
}

StackElementType Stack::top()
{
    assert(topIndex >= 0);
    return stackArray[topIndex];
}

bool Stack::isEmpty()
{
    return bool(topIndex == -1);
}