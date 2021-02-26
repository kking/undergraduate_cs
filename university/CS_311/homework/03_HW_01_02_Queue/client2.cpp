// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW1P2 Queue application (generate all strings)
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		client program client2.cpp
// 
// INSTRUCTION: 	Look for ** to complete this program.
// 					The string output should match my hw1queueDemo.out.
// ==================================================================
// PURPOSE: 		This client program will demonstrate the functionality of the
// 					custom "queue.h" implementation. A queue with the capacity of
// 					50 elements will be populated with strings until an overflow
// 					occurs.
//
// ALGORITHM: 		1. Add elements "A", "B", and "C".
// 					2. WHILE (true), or Overflow has not yet been thrown:
// 						a. Remove the front element
// 						b. Display the removed element and queue size
// 						c. Add element + "A"
//						d. Add element + "B"
// 						e. Add element + "C"
//					3. Display all the elements in this queue.
// ==================================================================

#include <iostream>
#include <stdlib.h>
#include <string>

#include "queue.h"

using namespace std;

int main() {
	queue stringQueue;
	string stringElement;
	
	// add elements "A", "B", and "C" to the queue
	stringQueue.add("A");
	stringQueue.add("B");
	stringQueue.add("C");

    while (true) {
    	try {
    		stringQueue.remove(stringElement);
    		
    		cout << "Removed element: " << stringElement;
    		cout << "\nSize: " << stringQueue.getSize() << "\n";
    		stringQueue.displayAll();
    		
    		stringQueue.add(stringElement + "A");
    		stringQueue.add(stringElement + "B");
			stringQueue.add(stringElement + "C");
			
			cout << "\n";
		}
		catch (queue::Underflow) {
			cerr << "ERROR: underflow occurred - no elements to remove.\n";
			exit(1);
		}
		catch (queue::Overflow) {
			cerr << "ERROR: overflow occured - queue is full.\n";
			cout << stringQueue.getSize();
			exit(1);
		}
    	
	} // end of while
	
} // end of main

