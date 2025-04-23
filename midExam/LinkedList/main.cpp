#include <iostream>
#include "LinkedList.h"

// Inorder에 head, tail관리
using namespace std;

int main()
{
    
    List l;
    ListElementType i;

    cout << "Enter items to add to list, add 0 to stop\n";
    cin >> i;

    //작성 드가자

    while(i != 0) { 
        l.insert(i); //list에 삽입
        cin >> i; // 다음꺼 입력 받기
    }

    cout << "\nHere are the itmes in the list\n";

    bool notEmpty(l.isEmpty()); // 비어있는지 확인. 일단 정수 변수 쓰레기값 넘김? 
    while(notEmpty) { // 안 비었다면
        cout << elem << endl;
        notEmpty = l.next(elem);
    }


    cout << "정상 종료";
    return 0;
}