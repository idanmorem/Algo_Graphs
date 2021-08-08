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
    vertexArray = new Vertex[size + 1];
    numberOfVertex = size;
    for(int i = 1; i <= size; i++)
    {
        vertexArray[i].setValue(i);
    }
}

int Graph::Vertex::getValue() const {
    return value;
}

void Graph::Vertex::setValue(int value) {
    Vertex::value = value;
}
