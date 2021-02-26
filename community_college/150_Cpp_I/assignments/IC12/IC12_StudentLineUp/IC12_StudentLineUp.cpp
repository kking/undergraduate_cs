/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #12
* LAST MODIFIED:	10/04/18
*
* Student Line-Up *************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will read a list of names from "LineUp.txt" and determine which names belong to the
* front and back of a line based on alphabetical order.
* 
* ALGORITHM:
* 1.  OPEN "LineUp.txt"
* 2.  IF existing file has not been opened
* 3.    PRINT "Error: File... not found"
* 4.    CLOSE program
* 5.  END IF
* 6.  READ front of line = first name in file
* 7.  READ back of line = first name in file
* 8.  WHILE end of file has not been reached
* 9.    READ current name
* 10.   FOR i through the length of the smaller name
* 11.     IF character i of current name <= i of current front
* 12.       SET front = current name
* 13.       BREAK FOR
* 14.   END FOR
* 15.   FOR i through the length of the smaller name
* 16.     IF character i of current name >= i of current back
* 17.       SET back = current name
* 18.       BREAK FOR
* 19.   END FOR
* 20. END WHILE
* 21. CLOSE "LineUp.txt"
* 22. PRINT "Front of line: " + front, "Back of line: " + back
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* cctype - enables manupulation of characters
* fstream - provides file I/O functions
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

/** FUNCTION PROTOTYPES **/
int getShorterNameLength(string name1, string name2);
string getFrontOfLine(string currentFront, string newName);
string getBackOfLine(string currentBack, string newName);

int main(int argc, char** argv) 
{
	string fileName = "LineUp.txt";
	string frontOfLine, backOfLine, tempName;
	
	// Declare an ifstream
	ifstream inFile;
	
	// Open file
	inFile.open(fileName.c_str());
	
	// Check to see if an existing file has been opened
	if (! inFile.is_open()) {
		cout << "Error: File \"" << fileName << "\" not found.\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	// Read first name from file, setting it to frontOfLine and backOfLine as a initial value
	if (! inFile.eof()) {
		inFile >> tempName;
		
		frontOfLine = tempName;
		backOfLine = tempName;
	}
	
	// Loop through file until end of file is reached
	while (! inFile.eof()) {
		inFile >> tempName;
		
		frontOfLine = getFrontOfLine(frontOfLine, tempName);
		backOfLine = getBackOfLine(backOfLine, tempName);
	}
	
	// Close "LineUp.txt"
	inFile.close();
	
	// Print the first and last names in line to the console
	cout << "\nFront of line: " << frontOfLine << "\nBack of line:  " << backOfLine << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

/**
 * Helper method returning the length of the shorter of two names.
 *
 * @param name1 the first name
 * @param name2 the second name
 * @return the length of the shorter name
 */
int getShorterNameLength(string name1, string name2) {
	if (name1.length() > name2.length())
		return name2.length();
	else
		return name1.length();
}

/**
 * Helper method returns the alphabetically smaller name of the given two names.
 *
 * @param currentFront the current front-of-line name
 * @param newName the name to be compared with the front-of-line name
 * @returns the name with greater precedence in alphabetization
 */
string getFrontOfLine(string currentFront, string newName) {
	int shorterNameLength = getShorterNameLength(currentFront, newName);
	string newFront = currentFront;
	
	if (tolower(currentFront[0]) == tolower(newName[0])) {
	
		for (int i = 0; i < shorterNameLength; i ++) {
			if (toupper(newName[i]) < toupper(currentFront[i])) {
				newFront = newName;
				break;
			}
		}
	
	}
	
	return newFront;
}

/**
 * Helper method returns the alphabetically greater name of the given two names.
 *
 * @param currentBack the current back-of-line name
 * @param newName the name to be compared with the back-of-line name
 * @returns the name with lesser precedence in alphabetization
 */
string getBackOfLine(string currentBack, string newName) {
	int shorterNameLength = getShorterNameLength(currentBack, newName);
	string newBack = currentBack;
	
	if (tolower(currentBack[0]) == tolower(newName[0])) {
		for (int i = 0; i < shorterNameLength; i ++) {
			if (toupper(newName[i]) > toupper(currentBack[i])) {
				newBack = newName;
				break;
			}
		}
	}
	
	return newBack;
}
