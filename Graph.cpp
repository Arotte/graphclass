#include "AdjMatrix.h"
#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int noOfVertices) {
    size = noOfVertices;
	/* Allocating space for the Matrix object */
	adjM = new AdjMatrix(noOfVertices);

	//cout<<"Graph with "<< noOfVertices <<" vertices created." <<endl;
}

Graph::~Graph() {
	delete adjM;

	//cout<<"\nGraph object destroyed."<<endl;
}

/* Add a new edge connecting vertex1 and vertex2 */
void Graph::addEdge(int vertex1, int vertex2) {

    if(vertex1 >= 0 && vertex1 <= this->size-1 &&
       vertex2 >= 0 && vertex2 <= this->size-1)
    {
        (*adjM)(vertex1, vertex2) += 1;
    } else cout << "Wrong input for function Graph::addEdge(int,int)!" << endl;

    //cout<<"Directed edge added between vertex "<<vertex1<<" and "<<vertex2<<"."<<endl;
}

void Graph::delEdge(int vertex1, int vertex2) {

    if(vertex1 >= 0 && vertex1 <= this->size-1 &&
       vertex2 >= 0 && vertex2 <= this->size-1)
    {
        if((*adjM)(vertex1, vertex2) != 0)
            (*adjM)(vertex1, vertex2) -= 1;
    } else cout << "Wrong input for function Graph::delEdge(int,int)!" << endl;

    //cout<<"Directed edge deleted between vertex "<<vertex1<<" and "<<vertex2<<"."<<endl;
}

void Graph::addUndEdge(int v1, int v2) {
    addEdge(v1, v2);
    addEdge(v2, v1);
}

void Graph::delUndEdge(int v1, int v2) {
    delEdge(v1, v2);
    delEdge(v2, v1);
}

void Graph::addVertex() {

    (*adjM).addColAndRow();
    this->size++;

    //cout<<"New vertex added. Number of vertices: "<<--size<<"->"<<size<<"."<<endl;
}

void Graph::delVertex(int id) {

    (*adjM).delColAndRow(id);
    --(this->size);

    //cout<<"Vertex "<<id<<" deleted. Number of vertices: "<<size<<"->"<<--size<<"."<<endl;
}

/* Check if two graph are the same */
bool Graph::operator==(Graph& other) const{

    if( (this->adjM)->isEqual(*other.adjM) ) return true;
    /* adjM is a pointer, so this is why the '->' symbol needed after this->adjM.
    *  other.adjM becomes a pointer as well, so the '*' dereference operator needed before other.adjM.
    */
    return false;
}

/* Undefined graph = a defined graph */
void Graph::operator=(const Graph& other) {

    if (this->adjM->isNullMatrix())
        this->size = other.size;

    /* this->adjM is a pointer to a Matrix object, this is why the dereference operator needed after this->adjM.
    *  other.adjM is also a pointer to a Matrix object, this is why the '*' dereference operator needed.
    */
    this->adjM->equalTo(*other.adjM);
}

/* Displays the adjacency matrix of the graph to stdout */
void Graph::printAdjM() const {

    cout << "---------------------------------" <<endl;
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            /* if-else statement is to avoid comma at the end of line */
            if (j != size-1)
                cout << (*adjM)(j, i) << ", ";
            else
                cout << (*adjM)(j, i);
        }
        cout<<"\n";
    }
    cout << "---------------------------------" << endl;
}


/* GETTER function */
int Graph::getSize() const { return this->size; }


/** Recursive function **/
void Graph::runDFS(int start, int* visited) {

    cout << start << " ";
    visited[start] = 1;

    for(int i=0; i<this->size; ++i)
        if(visited[i] == 0 && (*this->adjM)(start, i) == 1)
            (*this).runDFS(i, visited);


}

/** Recursive function **/
void Graph::runBFS(int start, int* visited, int prevStart) {


    //cout << start << " ";
    visited[start] = 1;

    for(int i=0; i<this->size; ++i) {
        if(visited[i] == 0 && (*this->adjM)(start, i) == 1) {
            visited[i] = 1;
            cout << i << " ";
        }
    }

    for(int j = 0; j<this->size; ++j) {
        if(visited[j] == 1 && (*this->adjM)(prevStart, j) == 1) {
            for(int d = 0; d<this->size; ++d) {
                if(visited[d] == 0 && (*this->adjM)(j, d) == 1)
                    (*this).runBFS(j, visited, prevStart);
            }
        }
    }

    for(int k = 0; k<this->size; ++k)
        if(visited[k] == 1 && (*this->adjM)(start, k) == 1)
            (*this).runBFS(k, visited, start);

}

void printPath(int* path, int length) {
    cout << endl;
    for(int i=0; i<length; i++)
        cout << path[i] << "  ";
    cout << endl;
}
