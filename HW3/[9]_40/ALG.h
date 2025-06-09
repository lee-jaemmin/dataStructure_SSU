#include "graph.h"
#include "List.h"
#include <assert.h>
//20212861 이재민

typedef List<int> IntList;
typedef ListIter<int> InstListIter;

class ALGraph : public Graph
{
    public:
        ALGraph(int size) : Graph(size) { // vertex개수에 대한 초기화는 부모 클래스가.
                                          // 자식 클래스는 ALG에 대한 구현만 한다.
            vertexList = new IntList[n]; // vertex개수만큼 배열 생성. 
            assert(vertexList);
        }
        friend class NeighborIter;
    protected:
        IntList* vertexList;
};

class NeighborIter : public InstListIter
{
    public:
        NeighborIter(const ALGraph &G, int startVertex)
            : InstListIter(G.vertexList[startVertex], G.n) {
                assert(startVertex < G.n);
            } // ListIter에게 전체 G 중 특정한 Vertex를 넘김.
              // VertexList에는 해당 vertex와 인접한 LL이 있겠죠.
              // G의 vertex 개수도 넘겨줌.
};
