// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW3P2 slist
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		header file slist.h
// 
// INSTRUCTION: 	Inherit everything publicly from llist
// 					Put only the following in class slist.h 
// 					inheriting everything from llist.h
// 					Then create slist.cpp with only the following functions
// 					Complete all ** parts 
// ==================================================================

// includes
#include "llist.h"

class slist : public llist // slist inherits publicly from llist
{
	public:
		// PURPOSE: slist constructor
		// to cout "in slist constructor".
		// Make it do nothing else.
		// Experiment and see what happens.
		// Taking this out completely would not work.
		// But note that there is no destructor.
		// PLEASE DO NOT delete the couts in slist and llist
		// constructors and destructors for HW6!!!!!
		slist();
		
		// PURPOSE: search through the list to see if any node contains the key.
		// PARAMETER: the key to search
		// RETURNS: the position (>=1) if a node is found, 0 otherwise
		int search(el_t);
		 
		// PURPOSE: go to the Ith node (if I is between 1 and Count) 
		// and replace the element there with the new element. 
		// PARAMETER: the element replacing the indicated element
		// PARAMETER: the index of the element to be replaced
		// THROWS OutOfRange: if I was an illegal value
		void replace(el_t, int);

		// PURPOSE: checks to see of the two lists look the same
		// PARAMETER: another slist
		// RETURNS: true if the two lists are identical, false otherwise
		bool operator==(const slist&);

}; // end of class slist

