// ==================================================================
// CS311 Yoshii - HW5 Priority Queue Implementation File
// 
// HW#: 			HW5 Priority Printer Queue 
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		implementation pqueue.cpp
// 
// INSTRUCTION: 	Complete all ** parts and give good comments
// 					** Do not delete my comments.
// ==================================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  
	count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
	cout << "Adding: " << j << endl;
	// ** add the job j at the rear (and update count)
	// **   if possible else display error message. 
	if (count < MAX) {
		Q[count++] = j;
		trickleup(); // moves the job to the right place	
	}
	else {
		cout << "ERROR: pqueue insertJob(" << j << ") failed." << endl;
	}
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
	cout << "Printing: " << Q[0] <<endl;
	reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ 
	cout << "Jobs: [" ;
	// ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
	for (int i = 0; i < count-1; i++) {
		cout << Q[i] << ", ";
	}
	cout << Q[count-1] << "]" << endl;
} 

// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
	// ** swap the values in these locations in Q
	int temp = Q[loc1]; // save value in loc1
	Q[loc1] = Q[loc2];
	Q[loc2] = temp;
}

// Purpose: to make the very last job trickle up to the right location. Never do X--. 
void pqueue::trickleup()
{ 
	int x = count-1;  // the very last job's location
	// ** While x is > 0   
	//    compare Q[x] with the parent (*)
	//    and if the parent is bigger swap & update x 
	//    to be the parent . Otherwise stop the loop.
	// (*) Call getParent to get the location of the parent
	//            based on the child's location.
	while (x > 0) {
		int parentLoc = getParent(x);
		if (Q[parentLoc] > Q[x]) {
			swap(x, parentLoc);
			x = parentLoc;
		}
		else {
			break;
		}
	} // end of while
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  
	// ** return the parent location based on the child loc
	return (even(childloc)) ? ((childloc-2)/2) : ((childloc-1)/2);
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
	return ((i % 2) ==  0); // odd=left child, even=right child
}


// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ 
	int X;   // the current location
	Q[0] = Q[count-1];  // move the last job to the front
	count--;
	X = 0; // ** Start X at 0 (the root)
	//    while X is within the array:
	//       Find the location of the smaller child
	//         (if the location of both children are off the tree, stop the loop).
	//       If the smaller child is smaller than the parent,
	//          swap and X becomes the smaller child's location.
	//       else no swaps so stop to loop.
	while (X >= 0 && X < count) {
		int smallLoc = getSmallerchild(X);
		if (smallLoc < 0 || smallLoc >= count) {
			break;
		}
		if (Q[smallLoc] < Q[X]) {
			swap(smallLoc, X);
			X = smallLoc;
		}
		else {
			break;
		}
	}
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
	// ** return the location of the smaller child 
	//    Be careful because one or both of them may be
	//    beyond count-1.  Check boundaries before you 
	//    compare Q contents!!!!
	int leftLoc = (i*2)+1;
	int rightLoc = (i*2)+2;
	if (leftLoc < count && rightLoc < count) {
		return (Q[leftLoc] < Q[rightLoc]) ? leftLoc : rightLoc;
	}
	else if (leftLoc < count) {
		return leftLoc;
	}
	else {
		return -1;
	}
}

// end of pqueue.cpp

