////////////////////////////////////////////////////
// Graph Data Structure - Configuration File
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

/// @file graph_cfg.h
/// @brief contains the configuration for the graph data structure

#ifndef _GRAPH_CFG_H_
#define _GRAPH_CFG_H_

////////////////////////////////////////////////////
// GLOBAL CONSTANTS
////////////////////////////////////////////////////

/// @brief maximal weight an edge can have
const unsigned int 	g_MAXIMAL_WEIGHT = 12;
/// @brief the graph density
const double 		g_DENSITY = 0.25;
/// @brief the number of nodes in the graph (for graph generation)
const unsigned int 	g_GRAPH_SIZE = 5;

////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////
#endif
