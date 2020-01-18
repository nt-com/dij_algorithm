////////////////////////////////////////////////////
// DijkstraType - C++ file
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////
#include "dij.h"

////////////////////////////////////////////////////
// METHODS
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// PRIVATE METHODS
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// PUBLIC METHODS
////////////////////////////////////////////////////

dijkstraType::dijkstraType(unsigned int size) {

	dSize = size;
	// memory allocation
	predecessor = new unsigned int[dSize];
	distance = new unsigned int[dSize];	
	visited = new bool[dSize];
	
	for(int i = 0; i < dSize; i++) {
		// there are no defined predecessor values yet,
		// so set them to the undefined placeholder
		predecessor[i] = g_UNDEFINED;
		// the distance to all nodes is infinity at 
		// initialization, so set to the placeholder value
		distance[i] = g_INFINITY;
		// no node has been visited yet, so visited is false for
		// all nodes...
		visited[i] = false;
	}

}

dijkstraType::~dijkstraType() {
	delete [] predecessor;
	delete [] distance;
	delete [] visited;
}

unsigned int dijkstraType::getMinDistance(void) {

	unsigned int minDistance = g_INFINITY;
	unsigned int minDistanceNode = g_UNDEFINED;

	for(int i = 0; i < dSize; i++) {
		// if we haven't yet visited the current node
		if( !visited[i] ) {
			// check if it's distance value is minimal,
			// if yes, return that node at the end of 
			// the distance computation
			if( distance[i] <= minDistance ) {
				minDistance = distance[i];
				minDistanceNode = i;	
			}
		}
	}

	return minDistanceNode;

}

void dijkstraType::setDistance(unsigned int node, unsigned int dist) {
	distance[node] = dist;
}
void dijkstraType::setPredecessor(unsigned int node, unsigned int pre) {
	predecessor[node] = pre;
}
void dijkstraType::setVisited(unsigned int node) {
	visited[node] = true;
}
bool dijkstraType::getVisited(unsigned int node) {
	return visited[node];
}

unsigned int dijkstraType::getDistance(unsigned int node) {
	return distance[node];
}

void dijkstraType::getShortestPath(unsigned int source, unsigned int destination) {

	unsigned int currentNode = destination;
	unsigned int path[dSize] = { 0x00 };
	unsigned int index = 0;
		
		if(source == destination) {
			cout << "source == destination" << endl;
			return;
		} 

		// if the distance to the destination node is not infinite
		// it can be reached from the source, thus we can print a path
		if(distance[destination] != g_INFINITY) {

			// try to get a path from destination to source
			while(currentNode != source) {
				path[index] = currentNode;	
				currentNode = predecessor[currentNode];
				index++;
			}

		} else {
			// when the destination node can't be reached from the source
			cout << "no path from " << source << " to " << destination << endl;
			return;
		}

	// if a path was found print it 
	// NOTE: the printing can be done above, but you may want to return an array with the 
	// shortest path in it instead and print it externally, that's why I segregated the two things.
	// Currently the function does not return an array, thus this would be a future addition
	// omitted in this implementation.
	for(int i = 0; i < index; i++) {
		cout << path[i] << " -> ";
	}
	cout << "[" << source << "]" << " | distance: " << distance[destination] << endl;

}

void dijkstraType::printData(void) {
	
	cout << "Predecessors: " << endl;
	for(int i = 0; i < dSize; i++) {
		cout << "Predecessor of " << i << " is " << predecessor[i] << endl;
	} // for outer (j)

	cout << "Distances: " << endl;
	for(int i = 0; i < dSize; i++) {
		for(int j = 0; j < dSize; j++) {
				cout << "Distance from " << i << " to " << j << " is: " << distance[j] << endl;
		} // for inner (j)
	} // for outer (j)

}
