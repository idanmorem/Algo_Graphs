#include "Graph.h"


Graph Graph::BuildTransposeGraph()
{
    int u,v;
    Graph gs_t;
    gs_t.makeEmptyGraph(this->numberOfVertex);

    for( u = 1 ; u <= this->numberOfVertex ; u++)
    {
        // Get the Adjacent list of u vertex
        AdjacentList::ListNode *currNeighborVertex = this->getAdjList(u).getHead();

        // Run over the adjacent list of u and for each neighbor v:  add edge (v,u)  v --> u
        while( currNeighborVertex != nullptr )
        {
            // get v value, the neighbor of u
            v = currNeighborVertex->getVal();

            // add edge (v,u) to Gs_T
            gs_t.addEdge(this->vertexArray[v],u);

            // step forward to the next neighbor
            currNeighborVertex = currNeighborVertex->getNext();
        }
    }
    return gs_t;
}


void Graph::makeEmptyGraph(int size)
{
    vertexArray = new Vertex[size + 1] ;
    numberOfVertex = size;
    for(int i = 1; i <= size; i++)
    {
        vertexArray[i].setValue(i);
    }
}

bool Graph::isAdjacent(int uVertex, int vVertex) {
    return false;
}

// need to return 1 if added else return 0
int Graph::addEdge(Vertex& uVertex, int vVertex_val) {

    uVertex.AddNeighbor(vVertex_val);
    if(uVertex.getLastNeighborAdded() != vVertex_val)
        return 0;
    else
        return 1;
}

void Graph::removeEdge(int uVertex, int vVertex) {

}

void Graph::readGraph() {

}

void Graph::printGraph() {

}

int Graph::isEmpty() {
    return 0;
}


int* Graph::BFS(Vertex& s)
{
    int *d = new int[numberOfVertex + 1];
    Queue Q(numberOfVertex);
    int u, v;

    for (v = 1; v <= numberOfVertex; v++)
        d[v] = INFINITY;

    Q.enqueue(s.getValue());
    d[s.getValue()] = 0;

    while (!Q.isEmpty())
    {
        u = Q.dequeue();
        AdjacentList::ListNode *curr = getAdjList(u).getHead();

        while (curr != nullptr) {
            v = curr->getVal();
            if (d[v] == INFINITY) {
                d[v] = d[u] + 1;
                Q.enqueue(v);
            }
            curr = curr->getNext();
        }
    }
    return d;
}


Graph Graph::shotrestPathGraph(Graph g, Vertex s, Vertex t) {
    return Graph();
}

void Graph::givenFunc() {

}
