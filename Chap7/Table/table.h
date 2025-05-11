#include <assert.h>
#ifndef TABLE_H
#define TABLE_H

const int MAX_TABLE = 100;

template <class tableKeyType, class tableDataType>
class Table
{
    public:
        Table();
        bool lookup(tableKeyType lookupKey, tableDataType &lookupData); // data 무거울수도 있으니까 주소 사용
        void insert(tableKeyType insertKey, tableDataType insertData);
        void deleteKey(tableKeyType deleteKey); // key만 지우는 이유

    private:
        struct item
        {
            tableKeyType key;
            tableDataType data;
        };

        item T[MAX_TABLE];
        int entries;
        int search(tableKeyType key); // 얘는 왜 private이야       
};
#endif

template <class tableKeyType, class tableDataType>
int Table <tableKeyType, tableDataType>::search(tableKeyType key)
{
   int pos;
   for(pos = 0; pos < entries && T[pos].key != key; pos++) {
    return pos;
   }
}

template <class tableKeyType, class tableDataType>
Table <tableKeyType, tableDataType>::Table()
{
    entries = 0;
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::insert(tableKeyType key, tableDataType data)
{
    assert(entries < MAX_TABLE);
    int pos(search(key));
    if(pos == entries) // 없으면
    {
        entries++;
        T[pos].key = key;
        T[pos].data = data;
    }
}

template <class tableKeyType, class tableDataType>
bool Table <tableKeyType, tableDataType>::lookup(tableKeyType key, tableDataType &data)
{
    int pos(search(key)); // key의 위치 찾기
    if(pos == entries) { // 없으면
        return false;
    } else { // 있으면
        data = T[pos].data; // data에 key 위치의 데이터 넣기
        return true;
    }
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::deleteKey(tableKeyType key)
{
    int pos(search(key)); // 지우고 싶은 데이터
    if(pos < entries) { // pos == entries이면 테이블에 데이터가 없다는 소리
        --entries;
        T[pos] = T[entries]; // 마지막 줄에 있던 거를 지우고 싶은 자리에 넣기   
    }
} 
