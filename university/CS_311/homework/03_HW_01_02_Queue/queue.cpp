// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW1P2 Queue
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		queue.cpp
// 
// INSTRUCTION: 	Look for ** using control-S. Then, fill in the function body.
// 					When done, compile queue.cpp to make sure it has no syntax errors.
// ==================================================================

#include <iostream>
#include "queue.h"  

using namespace std;

// constructor initializes data members as in the notes 
queue::queue() {  
	count = 0; // varies from 0 to MAX_SIZE.
	
	front = 0; // starts at 0; changes to 1, ..., MAX_SIZE-1, 0.
	rear = -1; // starts at -1; changes to 0, ..., MAX_SIZE-1, 0.
}

// destructor 
queue::~queue() { 
	// do nothing; the static array is destroyed by the compiler
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty() {
	return (count == 0);
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull() {
	return (count == MAX_SIZE);
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem) {
	if (isFull()) {
		throw Overflow();
	}
	rear = (rear+1) % MAX_SIZE;
	el[rear] = newElem;
	count++;
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem) {
	if (isEmpty()) {
		throw Underflow();
	}
	removedElem = el[front];
	front = (front+1) % MAX_SIZE;
	count--;
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
// PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem) {
	if (isEmpty()) {
		throw Underflow();
	}
	theElem = el[front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize() {
	return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [ ].
// if empty, displays [ empty ].
void queue::displayAll() {
	if (isEmpty()) { 
		cout << "[ empty ]" << endl;
	}
	else {
		int j = front;
		cout << "[ ";
		for (int i = 1; i <= count; i++) { 
			cout << el[j] << " ";
			j = (j+1) % MAX_SIZE;
		}
		cout << "]" << endl;   
	} 
}

// PURPOSE: if empty, throws an exception Underflow
// if queue has just 1 element, does nothing
// if queue has more than 1 element, moves the front one to the rear by
// calling remove followed by add.
void queue::goToBack() {           
	if (isEmpty()) {
		throw Underflow();
	}
	el_t theElem;
	remove(theElem);
	add(theElem);
}

// end of queue.cpp

