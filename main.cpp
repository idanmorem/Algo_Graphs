#include "IO.h"
#include "Graph.h"

int main()
{
    /*
    // TEST ONLY
    int t = 5 , s = 1; // source and terminate vertexes values
    Graph g;
    g.makeEmptyGraph(5);
    g.addEdge(g.vertexArray[1],3);
    g.addEdge(g.vertexArray[2],1);
    g.addEdge(g.vertexArray[3],2);
    g.addEdge(g.vertexArray[3],4);
    g.addEdge(g.vertexArray[4],2);
    int* d = g.BFS(g.vertexArray[1]);
    for ( int i = 1; i <= 5 ; i++)
    {
        if(d[i] != INFINITY )
            cout << "Shortest Path to Vertex _" << g.vertexArray[i].getValue() << "_ == " << d[i]  << endl;
        else
            cout << "No path to Vertex _" << g.vertexArray[i].getValue() << "_" << endl;
    }
    // END OF TEST


    Graph H;
    H = Graph::shotrestPathGraph(g,s,t);
    // Print H Graph
    // Print the time measuring

    return 0;
     */

    IO io;
    int i;
    io.graphDefenitionInput();
    std::cout << "Done";
    std::cin >> i;
}


