#ifndef ARYQUEUE_H
#define ARYQUEUE_H
#include <assert.h>
// 일단은 올리고 넣는다고 가정

const int maxQueueSize = 4;
template <class QueueElementType>
class aryQueue
{
private:
    int f; // 빼는 애
    int r; // 넣는 애
    QueueElementType Q[maxQueueSize]; // 이거!
    int cnt; 

public:
    aryQueue() : f(0), r(0), cnt(0) {};
    bool isEmpty();
    bool isFull();
    void enqueue(const QueueElementType &elem);
    QueueElementType dequeue();
    QueueElementType front();
    int nextPos(const int pos);
};

#endif

template <class QueueElementType>
bool aryQueue <QueueElementType> :: isEmpty()
{
    return (cnt == 0);
}

template <class QueueElementType>
bool aryQueue <QueueElementType> :: isFull()
{
    return (cnt == (maxQueueSize - 1));
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
    cnt++;     
}

template <class QueueElementType>
QueueElementType aryQueue <QueueElementType> :: dequeue()
{
    assert(!isEmpty());
    f = nextPos(f);
    cnt--;
    return Q[f];
}

template <class QueueElementType>
QueueElementType aryQueue <QueueElementType> :: front()
{
    assert(!isEmpty());
    return Q[nextPos(f)];
}

