////////////////////////////////////////////////////
// Dijkstra's Algorithm - Main File
// NOTE: 	compiled with g++ under Linux
//				no memory leaks detected by valgrind
////////////////////////////////////////////////////

/// @file main.cpp
/// @brief the main file, contains dijkstra's algorithm

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include "graph.h"
#include "dij.h"

// NAMESPACE
using namespace std;

////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// MAIN FUNCTION
////////////////////////////////////////////////////

int main(void) {

	// seed the random number generator
	srand(time(0));

	// set the source node for dijkstra's algorithm
	unsigned int sourceNode = 0;

	// average distance from a source node to all other nodes
	double averageDistance = 0.0;
	// current distance value for accumulation
	unsigned int currentDistance = 0;

	// create a graph g
	graph g(g_GRAPH_SIZE);

	// generate random nodes and edges	
	// the parameters are defined in graph_cfg.h
	g.generate(g_DENSITY, g_MINIMAL_WEIGHT, g_MAXIMAL_WEIGHT);

	// print the adjacency matrix if you want here
	g.print();

	// create an object for dijkstra's algorithm
	dijkstraType dij(g_GRAPH_SIZE);

	for(int i = 0; i < g_GRAPH_SIZE; i++) {
		// from the source node to all other nodes
		cout << "Running Dijkstra's Algorithm with Source " << sourceNode << endl;
		// run dijkstra's algorithm on the graph and get the result
		dij.dijkstra(g, sourceNode);
		// print all shortest paths from the source node to all other nodes
		for(int j = 0; j < g_GRAPH_SIZE; j++) {
			cout << "Shortest Path from source " << sourceNode << " to destination " << j << endl;
			currentDistance = dij.getShortestPath(sourceNode, j);
			averageDistance += static_cast<double>(currentDistance);
			cout << endl;
		} // for (j)

		averageDistance = averageDistance / static_cast<double>(g_GRAPH_SIZE);
		cout << "The calculated average distance is: " << averageDistance << endl;
		sourceNode++;

	} // for(i)

		return 0;

}
////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////
