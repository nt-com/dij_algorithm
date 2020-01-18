////////////////////////////////////////////////////
// DijkstraType - Header File
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

/// @file dij.h
/// @brief contains everything related to dijkstra's algorithm

#ifndef _DIJ_H_
#define _DIJ_H_

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////
#include <iostream>
#include <list>
#include "graph.h"
#include "dij_cfg.h"

// NAMESPACE
using namespace std;

////////////////////////////////////////////////////
// CLASSES
////////////////////////////////////////////////////

/// DIJKSTRA CLASS
/// contains data for dijkstra's algorithm and functions
/// to operate on the data. I chose to make this a seperate class 
/// instead of using arrays in dijkstra's algorithm so the data
/// is stored for future use and arrays do not have to be returned.
class dijkstraType {

	private:
		/// the number of nodes in the graph dijkstra's algorithm is applied to
		unsigned int dSize;
		/// the predecessors of the nodes in the graph, filled in by dijkstra's algorithm
		unsigned int *predecessor;
		/// the distance values between the source and the rest of the nodes
		unsigned int *distance;
		/// the nodes marked visited by dijkstra's algorithm
		bool *visited;
	public:
		/// constructor
		/// @param size the number of nodes of the graph
		dijkstraType(unsigned int size);
		/// destructor
		~dijkstraType();

		/// @brief used by dijkstra's algorithm to find the node with the minimal distance 
		/// to the current node
		/// @param void
		/// @return the node with the minimal distance to the current node
		unsigned int getMinDistance(void);

		/// @brief sets a distance for a node
		/// @param node the node to set the distance for
		/// @param dist the distance value to set
		/// @return void
		void setDistance(unsigned int node, unsigned int dist);

		/// @brief sets a predecessor for a node
		/// @param node the node to set a predecessor for
		/// @param pre the predecessor to set
		/// @return void
		void setPredecessor(unsigned int node, unsigned int pre);
		
		/// @brief marks a node as visited
		/// @param node the node to mark as visited
		/// @return void
		void setVisited(unsigned int node);

		/// @brief checks if a node was already visited or not
		/// @param node the node to check
		/// @return true if already visited, false if not
		bool getVisited(unsigned int node);

		/// @brief returns the distance value of a node
		/// @param node the node to return the distance value of
		/// @return the distance value
		unsigned int getDistance(unsigned int node);

		/// @brief prints the shortest path between a source and a destination node
		/// @param source the source node
		/// @param destination the destination node
		void getShortestPath(unsigned int source, unsigned int destination);

		/// @brief prints the internal data of this class after dijkstra's algorithm is finished
		/// mainly for debugging and traceability
		/// @return void
		void printData(void);

};

////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////
#endif
