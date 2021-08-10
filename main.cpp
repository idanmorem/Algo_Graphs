#include "IO.h"
#include "Graph.h"

int main()
{
    int t=5,s=1; // source and terminate vertexes values
    Graph g;
    g.makeEmptyGraph(5);
    g.addEdge(g.vertexArray[1],3);
    g.addEdge(g.vertexArray[2],1);
    g.addEdge(g.vertexArray[3],2);
    g.addEdge(g.vertexArray[3],4);
    g.addEdge(g.vertexArray[4],2);


    // Stage 1: Activate BFS algorithm on G graph
    int* d = g.BFS(g.vertexArray[1]);
    for ( int i = 1; i <= 5 ; i++)
    {
        if(d[i] != INFINITY )
            cout << "Shortest Path to Vertex _" << g.vertexArray[i].getValue() << "_ == " << d[i]  << endl;
        else
            cout << "No path to Vertex _" << g.vertexArray[i].getValue() << "_" << endl;
    }
    // End of Stage 1


    // Stage 2 - Delete every edge (u,v) that doesn't make the condition: d[v] = d[u] + 1
    // The graph after the deletion will be called: Gs
    int v,u;
    for( u = 1 ; u <= g.numberOfVertex ; u++)
    {
        // Get the Adjacent list of u vertex
        AdjacentList::ListNode *currNeighborVertex = g.getAdjList(u).getHead();

        // Run over the adjacent list and for each neighbor v, check if d[v] = d[u] + 1
        while( currNeighborVertex != nullptr )
        {
            v = currNeighborVertex->getVal();

            // if d[v] != d[u] + 1 then remove the edge (u,v)
            if( d[v] != (d[u] + 1) )
                g.removeEdge(u,v);

            // step forward to the next neighbor
            currNeighborVertex = currNeighborVertex->getNext();
        }
    }
    // End of Stage 2



    // Stage 3 - Build the transpose graph of Gs
    // The built graph will be called: Gs_T
    Graph gs_t = g.BuildTransposeGraph();
    // End of Stage 3


    // Stage 4 - 4.a Activate BFS on GsT when the source vertex is 't' (user's input vertex)
    //           4.b Delete all edges that doesn't accessible from 't' vertex

    int* dt = gs_t.BFS(gs_t.vertexArray[t]);

    // The graph after the delete will be called: H_T

    // ---------------------------------
    // End of Stage 4

    // Stage 5 - Build the transpose graph of H_T
    // The built graph will be called: H
    // ---------------------------------
    // End of Stage 5


    // RETURN H;











}


