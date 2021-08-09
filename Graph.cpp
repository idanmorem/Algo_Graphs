#include "Graph.h"



/*
 BFS(Graph G, Vertex s)
Queue Q
for each vertex v do
d[v] ← ∞
Q.Enqueue(s)
d[s] ← 0
while Q ≠ ∅ do
u ← Q.Dequeue()
for each v ∈Adj[u] do
if d[v] = ∞ then
d[v] ← d[u] + 1
Q.Enqueue(v)
 */

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

AdjacentList Graph::getAdjList(int uVertex) {
    return AdjacentList();
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
        AdjacentList::ListNode *curr = vertexArray[u].getAdjList().getHead();

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
