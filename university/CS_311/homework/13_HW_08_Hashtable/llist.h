// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW3P1 llist
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		linked list header file llist.h
// 
// INSTRUCTION: 	Llist class - header file template 
// 					You must complete the ** parts and then complete llist.cpp
// 					Don't forget PURPOSE and PARAMETERS 
// ==================================================================

#include "elem.h"

// hw08: el_t is now a class defined in "elem.h"
//typedef char el_t; // alias el_t : element type definition

// a list node is defined here as a struct Node for now
struct Node 
{
	el_t  Elem; // elem is the element stored
	Node *Next; // next is the pointer to the next node
};

// ------------------------------------------------------------------

class llist
{
	protected:
		Node *Front; // pointer to the front node
		Node *Rear;	 // pointer to the rear node
		int   Count; // counter for the number of nodes
		
		void moveTo(int, Node*&); // utility function to move to a specified node position
  
	public:
		// Exception handling classes 
		class Underflow{};  // thrown when a deletion is attempted on an empty list
		class OutOfRange{}; // thrown when the specified Node is out of range
		
		llist (); // constructor to create a list object
		~llist(); // destructor to destroy all nodes
		
		// PURPOSE: indicates whether this list is empty
		// RETURN: true if the list has no elements, false otherwise
		bool isEmpty();
		
		// PURPOSE: displays all elements in this list horizontally in the form [a, b, c, ...]
		void displayAll();
		
		// PURPOSE: adds a new element to the front of this list
		// PARAMETER: the data of the new Node being added to this list
		void addFront(el_t);

		// PURPOSE: adds a new Node to the rear of this list
		// PARAMETER: the data of the new Node being added to this list
		void addRear(el_t);
		
		// PURPOSE: deletes the front element of this list
		// PARAMETER: a reference to the data of the removed element
		void deleteFront(el_t&);
		
		// PURPOSE: deletes the rear element of this list
		// PARAMETER: a reference to the data of the removed element
		void deleteRear(el_t&);
		    
		// PURPOSE: deletes an element at the indicated position
		// PARAMETER: the index of the element to be removed
		// PARAMETER: a reference to the data of the removed element
		void deleteIth(int, el_t&);	// calls moveTo

		// PURPOSE: inserts an element at the indicated position
		// PARAMETER: the index at which the new element will be inserted
		// PARAMETER: the data of the new element
		void insertIth(int, el_t);	// calls moveTo
		
		// PURPOSE: copy constructor to allow pass by value and return by value of a llist
		// PARAMETER: the llist to be copied
		llist(const llist&);
		  
		// PURPOSE: overloading of = operator
		// PARAMETER: the llist to be copied
		// RETURN: a reference to a llist
		llist& operator=(const llist&); 

}; // end of class llist.h

