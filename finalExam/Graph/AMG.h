#include "graph.h"
#include <assert.h>
//20212861 이재민

class amGraph : public Graph
{
    public:
        amGraph(int size);
        virtual bool edgeMember(int fromV, int toV);
    protected:
        int* *am; // 2차원 배열 생성
};

amGraph::amGraph(int size) : Graph(size)
{
    int i;
    am = new int*[n];
    assert(am);

    for(i = 0; i < n; i++) {
        am[i] = new int[n];
        assert(am[i]);
        int j;
        for(j = 0; j < n; j++) {
            am[i][j] = 0;
        }
    }
}

bool amGraph::edgeMember(int fromV, int toV)
{
    assert(fromV < n && toV < n && fromV >= 0 & toV >= 0);
    return bool(am[fromV][toV] != 0);
}