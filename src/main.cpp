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
/// @brief Dijkstra's Algorithm 
/// @param g the graph to operate on
/// @param source the source node from which shortest paths are determined
/// @return a class object dijkstraType holding all information gathered by dijkstra's algorithm
dijkstraType dijkstra(graph& g, unsigned int source);

////////////////////////////////////////////////////
// MAIN FUNCTION
////////////////////////////////////////////////////

int main(void) {

	// seed the random number generator
	srand(time(0));

	// set the source node for dijkstra's algorithm
	unsigned int sourceNode = 0;

	// create a graph g
	graph g(g_GRAPH_SIZE);

	// generate random nodes and edges	
	// could add a function to check if graph is 
	// connected or not...
	g.generate(g_DENSITY);

	// print the adjacency matrix
	g.print();

	// print all shortet paths in the graph
	// from the source node to all other nodes
	for(int i = 0; i < g_GRAPH_SIZE; i++) {
		// set the source node
		sourceNode = i;
		cout << "Running Dijkstra's Algorithm with Source " << sourceNode << endl;
		// run dijkstra's algorithm on the graph and get the result
		dijkstraType dijkstraResult = dijkstra(g, sourceNode);
		// print all shortest paths from the source node to all other nodes
		for(int j = 0; j < g_GRAPH_SIZE; j++) {
			cout << "Shortest Path from source " << sourceNode << " to destination " << j << endl;
			dijkstraResult.getShortestPath(sourceNode, j);
			cout << endl;
		} // for inner (j)
		cout << endl;
	} // for outer (i)

	return 0;

}

////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////

dijkstraType dijkstra(graph& g, unsigned int source) {

	// used to store current node
	unsigned int u = g_UNDEFINED;
	// used to store alternative, possibly shorter paths
	unsigned int alternativePath = g_UNDEFINED;
	// temporary value to hold distance to an adjacent node
	unsigned int distanceNeighbor = g_INFINITY;
	// the list to store nodes in for processing of graph
	list<unsigned int> *q = new list<unsigned int>(0);
	
	// create a new dijkstra type containing distances, predecessors and visited nodes
	// initialization done class internal
	// no predecessors are known, distances are all infinite
	// no nodes are visited and the nodes must be added to the list (open set)
	dijkstraType dij(g.getSize());

	// source is automatically visited, because we start here.
	dij.setDistance(source, 0);

	// initialize the list
	for(int i = 0; i < g.getSize(); i++) {
		q->push_back(i);
	}

	// start dijkstra's algorithm	
	while( !q->empty() ) {

		// get the node stored in the list with the minimal distance
		u = dij.getMinDistance();		
		// set the current node to visited 
		dij.setVisited(u);	
		// remove the node from the list
		q->remove(u);
		
		// check what nodes are reachable from the current node
		list<unsigned int>::iterator it;
		for(it = q->begin(); it != q->end(); ++it) {
			// get the current node from the iterator (is the value of the iterator, hence dereference)
			unsigned int v = *it;
	
			// if a vertex can be reached from u, update the distance
			distanceNeighbor = g.getWeight(u,v);
	
			// if there is an edge to the neighbar
			// if the neighbor was not visited yet
			// if the distance from the source to the neighbor is not infinite (the neighbor can be
			// reached from the source)
			// update the distance value to the neighbor and set the predecessor for the neighbor
			if( distanceNeighbor != g_NOT_REACHABLE && !dij.getVisited(v) && dij.getDistance(u) != g_INFINITY) {
				// calculate the new path to the neighbor
				alternativePath = dij.getDistance(u) + distanceNeighbor;
				// if the new path is shorter than the stored path, set the new values
				if( alternativePath < dij.getDistance(v) ) {
					// set the newly calculated distance value for the node v
					dij.setDistance(v, alternativePath);
					// set node v's predecessor
					dij.setPredecessor(v,u);
				}
			} // if distanceNeighbor
		} // for iterator 	
			
	} // while
	
	// delete the list, as it is not needed anymore
	delete q;	

	// return the result of dijkstra's algorithm as a class object
	return dij;

}

////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////
