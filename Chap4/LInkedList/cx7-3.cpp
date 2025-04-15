#include "cx7-2.h"
#include <assert.h>

List::List()
{
    numberOfElements = 0;
    currentPosition = -1; // invalid로 정의하고 시작.
}

void List::insert(const ListElementType &elem)
{
    assert(numberOfElements < maxListSize); // 최대 배열 안 넘기는지 확인
    listArray[numberOfElements] = elem; // 0번째에 elem 넣어주기
    numberOfElements++; // 인덱스 하나 올려주기
}

bool List::first(ListElementType &elem) // 첫 번째 원소 가져오기
{
    if(numberOfElements == 0) { // 아무것도 없다면 false
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
    assert(currentPosition >= 0); // 배열 원소가 한 개면 다음꺼 없기 때문에 프로그램 죽임.
    if(currentPosition >= numberOfElements - 1) { // 뒤로 갈 수 없다면?
        return false;
    } 
    else {
        currentPosition++;
        elem = listArray[currentPosition];
        return true;
    }
        
}