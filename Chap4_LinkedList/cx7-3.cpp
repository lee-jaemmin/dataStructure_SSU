#include <iostream>
#include "cx7-2.h"
#include <assert.h>

List::List()
{
    numberOfElements = 0;
    currentPosition = -1;
}

void List::insert(const ListElementType &elem)
{
    assert(numberOfElements < maxListSize); // false면 프로그램 죽이기
    listArray[numberOfElements] = elem; // 일단 첫 원소를 가리키며 시작
    numberOfElements++;
}

bool List::first(ListElementType &elem) // 첫 번째 원소 가져오기기
{
    if(numberOfElements == 0) {
        return false;
    }
    else {
        currentPosition = 0;
        elem = listArray[currentPosition];
        return true;
    }
}

bool List::next(ListElementType &elem)
{
    assert(currentPosition >= 0);
    if(currentPosition >= numberOfElements - 1) { // 뒤로 갈 수 없다면?
        return false;
    } 
    else {
        currentPosition++;
        elem = listArray[currentPosition];
        return true;
    }
        
}