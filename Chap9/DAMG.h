#include "AMG.h"
#include <assert.h>
//20212861 이재민

class dAMGraph : public amGraph
{
    public:
        dAMGraph(int size, int initValue = 0) : amGraph(size) {};
        virtual void addEdge (int fromV, int toV);
};

void dAMGraph::addEdge(int fromV, int toV)
{
    assert(fromV < n && toV < n && fromV >= 0 & toV >= 0);
    if(!edgeMember(fromV, toV)) {
        m++;
        am[fromV][toV] = 1;
    }
}