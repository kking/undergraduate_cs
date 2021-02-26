/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #24
* LAST MODIFIED:	11/25/18
*
* Get to the Point ************************************************************
*
* PROGRAM DESCRIPTION: 
* Using a classes called Point and Line, this program will display and manipulate 
* information for two Points existing in space. 
* 
* ALGORITHM:
* 1. Create a Point p1 existing at (0, 0)
* 2. Create a Point p2 existing at (3, 4)
* 3. Create a Line ln1 starting at p1 and ending at p2
* 4. Create a Line ln2 starting at p2 and ending at p1
* 5. Print p1, p2, ln1, and ln2 to the console
* 6. Print the distance from p1 to p2, and the lengths of ln1 and ln2
* 7. Print the equality between p1 and p2 ("false" case)
* 8. Set p1 = p2
* 9. Print the equality between p1 and p2 ("true" case)
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* "Point.h" - class representing a single point with a x and y position
* "Line.h" - aggregate class relating the distance between two Point objects
******************************************************************************/

#include <cstdlib>
#include <iostream>

#include "Point.h"
#include "Line.h"

using namespace std;

int main(int argc, char** argv) {
	
	Point p1;
	Point p2(3, 4);
	
	Line ln1(p1, p2);
	Line ln2(p2, p1);
	
	cout << "Point 1: " << p1 << "\n" << "Point 2: " << p2 << "\n\n";
		
	cout << "Line 1: " << ln1 << "\n" << "Line 2: " << ln2 << "\n\n";
		
	cout << "Distance from p1 to p2 = " << p1.distanceTo(p2) << " units\n"
		<< "Length of ln1 = " << ln1.length() << " units\n"
		<< "Length of ln2 = " << ln2.length() << " units\n\n";
		
	cout << "Is p1 equal to p2? " << ((p1 == p2) ? "true" : "false") << "\n";
	cout << "Is ln1 equal to ln2? " << ((ln1 == ln2) ? "true" : "false") << "\n\n";
	
	p1 = p2;
	
	cout << "*** Setting p1 = p2 ***\n"
		<< "Point 1: " << p1 << endl << "Point 2: " << p2 << "\n"
		<< "Is p1 equal to p2? " << ((p1 == p2) ? "true" : "false") << "\n";
	
	return 0;
	
} // End of main

