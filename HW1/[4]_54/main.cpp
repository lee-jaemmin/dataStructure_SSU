#include <iostream>
#include "dummyHead.cpp"

//20212861 이재민민

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

    ListElementType elem;
    bool notEmpty(l.first(elem));

    while(notEmpty) {
        cout << elem << endl;
        notEmpty = l.next(elem);
    }


    return 0;
}