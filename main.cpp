/*****************************************************************\
|	Features of the Graph class                                   |
|                                                                 |
|	>Supports directed/not directed graphs                        |
|	>Basic functions:                                             |
|		>Add/delete vertices                                      |
|		>Add/delete edges                                         |
|                                                                 |
|		>Create graph with fixed number of points (without edges) |
|                                                                 |
|	>Graph Algorithms:                                            |
|		>DFS                                                      |
|		>BFS                                                      |
|	                                                              |
\*****************************************************************/

#include "Graph.h"
#include <iostream>

using namespace std;

int main() {

	int noOfVertices = 10;
	Graph mygraph(noOfVertices); /**/

	/** Add edges to 'mygraph' **/
	for (int i = 0; i < noOfVertices; i++) {
		for (int j = 0; j < noOfVertices; j++)
            if (i+2 == j)
                mygraph.addUndEdge(i, j);
	}
	mygraph.addUndEdge(5,6);
	mygraph.addUndEdge(8,9);
	mygraph.addUndEdge(2,3);
	mygraph.addUndEdge(0,9);
	mygraph.addUndEdge(1,7);
	mygraph.delVertex(4);
	mygraph.addVertex();

	/** Testing operator= **/
	Graph mygraph2;
	mygraph2 = mygraph;

	/** Plot the adjacency matrices **/
	cout << "Adacency matrix of 'mygraph':" << endl;
	mygraph.printAdjM();
	cout << "Adacency matrix of 'mygraph2':" << endl;
	mygraph2.printAdjM();

    /** Testing operator== **/
	if (mygraph2 == mygraph) cout << "'mygraph2' indeed equals to 'mygraph'" <<endl;

	/** DFS **/
	int dfsStartVertex = 0;
	int* visited = new int[noOfVertices];
	for(int i=0; i<noOfVertices; ++i) visited[i] = 0;
	cout << "Traversal order of DFS search on 'mygraph' starting from vertex " << dfsStartVertex<<endl;
	mygraph.runDFS(dfsStartVertex, visited);

	/** BFS **/
	int bfsStartVertex = 0;
    for(int i=0; i<noOfVertices; ++i) visited[i] = 0;
    cout << "\nTraversal order of BFS search on 'mygraph' starting from vertex "<<bfsStartVertex<<endl;
    cout << bfsStartVertex << " ";
    mygraph.runBFS(bfsStartVertex, visited);
    delete[] visited;


	//getchar(c);
	return 0;
}
