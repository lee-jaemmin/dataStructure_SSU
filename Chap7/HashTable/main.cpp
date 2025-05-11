#include <iostream>
#include "hashTable.h"

using namespace std;

int main()
{
    Table <int, int> t; // Table 객체 선언(배열로 하지 ㅁr..)
    int birth, i;


    for(i = 0; i < 7; i++) {
        cin >> birth;
        t.insert(birth, i);
    }
    cout << "[Dump]" << endl;
    t.dump();
    cout << endl;
    
    t.deleteKey(0);
    t.deleteKey(1);

    birth = 020202;
    i = 0;
    t.insert(birth, i);
    

    t.dump();
    return 0;
}
