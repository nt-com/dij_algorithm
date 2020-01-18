////////////////////////////////////////////////////
// DijkstraType - Configuration File
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

/// @file dij_cfg.h
/// @brief contains the configuration for dijkstra's algorithm

#ifndef _DIJ_CFG_H_
#define _DIJ_CFG_H_

#include <climits>

////////////////////////////////////////////////////
// GLOBAL CONSTANTS
////////////////////////////////////////////////////

/// @brief placeholder for the infinity value
const unsigned int 	g_INFINITY = UINT_MAX;
/// @brief placeholder for the undefined value
const unsigned int 	g_UNDEFINED = UINT_MAX-1;
/// @brief placeholder for when a node is not reachable from another
const unsigned int g_NOT_REACHABLE = 0;

////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////
#endif
