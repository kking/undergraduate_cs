/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #24
* LAST MODIFIED:	11/25/18
*
* Month ***********************************************************************
*
* PROGRAM DESCRIPTION: 
* Using the class Month, this program will print and manipulate information
* related to months in a year. 
* 
* ALGORITHM:
* 1. Create a Month m1 denoted by the values "December" and 12
* 2. Create a Month m2 denoted by "January" and 1
* 3. Print both Months to the console
* 4. Determine and print the equality between m1 and m2 to the console
* 5. Prefix increment m1 while printing to console
* 6. Prefix decrement m2 while printing to console
* 7. Determine and print the equality between m1 and m2 to the console
* 8. Assign m1 = m2
* 9. Print both Months to the console
* 10. Determine and print the equality between m1 and m2 to the console
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include "Month.h"

using namespace std;

int main() {
	
	// Create m1 ("December", 12), and m2 ("January", 1)
	Month m1("December", 12);
	Month m2;
	
	// Print both Months to the console
	cout << "~~~Instantiating m1 with January (1) and m2 with December (12)~~~\n"
		<< "m1 = " << m1 << endl
		<< "m2 = " << m2 << endl;
		
	// Determine and print the equality between m1 and m2 to the console
	cout << "m1 == m2? " << ((m1 == m2) ? "true" : "false") << "\n\n";
	
	// Prefix increment m1 and prefix decrement m2 while printing to console
	cout << "~~~++m1 (prefix increment) and --m2 (prefix decrement)~~~\n"
		<< "++m1 = " << ++m1 << endl
		<< "--m2 = " << --m2 << endl;
		
	// Determine and print the equality between m1 and m2 to the console
	cout << "m1 == m2? " << ((m1 == m2) ? "true" : "false") << "\n\n";
	
	// Assign m1 = m2
	m1 = m2;
	
	// Print both Months to the console
	cout << "~~~Assigning m1 = m2~~~\n"
		<< "m1 = " << m1 << endl
		<< "m2 = " << m2 << endl;
	
	// Determine and print the equality between m1 and m2 to the console
	cout << "m1 == m2? " << ((m1 == m2) ? "true" : "false") << "\n";

	return 0;
	
} // End of main

