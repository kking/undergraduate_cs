/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #02
* LAST MODIFIED:	08/28/18
*
* Cyborg Data Types ***********************************************************
*
* PROGRAM DESCRIPTION:
* This program will display a formatted table detailing the amount of memory used by the for each of the 
* following data types: bool, char, short, int, long, long long, float, double, and long double.
*
* ALGORITHM:
* 1. Define a set width for each column of the output, columnWidth.
* 2. In a single cout statement, begin the first column by inserting setw(columnWidth) and
*	 the name of the first data type, "bool". 
* 3. Insert the size of the data type through sizeof(bool), followed by the string " byte(s)\n",
*	 beginning a new line.
* 4. Repeat steps 2-3 within the same cout statement for char, short, int, long, long long,
* 	 float, double, and long double to complete the table.
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

int main(int argc, char* argv[]) 
{
	int columnWidth = 20; // a set width for each column of the following table
	
	/** OUTPUT **/
	cout << left
		<< setw(columnWidth) << "bool: " << sizeof(bool) << " byte(s)\n"
		<< setw(columnWidth) << "char: " << sizeof(char) << " byte(s)\n"
		<< setw(columnWidth) << "short: " << sizeof(short) << " byte(s)\n"
		<< setw(columnWidth) << "int: " << sizeof(int) << " byte(s)\n"
		<< setw(columnWidth) << "long: " << sizeof(long) << " byte(s)\n"
		<< setw(columnWidth) << "long long: " << sizeof(long long) << " byte(s)\n"
		<< setw(columnWidth) << "float: " << sizeof(float) << " byte(s)\n"
		<< setw(columnWidth) << "double: " << sizeof(double) << " byte(s)\n"
		<< setw(columnWidth) << "long double: " << sizeof(long double) << " byte(s)";
		
	return 0;
}
