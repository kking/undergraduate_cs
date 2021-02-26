// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW3P1 slist (inheriting from llist)
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		slist.cpp implementation file
// 
// INSTRUCTION: 	Complete all functions with their comments
// ==================================================================

using namespace std;

#include "slist.h" 
#include <iostream>

// ** Make sure llist constructor and destructors have couts in them

// PURPOSE: slist constructor
slist::slist() { 
	//cout << "slist constructor: " << endl;
}

// positions always start at 1

// PURPOSE: search through the list to see if any node contains the key.
// PARAMETER search: the key to search
// RETURNS: the position (>=1) if a node is found, 0 otherwise
int slist::search(el_t key) {
	int position = 1;
	Node *thisP = this->Front;
	
	while (thisP->Next != NULL) {
		if (thisP->Elem == key) {
			return position;
		}
		else {
			thisP = thisP->Next;
			position++;
		}
	}
	
	return (thisP->Elem == key) ? position : 0;
}

// PURPOSE: go to the Ith node (if I is between 1 and Count) 
// and replace the element there with the new element. 
// PARAMETER element: the element replacing the indicated element
// PARAMETER I: the index of the element to be replaced
// THROWS OutOfRange: if I was an illegal value
void slist::replace(el_t element, int I) {
	if (I < 1 || I > Count) {
		throw OutOfRange(); // error case: I is an illegal value, throw an exception
	}
	else {
		Node *el = this->Front;
		moveTo(I, el);
		el->Elem = element;
	}
} 

// PURPOSE: checks to see of the two lists look the same
// PARAMETER OtherOne: another slist
// RETURNS: true if the two lists are identical, false otherwise
bool slist::operator==(const slist& OtherOne) {
	if (OtherOne.Count != this->Count) {
		return false; // if not the same length, return false
	}
	else {
		// if the same lengths,
		// check each node to see if the elements are the same
		Node *thisP = this->Front;
		Node *otherP = OtherOne.Front;
		
		while (thisP != NULL) {
			if (thisP->Elem != otherP->Elem) {
				return false;
			}
			thisP = thisP->Next;
			otherP = otherP->Next;
		}
		return true;
	}
}

// end of class implementation slist.cpp

