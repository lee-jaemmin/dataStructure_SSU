#include <iostream>
#include "dummyHead.cpp"

//뒤에다 연결하는 더미 리스트. cpp파일 생성자에서 쓸데없는 변수 선언 등 전체적인 다듬기 필요.

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