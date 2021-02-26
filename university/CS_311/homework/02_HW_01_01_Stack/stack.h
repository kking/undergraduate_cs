// ==================================================================
// CS311 Yoshii
//
// INSTRUCTION:	Stack class header file template based on Notes-1
// 				You must complete the ** parts and then complete stack.cpp
// 				Must add good comments for each function - See Notes1B
// EMACS HINT:	Control-S does searches
// 				Tab on each line will indent perfectly for C++
// ==================================================================
// HW#:			HW1P1 stack
// NAME:		King
// COMPILER:	g++
// FILE TYPE:	header file stack.h
// ==================================================================

// Global aliases:

const int MAX = 10; // The MAX number of elements for the stack; MAX is unknown to the client

typedef int el_t; // typedef is int for now; el_t is unknown to the client

class stack { 
	private: // hidden from the client
  		el_t	el[MAX];	// an array of el_t's
		int		top;		// index to the top of stack
		
	public:	// available to the client
		// exception handling classes
		class Overflow {}; // empty class - used as an exception name only
		class Underflow {};
  	
		// prototypes to be used by the client
		// note that no parameter variables are given
		stack();   // constructor to create an object
		~stack();  // destructor  to destroy an object
  	
		// PURPOSE: if not full, enters an element at the top;
		//          otherwise throws an exception - Overflow
		// PARAMETER: pass the element to be pushed
		void push(el_t);
		  
		// PURPOSE: if not empty, removes and gives back the top element;
		//          otherwise throws an exception - Underflow
		// PARAMETER: provide variable to receive the popped element (by ref)
		void pop(el_t&);
		  
		// PURPOSE: if not empty, gives the top element without removing it;
		//          otherwise, throws an exception - Underflow
		// PARAMETER:	provide a holder (elem) for the element (pass by ref)
		void topElem(el_t&);
		
		// PURPOSE:	checks top and returns true if empty, false otherwise.
		bool isEmpty();
		
		// PURPOSE:	checks top and returns true if full, false otherwise.
		bool isFull();
		
		// PURPOSE:	dislayAll calls isEmpty and if true, displays [ empty ].
		// 			Otherwise, diplays the elements vertically, with the last added
		// 			element on top.
		void displayAll();
		
		// PURPOSE:	pops all elements from the stack until it is empty 
		void clearIt();
  
}; // end of stack.h

