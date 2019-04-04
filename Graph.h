/************\
|  Graph.h   |
\************/

#pragma once /* Include header file only once */

#include "AdjMatrix.h" /* Matrix class to handle adjacency matirx of graph */

class Graph {
	private:
		int size; /* No. of vertices */
		AdjMatrix* adjM; /* Pointer to a Matrix object. Defined in the Graph() constructor */
	public:
		/* Basic functions */
		Graph(int=0); /* Constructor: fix no. of points */
		~Graph(); /* Destructor */

		void addEdge(int, int); /* Add a new edge connecting vertex1 and vertex2 */
		void delEdge(int, int); /* Delete edge between vertex1 and vertex2 */
		void addUndEdge(int, int); /* Add undirected edge */
		void delUndEdge(int, int); /* Delete undirected edge */

		void addVertex(); /* Add new vertex with no edges */
		void delVertex(int); /* Delete the vertex with ID 'id' (also deletes connecting edges */

		bool operator==(Graph&) const; /* Check if two graph are the same */
		void operator=(const Graph&); /* Undefined graph = a defined graph */

		void printAdjM() const; /* Displays the adjacency matrix of the graph to stdout */
		/** void printPath() const; <- non-member function **/
		int getSize() const; /* Getter */

		/**** Graph algorithms ****/
		//void runDFS(int start, int* visited); /* Run the DFS algorithm. Output: a spanning tree */
		void runDFS(int start, int* visited); /* Run the DFS algorithm. Output: a spanning tree */
		void runBFS(int start, int* visited, int prevStart = 0); /* Run the BFS algorithm. Output: a spanning tree */
		//void runDijkstra(int start, int finish, int* shortestPath); /* Run Dijkstra's algorithm */


		/* More features */
		//int* getDegreeDistribution(); /* Get the degree distribution */
};

void printPath(int* path, int length); /* Displays a path in the graph (order of vertices) (stdout)) */
