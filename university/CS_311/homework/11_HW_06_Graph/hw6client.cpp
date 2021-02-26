// ==================================================================
// CS311 Yoshii - HW6 Client file
// 
// HW#: 			HW6 dgraph client 
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		graph client program hw6client.cpp (tester)
// 
// INSTRUCTION: 	Complete this file and comment using How to Comment file.
// ==================================================================
// PURPOSE: 		This client program will demonstrate the directed graph
//				"dgraph.h" implementation. 
//
// ALGORITHM: 		1. Use dgraph functions to:
//						a. READ file name to fill vertex array
//						b. PRINT a formatted representation of this graph
//					2. WHILE true, or until the user enters control-C to exit
//						a. PRINT "Enter a vertex name..."
//						b. READ the vertex name in this graph
//						c. PRINT degree of this vertex    (throws BadVertex)
//						d. PRINT adjacency of this vertex (throws BadVertex)
//						CATCH BadVertex, PRINT "... vertex... not found."
// ==================================================================

#include "dgraph.h"

using namespace std;

int main()
{ 
	dgraph graph; // graph object
	char vertex;  // vertex name from input
	
	graph.fillTable();    // use input file to fill the vertex array
	graph.displayGraph(); // format display of the graph 
	
	while (true) // until user forces program to end
	{
		cout << "Enter a vertex name or control-C to exit: ";
		cin >> vertex; // user specifies which vertex
		
		try 
		{
			// get degree of the vertex and display the result
			cout << graph.findOutDegree(vertex) << " edges come out to:" << endl; 
				
			// get adjacency list of the vertex and display the result (see Hint)
			graph.findAdjacency(vertex).displayAll();
		}
		catch (dgraph::BadVertex) // thrown by dgraph's findOutDegree and findAdjacency
		{
			cout << "ERROR BadVertex: dgraph vertex " << vertex << " not found." << endl;
		}
	}
	
} // end of main

/*
Hint:
slist l1; l1 = G.findAdjacency('a');
// how do you display l1?  Hint: it is an slist from HW3.
*/

