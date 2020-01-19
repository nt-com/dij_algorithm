////////////////////////////////////////////////////
// Graph Data Structure - Header File
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

/// @file graph.h
/// @brief contains the graph data structure and operations

#ifndef _GRAPH_H_
#define _GRAPH_H_

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////
#include <iostream>
#include <ctime>
#include "graph_cfg.h"

// NAMESPACE
using namespace std;

////////////////////////////////////////////////////
// CLASSES
////////////////////////////////////////////////////

/// GRAPH CLASS
/// contains the graph in adjacency matrix representation and a probability function
/// to generate a random graph. Further, public methods are included to operate on the
/// graph, for example random graph generation
class graph {

	private:
		/// holds the graph data structure
		unsigned int **g;
		/// the size of the graph, the number of nodes it contains
		unsigned int gSize;	
		/// the probability function to generate the a random graph with
		/// @return a probability value in range [0..1]
		double prob(void);

	public:

		/// @brief constructor
		/// @param size the number of nodes in the graph
		graph(unsigned int size);
		/// destructor
		~graph();

		/// @brief prints the adjacency matrix of the graph
		/// @return void
		void print(void);

		/// @brief generates a random graph
		/// @param density the density value to use for generating the graph
		/// @return void
		void generate(double density, unsigned int distanceMin, unsigned int distanceMax);

		/// @brief accessor method, returns the size (number of nodes) of the graph
		/// @return the number of nodes in the graph
		unsigned int getSize(void);

		/// @brief checks if destination is reachable from source
		/// @param source the source node
		/// @param destination the destination node	
		/// @return weight of the edge between source and destination, 0 if no edge exists
		unsigned int getWeight(unsigned int source, unsigned int destination);

};


////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////
#endif
