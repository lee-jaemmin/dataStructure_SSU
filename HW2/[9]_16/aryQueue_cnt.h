#include <assert.h>

const int maxQueue = 200;
//20212861 이재민

template <class queueElementType>
class Queue
{
    public:
        Queue();
        void enqueue(queueElementType e);
        queueElementType dequeue();
        queueElementType front();
        bool isEmpty();
        bool isFull();
        ~Queue();

    private:
        int f;
        int r;
        int m_ncnt;
        queueElementType queueAry[maxQueue];
};


int nextPos(int p)
{
    return ((p + 1) % maxQueue);
}

template <class queueElementType>
Queue <queueElementType> :: Queue()
{
    f = 0;
    r = 0;
    m_ncnt = 0;
}

template <class queueElementType>
void Queue<queueElementType> :: enqueue(queueElementType e)
{
    assert(!isFull());
    queueAry[r] = e; // 넣고
    r = nextPos(r); // 올리고
    m_ncnt++; // 카운트 증가
}

template <class queueElementType>
queueElementType Queue<queueElementType> :: dequeue()
{
    assert(!isEmpty());
    queueElementType elem = queueAry[f]; // 뺄 거 저장
    f = nextPos(f); // f 한칸 올리고
    m_ncnt--; // 개수 하나 감소
    return elem;
}

template <class queueElementType>
queueElementType Queue <queueElementType> :: front()
{
    assert(!isEmpty());
    return queueAry[f];
}

template <class queueElementType>
bool Queue <queueElementType>::isEmpty()
{
    return (m_ncnt == 0);
}

template <class queueElementType>
bool Queue <queueElementType>::isFull()
{
    return (m_ncnt == maxQueue - 1);
}

template <class QueueElementType>
Queue <QueueElementType>::~Queue()
{
    //여기서는 정적 배열이라 딱히 필요 없음.
    //LinkedList는 동적 할당이라 무조건 만들어줘야함.
}