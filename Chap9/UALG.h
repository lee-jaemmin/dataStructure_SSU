#ifndef UALG_H
#define UALG_H

#include "ALG.h"

class UALGraph : public ALGraph
{
    public:
        UALGraph(int size) : ALGraph(size) {};
        virtual void addEdge(int fromV, int toV);
};

#endif

void UALGraph :: addEdge(int fromV, int toV)
{
    assert(fromV < n && fromV >= 0 && toV < n && toV >= 0);
    vertexList[fromV].insert(toV);
    vertexList[toV].insert(fromV); // 양방향 작업
    m++; // edge 하나 증가
}