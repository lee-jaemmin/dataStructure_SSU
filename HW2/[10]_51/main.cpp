#include <iostream>
#include "linkedListHash.h"
#include "Cphone.h"

using namespace std;
//20212861 이재민

int stringToint(const string &strName) 
{
    int nSum = 0;
    for (int nIndex = 0; nIndex < strName.length(); nIndex++) {
        nSum += strName.at(nIndex); // 각 문자의 아스키값을 누적
    }
    return nSum;
}

int main()
{
    Table <int, CPhone> t;
    int birth, i;
    string name;

    for(i = 0; i < 3; i++) {
        CPhone phone;
        cin >> birth;
        cin >> name;
        
        phone.setName(name);
        phone.setBirth(birth);

        int newName = stringToint(name);
        
        t.insert(newName, phone);
    }
    t.dump();

    //t2 에서 찾을 key, data 입력 받기
    CPhone phone;
    cout << "삭제할 이름 입력: ";
    cin >> name;
    int target = stringToint(name);
    
    
    
    if(t.lookup(target, phone)) {
        cout << phone.getName() << "\t";
        cout << phone.getBirth();
    }


    return 0;
}



/* 
010101  
010111
950710
230709
690829
700413
031105

010101 Jin
010111 Jay
950710 sugar 
한국 이름일 경우 오버플로우가 엄청 빨리 남.
*/