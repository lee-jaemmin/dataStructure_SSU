#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
    public:
        graph(int size): n(size), m(0) {}; // 초기화 리스트
        // int size=생성자 매개변수
        // : n <- size, m <- 0 을 생성자 동시에 실행
        virtual int vertexSize() {return n;} 
        virtual int edgeSize() {return m;} // 정의까지 실행
        virtual void addEdge(int fromV, int toV) = 0; // pure virtual 선언: = 0을 이용한다.
                                                      // addEdge의 경우 자식 클래스에서 계속 바뀔 거기 때문에.
    protected:
        int n; // # of vertex
        int m; // # of edge
};

#endif

