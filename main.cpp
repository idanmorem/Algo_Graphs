#include "IO.h"
#include "Graph.h"

int main()
{
    Graph g;
    g.makeEmptyGraph(5);
    g.addEdge(g.vertexArray[1],3);
    g.addEdge(g.vertexArray[2],1);
    g.addEdge(g.vertexArray[3],2);
    g.addEdge(g.vertexArray[3],4);
    g.addEdge(g.vertexArray[4],2);
}


