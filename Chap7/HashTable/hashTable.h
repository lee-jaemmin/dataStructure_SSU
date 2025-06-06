#include <assert.h>
#include <iostream>
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

using namespace std;
const int MAX_TABLE = 11;

template <class tableKeyType, class tableDataType>
class Table
{
    public:
        Table();
        bool lookup(tableKeyType &lookupKey, tableDataType &lookupData); // data 무거울수도 있으니까 주소 사용
        void insert(tableKeyType &insertKey, tableDataType &insertData); // key, data 모두 무거울 수 있음.
        void deleteKey(const tableKeyType &key);
        void dump(); 

    private:
        enum slotType {Empty, Deleted, InUse};
        struct slot
        {
            slotType slotStatus;
            tableKeyType key;
            tableDataType data;
        };

        slot T[MAX_TABLE];
        int entries;
        int hash(const tableKeyType &key);
        int probe(const int pos); // nextPos같은 역할   
        bool search(int &pos, const tableKeyType &target);
};
#endif

template <class tableKeyType, class tableDataType>
int Table <tableKeyType, tableDataType>::hash(const tableKeyType &key)
{
   return key % MAX_TABLE; // 해시 함수 작동
}

template <class tableKeyType, class tableDataType>
int Table <tableKeyType, tableDataType>::probe(const int pos)
{
    return (pos + 1) % MAX_TABLE;
}

template <class tableKeyType, class tableDataType>
bool Table <tableKeyType, tableDataType>::search(int &pos, const tableKeyType &target)
{
    //pos에서부터 target searching 시작
    for(pos; T[pos].slotStatus != Empty; pos = probe(pos)) { // Empty가 나올 때까지 계속 찾는다.
        if(T[pos].slotStatus == InUse && T[pos].key == target) { // 상태가 InUse고 target과 같은 key 있으면
            return true;
        }
    }
    return false; // pos == 처음 만난 Empty. 따라서 현재 pos 뒤에 element가 남아있을 수도 있음.
                  // insert할 때 pos=hash(key); 를 한 번 더 실행해서 해결     
}

template <class tableKeyType, class tableDataType>
Table <tableKeyType, tableDataType>::Table()
{
    entries = 0;
    int i;
    for(i = 0; i < MAX_TABLE; i++) {
        T[i].slotStatus = Empty;
    }
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::insert(tableKeyType &key, tableDataType &data)
{
    assert(entries < MAX_TABLE - 1); // 하나의 Empty가 있을 자리 필요 (종료 조건) => -1 해줘야. Empty를 찾아야 서칭이 끝나니까.
    int pos(hash(key));

    if(!search(pos, key)) { // Empty 만나서 나왔으면 => 없다고 판단
        pos = hash(key); // search하느라 바뀐 pos 값 다시 원위치
    }
    // search = false : pos는 원래 원위치
    // search = true: pos는 찾은은 위치

    while(T[pos].slotStatus == InUse) { // 차 있으면 (사용 중이면)
        pos = probe(pos); // 선형 탐색.
    }
    entries++; // 개수 증가
    //deleted나 empty 만나서 나옴.
    T[pos].slotStatus = InUse;
    T[pos].key = key;
    T[pos].data = data;
}

template <class tableKeyType, class tableDataType>
bool Table <tableKeyType, tableDataType>::lookup(tableKeyType &key, tableDataType &data)
{
    int pos(hash(key)); // 해싱하기
    if(search(pos, key)) { // 있으면
        data = T[pos].data;
        return true;
    } else { // 없으면
        return false;
    }
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::deleteKey(const tableKeyType &key)
{
    int pos(hash(key)); // 지우고 싶은 데이터 해시
    if(search(pos, key)) { // 지우고 싶은 거 찾으면
        T[pos].slotStatus = Deleted; // 상태 바꾸고
        entries--; 
    }
} 

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::dump()
{
    int i;
    for(i = 0; i < MAX_TABLE; i++) {
        cout << i << '\t';
        switch(T[i].slotStatus) {
            case InUse:
                cout << "In Use\t" << T[i].key << endl;
                break;
            case Deleted:
                cout << "Deleted\t" << T[i].key << endl;
                break;
            case Empty:
                cout << "Empty\t" << endl;
                break;
        }
    }
    cout << "Entries = " << entries << "\n\n";
}
