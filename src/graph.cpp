////////////////////////////////////////////////////
// Graph Data Structure - C++ file
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////
#include "graph.h"

////////////////////////////////////////////////////
// METHODS
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// PRIVATE METHODS
////////////////////////////////////////////////////

double graph::prob(void) {

	return ( static_cast<double>(rand()) / static_cast<double>(RAND_MAX) ); 

}

////////////////////////////////////////////////////
// PUBLIC METHODS
////////////////////////////////////////////////////
graph::graph(unsigned int size) {

	gSize = size;
	// allocate memory on heap for base pointer
	g = new unsigned int* [gSize];
	
	for(int i = 0; i < gSize; i++) {
		// allocate memory row by row
		g[i] = new unsigned int[gSize];
		for(int j = 0; j < gSize; j++) {
			g[i][j] = 0;
		}
	}

}

graph::~graph() {

	// delete the rows	
	for(int i = 0; i < gSize; i++) {
		delete [] g[i];
	}
	// delete the base pointer
	delete [] g;

}

void graph::print(void) {

	cout << "Adjacency Matrix: " << endl;	
	for(int i = 0; i < gSize; i++) {
		for(int j = 0; j < gSize; j++) {
			// print one row of the matrix
			cout << "\t" << g[i][j] << "\t";
		} // for inner (j)
		cout << endl; // linebreak after row is printed
	} // for outer (i)

}

void graph::generate(double density) {

	for(int i = 0; i < gSize; i++) {
		for(int j = 0; j < gSize; j++) {
			if(i == j) {
				// do not create any loops in the graph
				g[i][j] = 0;
			} else {
				// use probability function to determine if an
				// edge is created. Create edge with random weight.
				// NOTE: could put this in the first if statement above
				// if(i == j || prob_result >= density) but the segregation
				// allows a quicker change to generate graphs with loops and I think it contributes
				// to readability this way
				if( prob() < density ) {
					// generate a random weight here
					g[i][j] = g[j][i] = (rand() % g_MAXIMAL_WEIGHT) + 1;
				} else {
					// no edge connecting nodes i and j
					g[i][j] = g[j][i] = 0;
				}
			}
		} // for inner (j)
	} // for outer (i)

}

unsigned int graph::getSize(void) {
	return gSize;
}

unsigned int graph::getWeight(unsigned int source, unsigned int destination) {
	// if destination is reachable from source, the adjacency matrix contains a weight
	// value > 0, which is also the cost/distance to reach destination from source 
	return g[source][destination];
}

////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////


