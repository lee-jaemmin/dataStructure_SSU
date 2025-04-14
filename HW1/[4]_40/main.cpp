#include <iostream>
#include "inorderList.cpp"

//20212861 이재민

using namespace std;
int main()
{
    List l;
    ListElementType i;

    cout << "Enter items to add to list, add 0 to stop\n";
    cin >> i;
    
    while(i != 0) {
        l.insert(i);
        cin >> i;
    }

    cout << "\nHere are the itmes in the list\n";
    ListElementType elem;
    bool notEmpty(l.first(elem)); // 비어있는지 확인. 일단 정수 변수 쓰레기값 넘김? 
    while(notEmpty) { // 안 비었다면
        cout << elem << endl;
        notEmpty = l.next(elem);
    }


    cout << "정상 종료";
    return 0;
}