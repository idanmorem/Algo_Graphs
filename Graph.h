#include "AdjacentList.h"
#include "Queue.h"

class Graph {
    class Vertex{
        AdjacentList list;
        int value;
    public:
        int getValue() const;

        void setValue(int value);
    };

public:
    Vertex* vertexArray;
    int numberOfVertex;

public:
    Graph() {vertexArray = nullptr;}
    void makeEmptyGraph(int size);
    bool isAdjacent(int uVertex, int vVertex);
    AdjacentList getAdjList (int uVertex);
    int addEdge(int uVertex, int vVertex);
    void removeEdge(int uVertex, int vVertex);
    void readGraph();
    void printGraph();
    int isEmpty();
    int* BFS(); //Snir
    Graph shotrestPathGraph(Graph g, Vertex s, Vertex t);
    void givenFunc(); //measuring algorithm time
};


#endif //ALGO_GRAPH_H
