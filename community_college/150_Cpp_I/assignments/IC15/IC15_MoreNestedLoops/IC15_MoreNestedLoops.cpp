/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #15
* LAST MODIFIED:	10/16/18
*
* More Nested Loops ***********************************************************
*
* PROGRAM DESCRIPTION: 
* This program will use nested for loops to create figures comprised of ASCII characters.
* 
* ALGORITHM:
* 1.  DO, WHILE option != 3
* 2.    PRINT menu
* 3.    READ option as an integer in the range [1, 3]
* 4.    SWITCH option
* 5.      CASE 1: function printTriangle()
* 6.        FOR row in the range [1, 5]
* 7.          FOR dash in range [1, 6 - row]
* 8.            PRINT "-"
* 9.          FOR number in range [1, row*2 - 1]
* 10.           PRINT row*2 - 1
* 11.         FOR dash in range [1, 6 - row]
* 12.           PRINT "-"
* 13.       END FOR
* 14.     CASE 2: function printTriangle(int size)
* 15.       READ size as an integer in the range [0, MAX]
* 16.       FOR row in the range [1, size]
* 17.         FOR dash in the range [1, (size-row)*4]
* 18.           PRINT "-"
* 19.         FOR asterisk in the range [1, (row-1)*8]
* 20.           PRINT "*"
* 21.         FOR dash in the range [1, (size-row)*4]
* 22.           PRINT "-"
* 23.       END FOR
* 24.     CASE 3: 
* 25.       PRINT "Thanks for printing triangles with me!"
* 26. END DO, WHILE option != 3 
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/** FUNCTION PROTOTYPES **/
void printMenu();
void printTriangle();
void printTriangle(int rows);
double getValidInput(string message, string error, double min, double max);

int main(int argc, char** argv) 
{
	int menuOption, triangleSize;
	
	do
	{
		printMenu();
		menuOption = getValidInput("", "Error: Menu selection must be 1-3.", 1, 3);
		
		switch (menuOption) {
			case 1: // Print a numbered triangle of a fixed size
				printTriangle();
				break;
			case 2: // Print a triangle whose height is dependent on an integer received from console
				triangleSize = getValidInput("\nEnter size (rows) for triangle: ", "Error: Invalid size.", 0, INT_MAX);
				printTriangle(triangleSize);
				break;
			case 3: // Exit program
				cout << "\nThanks for printing triangles with me. :) \n\n";
				break;
			default: 
				break;
		}
		
	} while (menuOption != 3);
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/
/**
 * Prints a menu presenting options for printing a triangle.
 */
void printMenu() {
	cout
		<< "*****************************************************\n" 
		<< "**           Let's Print Some Triangles!           **\n"
		<< "*****************************************************\n" 
		<< "** 1. Print a numbered triangle                    **\n"
		<< "** 2. Print a triangle with a size of your choice  **\n"
		<< "** 3. Exit program                                 **\n"
		<< "*****************************************************\n";
}

/**
 * Prints the following figure using nested for-loops:
 *
 * -----1-----
 * ----333----
 * ---55555---
 * --7777777--
 * -999999999-
 */
void printTriangle() {
	cout << "\nCheck this out!\n\n";
	
	for (int row = 1; row <= 5; row ++) {
		for (int lDash = 1; lDash <= (6 - row); lDash ++) {
			cout << "-";
		}
		for (int number = 1; number <= (row*2 - 1); number ++) {
			cout << row*2 - 1;
		}
		for (int rDash = 1; rDash <= (6 - row); rDash ++) {
			cout << "-";
		}
		cout << endl;
	}
	
	cout << "\n... Isn't it beautiful?\n\n";
}
 
 /**
  * Prints a triangle figure whose height (number of rows) is determined by the user.
  *
  * @param size the number of rows to be printed
  */
void printTriangle(int size) {
	cout << "\nHere's a triangle comprised of " << size << " rows: \n\n";
	
	for (int row = 1; row <= size; row ++) {
		for (int lDash = 1; lDash <= ((size-row)*4); lDash ++) {
			cout << "-";
		}
		for (int asterisk = 1; asterisk <= ((row-1)*8); asterisk ++) {
			cout << "*";
		}
		for (int rDash = 1; rDash <= ((size-row)*4); rDash ++) {
			cout << "-";
		}
		cout << endl;
	}
	
	cout << endl;
}

/**
 * Function handling input validation.
 *
 * @param message a custom message prompting for user input
 * @param error an error message to be presented in the case of erroneous input
 * @param min the minimum numerical value for user input
 * @param max the maximum numerical value for user input
 * @return a valid number entered by the user
 */
double getValidInput(string message, string error, double min, double max) {
	bool inputFail;
	double input;
	
	do {
		cout << message;
		cin >> input;
		
		// Input validation;
		// fails if wrong data type is read, or input > max or < min
		inputFail = cin.fail() || (input < min) || (input > max);
		
		if (inputFail) {
			cout << error << endl;
			cin.clear();               // Clears error flag
			cin.ignore(INT_MAX, '\n'); // Ignores characters up to new line character
		}
		
	} while (inputFail);
	
	return input;
}

