// ==================================================================
// CS311 Yoshii - HW7 Client file
// 
// HW#: 			HW7 DFS client using dgraph.h
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		client hw7client.cpp 
// 
// INSTRUCTION: 	Complete this file and comment using How to Comment file.
// ==================================================================
// PURPOSE: 		This client uses the dgraph class and stack class
//				to do depth first traversal of the graph stored in table.txt
//
// ALGORITHM: 		1. PRINT the graph before DFS begins
//					2. Push A onto the stack
//					3. WHILE the stack is not empty:
//						a. Remove a vertex V from the stack
//						b. PRINT the vertex name, e.g. "Removed V from stack"
//						c. IF V is not yet marked:
//							i.   Mark/visit V
//							ii.  PRINT a message, e.g. "Visit V as 2"
//							iii. Get V's adjacency list
//							iv.  IF no adjacencies, PRINT "Deadend reached - backing up"
//							v.   ELSE put adjacencies on the stack (delete from the rear 
//							     and push) and PRINT a message
//						d. ELSE PRINT a message, e.g. "V has been visited - backing up"
//						e. PRINT the stack, labeling it as the current stack
//					4. PRINT the formatted graph, with visit numbers for all vertices
// ==================================================================

#include "stack.h" // ** Be sure to include dgraph, slist and stack
#include "dgraph.h"

using namespace std;

int main()
{
	stack vStack; // stack for vertices used in DFS
	slist aList;  // adjacency list for a vertex
	dgraph graph; // graph object
	char vertex;  // vertex name popped from stack
	int visitNum = 0; // the visit number for a vertex
	
	graph.fillTable();
	graph.displayGraph(); // Print the graph before DFS begins
	
	vStack.push('A'); // Push A onto the stack
	
	while (!vStack.isEmpty()) // while the stack is not empty:
	{
		vStack.pop(vertex); // Remove a vertex V from the stack
		cout <<  "Removed " << vertex << " from stack\n"; // Print the vertex name
		
		if (!graph.isMarked(vertex)) // if the vertex is not yet marked:
		{
			graph.visit(++visitNum, vertex); // Mark/visit vertex
			cout << "Visit " << vertex << " as " << visitNum << endl;
			
			aList = graph.findAdjacency(vertex); // Get vertex's adjacency list
			
			if (aList.isEmpty()) // if no adjacencies exist:
			{
				cout << "Deadend reached - backup.\n";
			}
			else 
			{
				cout << "...pushing ";
				aList.displayAll();
				
				// put adjacencies on the stack
				while (!aList.isEmpty())
				{
					aList.deleteRear(vertex);
					vStack.push(vertex);
				}
			}
		}
		else 
		{
			cout << vertex << " had been visited already - backup.\n";
		}
		
		vStack.displayAll(); // Print the current stack
	}

	graph.displayGraph(); // Print the formatted graph

} // end of main

