// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW3P2 slist
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		client program (tester) HW3P2client.cpp
// 
// INSTRUCTION: 	Read the whole file first.
// 					Look for ** to complete all of them.
// 					The output should match my assingment sheet. Check!!!
// 					DO not forget to Tab on each line
// ==================================================================

using namespace std;

#include "slist.h"
#include <iostream>
#include <stdlib.h>

// PURPOSE: Testing search and replace functions
void testOne()
{ 
	slist L;  // the list 
	int foundPos; // to hold the found position from Search  
	int counter = 1; // used to display test line number
	
	try
	{
		// 1) add to front once (element 4)
		cout << "Step " << counter++ << " addFront" << endl;
		L.addFront(4);
		//L.displayAll();
		
		// 2) add to rear 3 times (elements 6, 7, 8)
		cout << "Step " << counter++ << " addRear" << endl;
		L.addRear(6);
		L.addRear(7);
		L.addRear(8);
		
		// 3) displayAll - 4 6 7 8
		cout << "Step " << counter++ << endl;
		L.displayAll();
		
		// 4) search for 6, report the result - found in pos 2
		cout << "Step " << counter++ << endl;
		foundPos = L.search(6);
		cout << "Found 6 in location " << foundPos << endl;
		
		// 5) replace the 6 with 0 using the search result (foundPos)
		cout << "Step " << counter++ << " replace 6" << endl;
		L.replace(0, foundPos); 
		
		// 6) displayAll - 4 0 7 8
		cout << "Step " << counter++ << endl;
		L.displayAll();
		
		// 7) search for 8 and report the result - found in pos 4
		cout << "Step " << counter++ << endl;
		foundPos = L.search(8);
		cout << "Found 8 in location " << foundPos << endl;
		
		// 8) replace the 8 with 2 using the search result (foundPos)
		cout << "Step " << counter++ << " replace 8" << endl;
		L.replace(2, foundPos);
		
		// 9) displayAll - 4 0 7 2
		cout << "Step " << counter++ << endl;
		L.displayAll();
		
		// 10) search for 5 and report the result   - not found
		cout << "Step " << counter++ << endl;
		L.search(5);
		cout << "Found 5 in location " << foundPos << endl;
		
		// 11) replace postion 7 with 10
		cout << "Step " << counter++ << " replace 7" << endl;
		L.replace(10, 7);
		
	} //end of try
	catch(slist::OutOfRange)
	{ 
		cerr << "ERROR: Bad position was given" << endl;
	}

} //end of testOne

// PURPOSE: Testing overloading of ==
void testTwo()
{ 
	slist L1, L2;
	int counter = 1;
	
	// 1. L1 is empty and L2 is empty 
	cout << "Step " << counter++ << ": L1 and L2 is empty." << endl;
	if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;
	
	// 2. L1 is empty and L2 with 4, 5 
	cout << "Step " << counter++ << ": L1 is empty and L2 with 4, 5." << endl;
	L2.addRear(4); L2.addRear(5);
	if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;
	
	// 3.  The opposite 
	cout << "Step " << counter++ << ": L2 with 4, 5 and L1 is empty." << endl;
	if (L2 == L1) cout << "true" << endl; else cout << "false" << endl;
	
	// 4. L1 with 1,2,3 and L2 with  1,2,3
	cout << "Step " << counter++ << ": L1 with 1, 2, 3 and L2 with 1, 2, 3." << endl;
	L1.addRear(1); L1.addRear(2); L1.addRear(3);
	int x;
	L2.deleteFront(x);
	L2.deleteFront(x);
	L2.addRear(1); L2.addRear(2); L2.addRear(3);
	if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

	// 5. L1 with 1,2,3 and L2 with 1,2
	cout << "Step " << counter++ << ": L1 with 1, 2, 3 and L2 with 1, 2." << endl;
	L2.deleteRear(x);
	if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;
	
	// 6. L1 has 1,2,3 and L2 has 1,2,3,4
	cout << "Step " << counter++ << ": L1 with 1, 2, 3 and L2 with 1, 2, 3, 4." << endl;
	L2.addRear(3);
	L2.addRear(4);
	if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;
	
	// 7. L1 has 1,2,3 and L2 has 1,2,4
	cout << "Step " << counter++ << ": L1 with 1, 2, 3 and L2 with 1, 2, 4." << endl;
	L2.deleteRear(x);
	L2.deleteRear(x);
	L2.addRear(4);
	if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

 } //end of method testTwo

// PURPOSE: to test slist thoroughly
int main()
{
	cout << "---- Begin testOne(): search and replace ----" << endl;
	
	testOne(); // for search and replace
	
	cout << "---- End of testOne() ----- " << endl;
	cout << "---- Begin testTwo(): == operator ----" << endl;
	
	testTwo();  // for testing ==
	
	cout << "---- End of testTwo() ----- " << endl;

} // end of main/program

