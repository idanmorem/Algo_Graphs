#ifndef ALGO_GRAPH_H
#define ALGO_GRAPH_H
#include "AdjacentList.h"
#include "Queue.h"
#define INFINITY (2^31)

class Graph {

public:
    class Vertex {
        AdjacentList list;
        int value;
    public:
        void setValue(int _value){value=_value;};
        void AddNeighbor(int neighbor_value){list.pushBack(list.CreateNode(neighbor_value));};
        int getLastNeighborAdded(){return list.getTailVal();};
        int getValue() const { return value; };
        friend Graph;
        AdjacentList getAdjList() { return list;}
        Vertex(int _value = 0)
        {
            value = _value;

        }
    };

public:
    Vertex *vertexArray;
    int numberOfVertex ;

public:
    Graph() {vertexArray = nullptr;}
    void makeEmptyGraph(int size);
    bool isAdjacent(int uVertex, int vVertex);
    AdjacentList getAdjList (int uVertex);
    int addEdge(Vertex& uVertex, int vVertex_val);
    void removeEdge(int uVertex, int vVertex);
    void readGraph();
    void printGraph();
    int isEmpty();
    int* BFS(Vertex& s); //Snir
    Graph shotrestPathGraph(Graph g, Vertex s, Vertex t);
    void givenFunc(); //measuring algorithm time
};


#endif //ALGO_GRAPH_H
