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

    int * res = g.BFS(g.vertexArray[1]);
    for ( int i = 1; i <= 5 ; i++)
    {
        if(res[i] != INFINITY )
            cout << "Shortest Path to Vertex _" << g.vertexArray[i].getValue() << "_ == " << res[i]  << endl;
        else
            cout << "No path to Vertex _" << g.vertexArray[i].getValue() << "_" << endl;
    }

}


