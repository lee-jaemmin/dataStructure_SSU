const int tSize = 100;

template <class tableKeyType, class tableDataType>
class Table
{
private:
    struct item
    {
        tableKeyType key;
        tableDataType data;
    };

    item T[tSize];
    int entries;
    int pos;
public:
    Table() : entries(0) {};
    int search(tableKeyType &key); 
    void insert(tableKeyType &key, tableDataType &data);
    void del(tableKeyType &key);   
    bool lookup(tableKeyType &key, tableDataType &data);
};

template <class tableKeyType, class tableDataType>
int Table <tableKeyType, tableDataType>::search(tableKeyType &key)
{
    int pos;
    for(pos = 0; pos < entries && T[pos].key != key; pos++);
    return pos;
    // 찾으면 pos == 그 자리
    // 못 찾으면 pos == entries.
    // int 하나가 두 가지 정보를 포함. '타당성', '위치'
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::insert(tableKeyType &key, tableDataType &data)
{
    // insert 다시 써보기.
    assert(entries < tSize); // entries는 저장된 개수!! 오해 금지
    int pos = search(key);
    if(pos == entries) { 
        // 못 찾음
        entries++;
    }
    T[pos].key = key;
    T[pos].data = data;
    
}

template <class tableKeyType, class tableDataType>
bool Table <tableKeyType, tableDataType>::lookup(tableKeyType &key, tableDataType &data) 
{
    int pos(search(key)); 
    if(pos == entries) { 
        return false;
    } else { 
        data = T[pos].data;
        return true;
    }
}

template <class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType> :: del(tableKeyType &key)
{
    int pos = search(key);
    if(pos < entries) { // < rather than !=
        entries--;
        T[pos] = T[entries]; // key, data 따로 바꿀 필요 없이 한 번에 하면 됨.
    }
}