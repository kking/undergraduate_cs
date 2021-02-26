// ==================================================================
// CS311 Yoshii Linked List class
// 
// HW#: 			HW3P1 llist
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		llist.cpp implementation file
// 
// INSTRUCTION: 	Must use the provided HW3P1_help.doc to create llist.cpp
// 					It helps to first create if-then-else structure to fill in later.
// 					- Make sure PURPOSE and PARAMETER comments are given in detail
// 					- Make sure all if-then-else are commented describing which case it is
// 					- Make sure all local variables are described fully with their purposes
// 					
// EMACS HINT: 		You can copy from a Word document to emacs (contrl-right click)
// 					cntr-K cuts and cntr-Y pastes
// 					Esc x replace-str does string replacements
// 					Esc > goes to the end of the file; Esc < to the beginning
// 					Tab on each line will indent perfectly for C++			
// ==================================================================

using namespace std;

#include<iostream>
#include"llist.h" 

// PURPOSE: constructor to create a list object and initialize its members
llist::llist() { 
	cout << "calling the llist constructor...\n"; 
	Front = NULL; // Front points to NULL
	Rear = NULL; // Rear points to NULL
	Count = 0;
}

// PURPOSE: destructor to destroy this list by deleting all nodes (in heap)
llist::~llist() { 
	cout << "calling the llist destructor...\n";
	el_t temp;
	while (!isEmpty()) {
		deleteFront(temp); // delete front node until this list is empty
	}
}

// PURPOSE: indicates whether this list is empty
// RETURN: true if this list has no elements, false otherwise
bool llist::isEmpty() {
	// return true if Front and Rear are both pointing to NULL and Count is 0.
	return (Front == NULL) && (Rear == NULL) && (Count == 0); 
}

// PURPOSE: displays all elements in this list horizontally in the form [ a b c ... ]
void llist::displayAll() { 
	if (isEmpty()) {
		// special case: the list is empty
		cout << "[empty]\n"; 
	}
	else {
		// regular case: traverse list to print each element's value
		cout << "[";
		Node *element = Front;
		
		while (element != NULL) {
			cout << element->Elem << " ";
			element = element->Next;
		}
		cout << "]\n";
	}
	//cout << "Count: " << Count << endl;
}  
  
// PURPOSE: adds a new Node to the rear of this list
// PARAMETER NewNum: the data of the new Node being added to this list
void llist::addRear(el_t NewNum) { 
	if (isEmpty()) {
		// special case: new element is the first node added to this list
		Node *newRear = new Node;	// pointer to a new Node
		Front = newRear;			// Front and
		Rear = newRear;				// Rear points to new Node
		Rear->Elem = NewNum;		// Rear data set to NewNum
		Rear->Next = NULL;
	}
	else {
		// regular case: add a new node with NumNum data at the rear
		Rear->Next = new Node; 		// Rear points to a new Node
		Rear = Rear->Next;			// Rear points to next element
		Rear->Elem = NewNum;		// Rear data set to NewNum
		Rear->Next = NULL;
	}
	Count++; // increment Count
}

// PURPOSE: adds a new element to the front of this list
// PARAMETER NewNum: the data of the new Node being added to this list
void llist::addFront(el_t NewNum) {
	if (isEmpty()) {
		// special case: new element is the first node added to this list
		Node *newFront = new Node;	// pointer to a new Node
		Front = newFront;			// Front and
		Rear = newFront;			// Rear points to new Node
		Rear->Elem = NewNum;		// Rear data set to NewNum
		Rear->Next = NULL;
	}
	else {
		// regular case: add a new node at the front
		Node *newFront = new Node;	// pointer to a new Node
		newFront->Next = Front;		// new front points to current front
		Front = newFront;			// Front points to new Node
		Front->Elem = NewNum;
	}
	Count++; // increment count
}

// PURPOSE: deletes the front element of this list
// PARAMETER OldNum: a reference to the data of the removed element
void llist::deleteFront(el_t& OldNum) { 
	if (isEmpty()) {
		// error case: if the list is empty, throw an exception
		throw Underflow();
	}
	else if (Front->Next == NULL) {
		// special case: removal will make this list empty
		OldNum = Front->Elem; // pass front node element by reference
		delete Front; // remove the front node
		Front = NULL;
		Rear = NULL;
	}
	else {
		// regular case: remove the front node
		OldNum = Front->Elem;	// pass front node element by reference
		Node *newFront;			// pointer to new front
		newFront = Front->Next;	// new front points to second element
		delete Front;			// delete the old front node
		Front = newFront;
	}
	Count--; // decrement Count
}

// PURPOSE: deletes the rear element of this list
// PARAMETER OldNum: a reference to the data of the removed element
void llist::deleteRear(el_t& OldNum) {
	if (isEmpty()) {
		throw Underflow(); // error case: if the list is empty, throw an exception
	}
	else if (Front->Next == NULL) {
		// special case: removal will make this list empty
		OldNum = Rear->Elem; // pass front node element by reference
		delete Rear; // delete the rear node
		Front = NULL;
		Rear = NULL;
	}
	else {
		// regular case: remove the rear node
		OldNum = Rear->Elem; // pass front node element by reference
	
		Node *newRear = Front; // pointer for new rear
		moveTo((Count-1), newRear); // use helper function to move newRear
		
		newRear->Next = NULL;
		delete Rear; // delete the old rear node
		Rear = newRear;
	}
	Count--; // decrement Count
}

/* harder ones follow */

// PURPOSE: Utility Function to move a local pointer to the Jth node
// PARAMETER J: the index to which the local pointer is moved
// PARAMETER temp: the local pointer to be moved
void llist::moveTo(int J, Node*& temp) { 
	// moves temp J-1 times to go to the Jth node
	for (int K = 1; K <= J-1; K++) {
		temp = temp->Next;
	}
}

// PURPOSE: deletes an element at the indicated position
// PARAMETER I: the index of the element to be removed
// PARAMETER OldNum: a reference to the data of the removed element
void llist::deleteIth(int I, el_t& OldNum) { 
	if (I > Count || I < 1) {
		throw OutOfRange(); // error case: if I is an illegal value, throw an exception
	}
	else if (I == 1) {
		deleteFront(OldNum); // special case: front element to be removed
	}
	else if (I == Count) {
		deleteRear(OldNum); // special case: rear element to be removed
	}
	else {
		// regular case: delete Ith node (I starts at 1)
		// consider the visual:
		// [first]-->[prev]-->[del]-->[del.Next]-->[...]-->
		Node *prev = Front;
		moveTo(I-1, prev); // use helper function to move prev to I-1th position
		
		Node *del = prev->Next; // point del to next element
		prev->Next = del->Next; // point prev's Next to del's Next
		
		OldNum = del->Elem; // retrieve del's value to return
		delete del;
		Count--; // decrement Count
	}
}

// PURPOSE: inserts an element at the indicated position
// PARAMETER I: the index at which the new element will be inserted
// PARAMETER newNum: the data of the new element
void llist::insertIth(int I, el_t newNum) { 
	if (I > Count+1 || I < 1) {
		throw OutOfRange(); // error case: I is an illegal value, throw an exception
	}
	else if (I == 1) {
		addFront(newNum); // special case: add element to front
	}
	else if (I == Count+1) {
		addRear(newNum); // special case: add element to rear
	}
	else {
		// regular case: add element right before the Ith node
		// consider the visual:
		// [first]-->[prev]-->[newNode]-->[after]-->[...]-->
		Node *prev = Front;
		moveTo(I-1, prev); // use helper function to move prev to I-1th position
		
		Node *after = Front;
		moveTo(I, after); // use helper function to move after to Ith position
		
		Node* newNode = new Node;
		newNode->Elem = newNum;
		newNode->Next = after; // point newNode's Next to after
		
		prev->Next = newNode; // point prev's Next to newNode
		Count++; // increment Count
	}
}

// PURPOSE: copy constructor to allow pass by value and return by value of a llist
// PARAMETER Original: the llist to be copied 
llist::llist(const llist& Original) { 
	// use provided code
	// Note that the Original is being passed to the constructor by reference
	// to create a new object this-> as a copy of the Original
	Front = NULL; // initialize this-> data members
	Rear = NULL;
	Count = 0;
	
	// this-> object has to be built by allocating new cells and copying the values
	// from Original into each cell as it was done with operator=
	Node* P = Original.Front; // local pointer for Original
	while (P != NULL) {
		this->addRear(P->Elem);
		P = P->Next;
	}
	// Nothing to return since this is a constructor
}

// PURPOSE: overloading of = operator
// PARAMETER OtherOne: the llist to be copied
// RETURN: a reference to a llist
llist& llist::operator=(const llist& OtherOne) { 
	// use provided code
	el_t x;
	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects.
	if (&OtherOne != this) {
		// this-> object has to be emptied first.
		while (!this->isEmpty()) {
			this->deleteRear(x);
		}
		// this-> object has to be built up by allocating new cells 
		// with OtherOne elements
		Node* P = OtherOne.Front; // local pointer for OtherOne
		// loop which repeats until you reach the end of OtherOne
		while (P != NULL) {
			this->addRear(P->Elem); // P's element is added to this->
			P = P->Next; // Go to the next node in OtherOne
		}
	} // end of if
	
	return *this; // return the result (by reference) unconditionally.
}

// end of class implementation llist.cpp

