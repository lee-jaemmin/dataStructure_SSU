#ifndef ARYQUEUE_H
#define ARYQUEUE_H
#include <assert.h>
// 일단은 올리고 넣는다고 가정
// 참고로 cnt 없으면 F, E 방식 상관없이 한 칸 못 씀 --> 종료 조건이 f == nextPos(r)
const int maxQueueSize = 200;
template <class QueueElementType>
class aryQueue
{
private:
    int f; // 빼는 애
    int r; // 넣는 애
    QueueElementType Q[maxQueueSize]; // 이거! 

public:
    aryQueue() : f(0), r(0) {};
    bool isEmpty();
    bool isFull();
    void enqueue(const QueueElementType &elem);
    QueueElementType dequeue();
    int nextPos(const int pos);
};

#endif

template <class QueueElementType>
bool aryQueue <QueueElementType> :: isEmpty()
{
    return (f == r);
}

template <class QueueElementType>
bool aryQueue <QueueElementType> :: isFull()
{
    return (f == nextPos(r));
}

template <class QueueElementType>
int aryQueue <QueueElementType> :: nextPos(int pos)
{
    return (pos + 1) % maxQueueSize;
}

template <class QueueElementType>
void aryQueue <QueueElementType> :: enqueue(const QueueElementType &elem)
{
    assert(!isFull()); // 가득 안 찼는지 확인
    r = nextPos(r); // f 한 칸 올리고
    Q[r] = elem; // 삽입     
}

template <class QueueElementType>
QueueElementType aryQueue <QueueElementType> :: dequeue()
{
    assert(!isEmpty());
    f = nextPos(f);
    return Q[f];
}

