#include <iostream>
#include "hashTable.h"
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
    Table <int, int> t; // Table 객체 선언(배열로 하지 ㅁr..)
    Table <int, CPhone> t2;
    int birth, i;


    for(i = 0; i < 7; i++) {
        cin >> birth;
        t.insert(birth, i);
    }
    cout << endl << "4번 dump" << endl;
    t.dump();
    cout << endl;
    
    //8진수 -10진수 혼동 때문에 stoi사용!!
    t.deleteKey(stoi("010101")); // index 3 삭제
    t.deleteKey(stoi("010111")); // index 2 삭제

    birth = 100102; // 모듈러 연산 시 2 나옴
    i = 0;
    t.insert(birth, i); 

    cout << endl << "5번 dump" << endl;
    t.dump();

    //t2 데이터 추가
    string name;

    for(i = 0; i < 3; i++) {
        CPhone phone;
        cin >> birth;
        cin >> name;
        
        phone.setName(name);
        phone.setBirth(birth);

        int newName = stringToint(name);
        
        t2.insert(newName, phone);
    }
    t2.dump();

    //t2 에서 찾을을 key, data 입력 받기
    CPhone phone;
    cout << "삭제할 이름 입력: ";
    cin >> name;
    int target = stringToint(name);
    
    
    while(1) {
        if(t2.lookup(target, phone)) {
            cout << phone.getName() << "\t";
            cout << phone.getBirth();
            break;
        }
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