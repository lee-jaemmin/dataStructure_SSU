#include <iostream>
#include "linkedStack.h"

//20212861 이재민

using namespace std;
int main()
{
    Stack <int> s;
    int i;

    cout << "Enter items to add to list, add 0 to stop\n";
    cin >> i;
    
    while(i != 0) {
        s.insert(i);
        cin >> i;
    }

    cout << "\nHere are the itmes in the list\n";
    
    while(!(s.isEmpty())) {
        cout << s.pop() << endl;
    }


    cout << "정상 종료";
    return 0;
}