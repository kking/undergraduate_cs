// ==================================================================
// CS311 Yoshii - dgraph.cpp 
// 
// HW#: 			HW7 DFS client using dgraph.h
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		graph class implementation dgraph.cpp
// 
// INSTRUCTION: 	Complete all the functions you listed in dgraph.h
//			Comment the file completely using How to Comment file.
//			Use HW6-help.docx to finish the functions.
// ==================================================================

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

// PURPOSE: constructor initializes the vertex name and visit numbers to defaults
dgraph::dgraph() 
{
	// initialize vertexName (blank) and visit numbers (0)
	for (int i = 0; i < SIZE; i++) {
		Gtable[i].vertexName = ' ';
		Gtable[i].visit = 0;
	}
	countUsed = 0; // initialize countUsed to be 0
}

// PURPOSE: destructor deletes all nodes of slists in the table
dgraph::~dgraph()   
{
	// do we have to delete all nodes of slists in table??
	// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
}

// PURPOSE: reads a specified file to create each vertex with its adjacencies
void dgraph::fillTable()  // be sure to read from a specified file
{
	string fname;
	int oDegrees;
	char vertexName;
	
	cout << "Enter a file name: ";
	cin >> fname;
	ifstream fin(fname.c_str(), ios::in); // declare and open fname
	
	// the rest is in HW6-help:
	while (fin >> Gtable[countUsed].vertexName) // if the name can be read
	{
		fin >> oDegrees;
		Gtable[countUsed].outDegree = oDegrees;
		
		for (int i = 0; i < oDegrees; i++) 
		{
			fin >> vertexName;
			(Gtable[countUsed].adjacentOnes).addRear(vertexName); // slist function
		}
		countUsed++;
	}
	
	fin.close(); // close stream fname
}

// PURPOSE: dislays the graph's verticies in a table format and the number of edges
void dgraph::displayGraph() 
{
	int edges = 0;
	for (int i = 0; i < countUsed; i++) {
		edges += Gtable[i].outDegree;
	}
	
	// be sure to display in a really nice table format -- all columns but no unused 
	// rows and include the number of edges at the top 
	cout << "** The number of edges is: " << edges << endl;
	cout << "  Out Visit Adj" << endl;
	cout << " -----------------------" << endl;
	for (int i = 0; i < countUsed; i++) {
		cout << Gtable[i].vertexName << " ";
		cout << Gtable[i].outDegree << "     ";
		cout << Gtable[i].visit << " ";
		Gtable[i].adjacentOnes.displayAll();
	}
}

// PURPOSE: returns the out degrees according to the given vertex name
// PARAMETER V: the name of a vertex in this graph
// RETURN: the number of out degrees of the given vertex
// THROWS: BadVertex if V is not a vertex name in this graph
int dgraph::findOutDegree(char V)
{
	// does not use a loop
	int vIndex = V - 65;
	if (vIndex < 0 || vIndex >= countUsed) {
		throw BadVertex();
	}
	return Gtable[vIndex].outDegree;
}

// PURPOSE: returns the adjacency list according to the given vertex name
// PARAMETER V: the name of a vertex in this graph
// RETURN: the slist representing the adjacencies of the given vertex
// THROWS: BadVertex if V is not a vertex name in this graph
slist dgraph::findAdjacency(char V)
{
	// does not use a loop
	int vIndex = V - 65;
	if (vIndex < 0 || vIndex >= countUsed) {
		throw BadVertex();
	}
	return Gtable[vIndex].adjacentOnes;
}

// PURPOSE: enters the given visit number for a given vertex; indicates the
// order in which vertices were visited.
// PARAMETER visitNum: the visit number
// PARAMETER V: a vertex
// THROWS: BadVertex if V is not a vertex name in this graph
void dgraph::visit(int visitNum, char V)
{
	// does not use a loop
	int vIndex = V - 65;
	if (vIndex < 0 || vIndex >= countUsed) {
		throw BadVertex();
	}
	Gtable[vIndex].visit = visitNum;
}
		
// PURPOSE: indicates the given vertex has been visited
// PARAMETER V: a vertex
// RETURN: true if the vertex was already visited, otherwise false
// THROWS: BadVertex if V is not a vertex name in this graph
bool dgraph::isMarked(char V) 
{
	// does not use a loop
	int vIndex = V - 65;
	if (vIndex < 0 || vIndex >= countUsed) {
		throw BadVertex();
	}
	return (Gtable[vIndex].visit != 0);
}

// end of dgraph.cpp

