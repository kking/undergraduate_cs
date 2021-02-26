// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW3P1 llist
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		client program (tester) HW3P1client.cpp
// 
// INSTRUCTION: 	Look for ** to complete all of them
// 					The output should match my assignment sheet. Check!!!!
// ==================================================================

using namespace std;

#include "llist.h"
#include <iostream>
#include <stdlib.h>

// PURPOSE: to test copy constructor which gets called automatically. 
// Adds 6 to the rear of the copiedList and displays the list.
// PARAMETER copiedList: list passed by value becomes copiedList via copy constructor
void CopyTest(llist copiedList)
{
	cout << "in copy test" << endl;
	copiedList.addRear(6); // add 6
	copiedList.displayAll(); // display all
	cout << "finished copy test" << endl;
}

void caseOne()
{
	cout << "CASE 1: Basic --------------- " << endl;
	llist L; // this is my list
	int x; // to hold a removed element
	int c = 1; // displayed step number
	
	// 1. check empty and report the result  
	cout << "Step " << c++ << ": isEmpty()." << endl;
	cout << ((L.isEmpty()) ? "List is empty.\n" : "List is not empty.\n");
	
	// 2. display the list  
	cout << endl << "Step " << c++ << ": displayAll()." << endl;
	L.displayAll();

	// 3. add 4 integers to rear 1,2,3,4    
	cout << endl << "Step " << c++ << ": addRear(int), adding 1, 2, 3, 4." << endl;
	L.addRear(1); 
	L.addRear(2); 
	L.addRear(3); 
	L.addRear(4);
	
	// 4. display the list  
	cout << endl << "Step " << c++ << ": displayAll()." << endl;
	L.displayAll();
	
	// 5. remove from front twice using x (and display the elements removed)
	cout << endl << "Step " << c++ << ": deleteFront(int) twice." << endl;
	L.deleteFront(x);
	cout << "Removed: " << x << endl;
	L.deleteFront(x);
	cout << "Removed: " << x << endl;

	// 6. display the list
	cout << endl << "Step " << c++ << ": displayAll()." << endl;
	L.displayAll();
	
	// 7. check empty and report the result 
	cout << endl << "Step " << c++ << ": isEmpty()." << endl;
	cout << ((L.isEmpty()) ? "List is empty." : "List is not empty.") << endl;
	
	// 8. remove from the rear twice using x (display the elements removed)
	cout << endl << "Step " << c++ << ": deleteRear(int) twice." << endl;
	L.deleteRear(x);
	cout << "Removed: " << x << endl;
	L.displayAll();
	L.deleteRear(x);
	cout << "Removed: " << x << endl;
	L.displayAll();
	  
	// 9. check empty again and report the result
	cout << endl << "Step " << c++ << ": isEmpty()." << endl; 
	cout << ((L.isEmpty()) ? "List is empty." : "List is not empty.") << endl;

} // end of method caseOne

void caseTwo()
{ 
  cout << endl <<  "Case 2: Insert and Delete ------------" << endl;
  llist L; // another list for case 2
  int x; // to hold the removed element 
  int c = 1; // displayed step number

  // 1. add to front 4 times (9,8,6,5) 
  cout << "Step " << c++ << ": addFront(int), adding 9, 8, 6, 5." << endl;
  L.addFront(9); 
  L.addFront(8); 
  L.addFront(6); 
  L.addFront(5);

  // 2. display all
  cout << endl << "Step " << c++ << ": displayAll()." << endl;
  L.displayAll();

  // 3. insert the 1st (element 4) 4 5 6 8 9
  cout << endl << "Step " << c++ << ": insertIth(1, 4), insert 4 at index 1." << endl;
  L.insertIth(1, 4);
  L.displayAll();

  // 4. insert the 4th (element 7)  4 5 6 7 8 9
  cout << endl << "Step " << c++ << ": insertIth(4, 7), insert 7 at index 4." << endl;
  L.insertIth(4, 7);
  L.displayAll();

  // 5. insert the 7th (element 10) and displayAll 4 5 6 7 8 9 10
  cout << endl << "Step " << c++ << ": insertIth(7, 10), insert 10 at index 7." << endl;
  L.insertIth(7, 10);
  L.displayAll();

  // 6. insert the 9th (element 12) error (out of range)
  cout << endl << "Step " << c++ << ": insertIth(9, 12), insert 12 at index 9 (out of range)." << endl;
  try {
	L.insertIth(9, 12);
  }
  catch (llist::OutOfRange) {
  	cout << "Error OutOfRange: insertion attempted out of range.\n"; // do not exit
  }

  // 7. insert the 0th (element 0) error (out of range)
  cout << endl << "Step" << c++ << ": insertIth(0, 0), insert 0 at index 0 (out of range)." << endl;
  try {
	L.insertIth(0, 0);
  }
  catch (llist::OutOfRange) {
  	cout << "Error OutOfRange: insertion attempted out of range.\n"; // do not exit
  }

  // 8. displayAll (should be unchanged from step 5 display)
  cout << endl << "Step " << c++ << ": displayAll()." << endl;
  L.displayAll();

  // 9. delete Ith I==1 (display  the element removed) 5 6 7 8 9 10
  cout << endl << "Step " << c++ << ": deleteIth(1, int), delete 1st element." << endl;
  L.deleteIth(1, x); 
  cout << "Removed: " << x << endl;
  L.displayAll();

  // 10. delete Ith I==6 (display the element removed) 5 6 7 8 9 
  cout << endl << "Step " << c++ << ": deleteIth(6, int), delete 6th element." << endl;
  L.deleteIth(6, x);
  cout << "Removed: " << x << endl;
  L.displayAll();

  // 11. delete Ith I==3 (display the element removed) and displayAll 5 6 8 9
  cout << endl << "Step " << c++ << ": deleteIth(3, int), delete 3rd element." << endl;
  L.deleteIth(3, x);
  cout << "Removed: " << x << endl;
  L.displayAll();

  // 12. delete Ith I==5 . error (out of range)
  cout << endl << "Step " << c++ << ": deleteIth(5, int), delete 5th element (out of range)." << endl;
  try {
	L.deleteIth(5, x);
  }
  catch (llist::OutOfRange) {
  	cout << "Error OutOfRange: deletion attempted out of range.\n"; // do not exit
  } 

  // 13. delete Ith I==0 . error (out of range)
  cout << endl << "Step " << c++ << ": deleteIth(0, int), delete 0th element (out of range)." << endl;
  try {
	L.deleteIth(0, x);
  }
  catch (llist::OutOfRange) {
  	cout << "Error OutOfRange: deletion attempted out of range.\n"; // do not exit
  } 

  // 14. displayAll (should be unchanged from step 11 display)
  cout << endl << "Step " << c++ << ": displayAll()." << endl;
  L.displayAll();

  // 15. delete from rear until empty (display the elements removed)
  cout << endl << "Step " << c++ << ": delete all elements." << endl;
  // loop - use x for removed element
  cout << "Removed: ";
  while (!L.isEmpty()) {
  	L.deleteRear(x);
  	cout << x << " ";
  }
  cout << endl;

  // 16. displayAll - should be empty now
  cout << endl << "Step " << c++ << ": displayAll()." << endl;
  L.displayAll();

  // 17. insert the 0th (error out of range)
  cout << endl << "Step " << c++ << ": insertIth(0, int), insert element at index 0 (out of range)." << endl;
  try {
	L.insertIth(0, x);
  }
  catch (llist::OutOfRange) {
  	cout << "Error OutOfRange: insertion attempted out of range.\n"; // do not exit
  }

  // 18. delete front (error underflow)
  cout << endl << "Step " << c++ << ": deleteFront(int), deletion from empty list (underflow)." << endl;
  try {
	L.deleteFront(x);
  }
  catch(llist::Underflow) {
  	cout << "Error Underflow: deletion attempted on an empty list.\n"; // do not exit
  } 

  // 19. delete 2nd I == 2 (error out of range)
  cout << endl << "Step " << c++ << ": deleteIth(2, int), delete 2nd element (out of range)." << endl;
  try {
	L.deleteIth(2, x);
  }
  catch (llist::OutOfRange) {
  	cout << "Error OutOfRange: deletion attempted out of range.\n"; // do not exit
  } 
  
  // 20.  delete rear (error underflow)
  cout << endl << "Step " << c++ << ": deleteRear(int), deletion from empty list (underflow)." << endl;
  try {
	L.deleteRear(x);
  }
  catch(llist::Underflow) {
  	cout << "Error Underflow: deletion attempted on an empty list.\n"; // do not exit
  } 

} // end of method caseTwo

void caseThree()
{
  cout << "Case 3: Copy Constructor and = -------" << endl;
  llist L1, L2; // two lists needed
  int x; // local for removed element
  int c = 1; // step number

  // 1. Create a 5 element list with  [1,2,3,4,5] (L1)
  cout << "Step " << c++ << ": addRear(int), add 1, 2, 3, 4, 5 to L1." << endl;
  for (int i = 1; i <= 5; i++) {
  	L1.addRear(i);
  }
  cout << "L1: "; 
  L1.displayAll(); 

  // 2. Simply pass L1 to a client function called CopyTest to test your copy constructor.
  cout << endl << "Step " << c++ << ": client CopyTest(llist), test copy constructor with L1." << endl;
  CopyTest(L1);
  
  cout << "-- After copytest --- " << endl;
 
  // 3. Display L1 (this should still be a 5 element list)
  cout << endl << "Step " << c++ << ": displayAll(), display L1." << endl;
  cout << "L1: "; 
  L1.displayAll();
 
  cout << "-- Testing operator overloading ---" << endl;

  // 4. Do L1 = L1;
  cout << endl << "Step " << c++ << ": gets, L1 = L1." << endl;
  L1 = L1;

  // 5. Display L1 (this should still be 1 2 3 4 5)
  cout << endl << "Step " << c++ << ": displayAll(), display L1." << endl;
  cout << "L1: "; 
  L1.displayAll();		

  // 6. Create a 4 element list L2 with 7,8,9,10.
  cout << endl << "Step " << c++ << ": addRear(int), add 7, 8, 9, 10 to L2." << endl;
  for (int i = 7; i <= 10; i++) {
  	L2.addRear(i);
  }

  // 7. Display L2
  cout << endl << "Step " << c++ << ": displayAll(), display L2." << endl;
  cout << "L2: ";
  L2.displayAll();

  // 8. Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << endl << "Step " << c++ << ": gets, L2 = L1." << endl;
  L2 = L1;

  // 9. Display L2.
  cout << endl << "Step " << c++ << ": displayAll(), display L2." << endl;
  cout << "L2: "; 
  L2.displayAll();

  // 10. Remove a rear node from L1. (This should not affect L2).
  cout << endl << "Step " << c++ << ": deleteRear(int), remove element from L1." << endl;
  L1.deleteRear(x);

  // 11. Display L1. (L1 is 1,2,3,4)
  cout << endl << "Step " << c++ << ": displayAll(), display L1." << endl;
  cout << "L1 :";
  L1.displayAll();

  // 12. Display L1 again. (4 elements just to make sure)
  cout << endl << "Step " << c++ << ": displayAll(), display L1." << endl;
  cout << "L1: ";
  L1.displayAll();

  // 13. Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << endl << "Step " << c++ << ": displayAll(), display L2." << endl;
  cout << "L2: ";
  L2.displayAll();
}

// PURPOSE of the Program: to test llist thoroughly
// Algorithm/Design: 3 test cases are divided into functions and ***
int main()
{
	int selection; // this will display what the user wants to do
	  
	do {
		cout << endl << "MENU: These are your options: " << endl << endl;
		cout << "   (1) Case 1  " << endl;
		cout << "   (2) Case 2  " << endl;
		cout << "   (3) Case 3  " << endl;
		cout << "    Enter ( 0 ) to quit " << endl;
		cout << "===> ";
		      
		cin >> selection;
		      
		switch(selection) {
			case 1: caseOne(); break;
			case 2: caseTwo(); break;
			case 3: caseThree(); break;
		}
	}
	while(selection !=0);

} // end of main

