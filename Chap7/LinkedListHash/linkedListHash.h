#include <assert.h>
#include <iostream>
#ifndef LINKED_LIST_HASH_H
#define LINKED_LIST_HASH_H

using namespace std;
//20212861 이재민 

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
        struct Slot;
        typedef Slot* Link;
        struct Slot
        {
            tableKeyType key;
            tableDataType data;
            Link next;
        };

        Link T[MAX_TABLE];
        int entries;
        int hash(const tableKeyType &key);
        bool search(Link &slotPointer, const tableKeyType &target);
};
#endif

template <class tableKeyType, class tableDataType>
int Table <tableKeyType, tableDataType>::hash(const tableKeyType &key)
{
   return key % MAX_TABLE; // 해시 함수 작동
}

template <class tableKeyType, class tableDataType>
bool Table <tableKeyType, tableDataType>::search(Link &slotPointer, const tableKeyType &target)
{
    //slot의 주소에서 시작해서 LinkNode가 끝날 때까지 탐색
    for(; slotPointer; slotPointer = slotPointer->next) { 
        if(slotPointer->key == target) { // 있으면
            return true; // 이 시점 slotPointer는 target이 있는 헤드.
        }
        return false;
    }
}

template <class tableKeyType, class tableDataType>
Table <tableKeyType, tableDataType>::Table()
{
    int i;
    for(i = 0; i < MAX_TABLE; i++) {
        T[i] = 0; // 모든 테이블 slot nullpointer로 초기화.
    }
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::insert(tableKeyType &key, tableDataType &data)
{
    int pos(hash(key)); // 해싱을 함: 0~10사이 값.
    Link sp(T[pos]); // 헤드[0~10] 주소 sp에 저장.

    if(!search(sp, key)) { // search의 return 값이 false면 (=없으면, = 새로운 거 넣어야하면)
        Link insertedSlot = new Slot;
        insertedSlot->key = key;
        insertedSlot->data = data;
        insertedSlot->next = T[pos];
        T[pos] = insertedSlot;
    } else { // 있으면 
        sp->data = data; // 데이터만 교체.
    }
}

template <class tableKeyType, class tableDataType>
bool Table <tableKeyType, tableDataType>::lookup(tableKeyType &key, tableDataType &data)
{
    int pos(hash(key)); // 해싱하기
    Link sp(T[pos]);
    if(search(sp, key)) { // 있으면
        data = sp->data;
        return true;
    } else { // 없으면
        return false;
    }
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::deleteKey(const tableKeyType &key)
{
    int pos(hash(key)); // 지우고 싶은 데이터 해시
    Link p;
    if(T[pos] == 0) { // 없으면
        return;
    }
    // p->next를 이용해 key 비교를 할 거기 때문에 첫번째에 바로 있는 경우가 special case가 됨.
    if((T[pos]->key == key)) { // 첫 노드가 타겟이면면
        Link deleteSlot(T[pos]); // 현재 주소 저장. (첫 노드 주소)
        T[pos] = T[pos]->next; // 한 칸 뒤로 옮김
        delete deleteSlot;
    } else {
        for(p = T[pos]; p->next; p = p->next){ //T[pos]부터 시작해서 null 나올 때까지 이동
            if(p->next->key == key) { // 내 다음거가 지울 녀석이면
                Link deleteSlot = p->next; // 저장
                p->next = p->next->next; // 한칸뒤로
                delete deleteSlot;// 삭제
                break;
            }
        }
    }
} 

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::dump()
{
    int i;
    for(i = 0; i < MAX_TABLE; i++) {
        cout << i << '\t';
        Link p;
        for(p = T[i]; p; p = p->next) {
            cout << p->key << '\t';
            cout << endl;
        }
        cout << endl;
    }
}
