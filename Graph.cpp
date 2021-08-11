#include "Graph.h"


Graph Graph::BuildTransposeGraph()
{
    int u,v;
    Graph gs_t;
    gs_t.makeEmptyGraph(numberOfVertex);

    for( u = 1 ; u <= numberOfVertex ; u++)
    {
        // Get the Adjacent list of u vertex
        AdjacentList::ListNode *currNeighborVertex = getAdjList(u).getHead();

        // Run over the adjacent list of u and for each neighbor v:  add edge (v,u)  v --> u
        while( currNeighborVertex != nullptr )
        {
            // get v value, the neighbor of u
            v = currNeighborVertex->getVal();

            // add edge (v,u) to Gs_T
            gs_t.addEdge(vertexArray[v],u);

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
    if(isEmpty() == 0)
    {
        for(int i = 0; i < numberOfVertex; i++)
        {
            AdjacentList::ListNode* currentNode = vertexArray[i].list.getHead();
            while(currentNode != nullptr)
            {
                std::cout << "(" << i << "," << currentNode->getVal() << ") ";
                currentNode = currentNode->getNext();
            }
        }
    }
    else
    {
        std::cout << "The graph is empty" << std::endl;
    }
}

int Graph::isEmpty() {
    if(numberOfVertex == 0)
        return 1;
    else
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


Graph Graph::shotrestPathGraph(Graph g, int s, int t) {

    int v,u;
    // Stage 1: Activate BFS algorithm on G graph
    int* d = g.BFS(g.vertexArray[s]);
    for ( int i = 1; i <= g.numberOfVertex ; i++) {
        if(d[i] != INFINITY )
            cout << "Shortest Path to Vertex _" << g.vertexArray[i].getValue() << "_ == " << d[i]  << endl;
        else
            cout << "No path to Vertex _" << g.vertexArray[i].getValue() << "_" << endl;
    }

    // Stage 2 - Delete every edge (u,v) that doesn't make the condition: d[v] = d[u] + 1
    // The graph after the deletion will be called: Gs

    for( u = 1 ; u <= g.numberOfVertex ; u++) {
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
    // Stage 3 - Build the transpose graph of Gs: Gs_T
    Graph gs_t = g.BuildTransposeGraph();

    // Stage 4 - 4.a Activate BFS on GsT when the source vertex is 't'
    int* dt = gs_t.BFS(gs_t.vertexArray[t]);
    // 4.b Delete all edges that doesn't accessible from 't' vertex  TODO: CHECK HOW TO DO 4.b
    // -------
    // Gs_T after the represent : H_T Graph

    // Stage 5 - Return the transpose graph of H_T : H
    delete d;
    delete dt;
    return gs_t.BuildTransposeGraph(); // Return H
}

