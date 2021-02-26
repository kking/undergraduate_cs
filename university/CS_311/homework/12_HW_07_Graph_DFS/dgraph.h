// ==================================================================
// CS311 Yoshii - dgraph.h that uses slist.h
// 
// HW#: 			HW7 DFS client using dgraph.h
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		graph class header file dgraph.h
// 
// INSTRUCTION: 	You need to comment this file completely
//				using the How to Comment file.
//				You have seen many examples so far.
//				We will check to see how well you have commented it.
// ==================================================================

#include <iostream>
#include "slist.h"
using namespace std;

// GLOBAL ALIAS -----------------------------------
const int SIZE = 20; // the size of the graph table

// this will be in each GTable slot
struct Gvertex
{
	char  vertexName;   // the vertex Name
	int   outDegree;    // the Out degree; number of edges coming out
	slist adjacentOnes; // the adjecent vertices in an slist
	int   visit;        // This will hold the visit number in HW7 
};

class dgraph // a directed graph class
{
	private:
		Gvertex Gtable[SIZE]; // an array of vertices; a table representing the dgraph
		int     countUsed;    // how many slots of the Gtable are actually used

	public:
		// PURPOSE: class thrown when the vertex is not in the graph
		class BadVertex {};
		
		// PURPOSE: constructor initializes the vertex name and visit numbers to defaults
		// initialize vertexName (blank) and visit numbers (0)
		// initialize countUsed to be 0
		dgraph();   
		
		// PURPOSE: destructor deletes all nodes of slists in the table
		// do we have to delete all nodes of slists in table??
		// Question: If we do not do this, will the llist destructor
		// be called automatically??? Try it.
		~dgraph();   
		
		// PURPOSE: reads a specified file to create each vertex with its adjacencies
		// read from the input file and fill GTable
		void fillTable();  
		
		// PURPOSE: displays in an easy to read table format 
		void displayGraph(); 
		
		// PURPOSE: returns the out degrees according to the given vertex name
		// PARAMETER: the name of a vertex in this graph
		// RETURN: the number of out degrees of the given vertex
		// THROWS: BadVertex if V is not a vertex name in this graph
		int findOutDegree(char);  
		
		// PURPOSE: returns the adjacency list according to the given vertex name
		// PARAMETER: the name of a vertex in this graph
		// RETURN: the slist representing the adjacencies of the given vertex
		// THROWS: BadVertex if V is not a vertex name in this graph
		slist findAdjacency(char); 
		
		// PURPOSE: enters the given visit number for a given vertex; indicates the
		// order in which vertices were visited.
		// PARAMETER: the visit number
		// PARAMETER: a vertex
		// THROWS: BadVertex if V is not a vertex name in this graph
		void visit(int, char);
		
		// PURPOSE: indicates the given vertex has been visited
		// PARAMETER: a vertex
		// RETURN: true if the vertex was already visited, otherwise false
		// THROWS: BadVertex if V is not a vertex name in this graph
		bool isMarked(char);

}; // end of dgraph.h

