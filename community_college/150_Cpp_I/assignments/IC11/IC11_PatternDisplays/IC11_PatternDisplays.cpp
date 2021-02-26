/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #11
* LAST MODIFIED:	10/02/18
*
* Pattern Displays ************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will utilize nested for loops to print various patterns of triangles.
* 
* ALGORITHM:
* 1.  PRINT "Pattern A:"
* 2.  FOR i = 0 through 10
* 3.    FOR j = 0 through i
* 4.      PRINT "+" for as many times as current row number i
* 5.    END FOR
* 6.    PRINT "\n"
* 7.  END FOR
* 8.  PRINT "Pattern B:"
* 9.  FOR i = 10 through 0 descending
* 10.   FOR j = 0 through i
* 11.     PRINT "*" for as many times as the current value of i
* 12.   END FOR
* 13.   PRINT "\n"
* 14. END FOR
* 15. PRINT "Pattern C:"
* 16. FOR i = 0 through 6
* 17.   FOR j = i through 5
* 18.     PRINT " " for as many times as i - 5
* 19.   END FOR
* 20.   FOR k = 0 through i * 2
* 21.     PRINT "*" for as many times as i * 2
* 22.   END FOR
* 23.   PRINT "\n"
* 24. END FOR
* 25. PRINT "Pattern D:"
* 26. FOR i = 6 through 0 descending
* 27.   FOR j = i through 6
* 28.     PRINT " " for as many times as i - 6
* 29.   END FOR
* 30.   FOR k = 1 through i * 2
* 31.     PRINT "*" for as many times as (i * 2) - 1
* 32.   END FOR
* 33. END FOR
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
******************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	cout << "Pattern A:\n";
	for (int i = 0; i < 10; i ++) {
		// Print "+" for as many times as the current row number
		for (int j = 0; j < i; j ++) {
			cout << "+";
		}
		cout << "\n";
	}
	
	cout << "\nPattern B:\n\n";
	for (int i = 10; i > 0; i --) {
		// Prin "+" for as many times as the current value of i
		for (int j = 0; j < i; j ++) {
			cout << "+";
		}
		cout << "\n";
	}
	
	cout << "\nPattern C:\n\n";
	for (int i = 0; i < 6; i ++) {
		// Print " " for as many times as i - 5
		for (int j = i; j < 5; j ++) {
			cout << " ";
		}
		// Print "*" for as many times as i * 2
		for (int k = 0; k <= i*2; k ++) {
			cout << "*";
		}
		cout << "\n";
	}
	
	cout << "\nPattern D:\n\n";
	for (int i = 6; i > 0; i --) {
		// Print " " for as many times as i - 6
		for (int j = i; j < 6; j ++) {
			cout << " ";
		}
		// Print "*" for as many times as (i * 2) - 1
		for (int k = 1; k < i*2; k ++) {
			cout << "*";
		}
		cout << "\n";
	}
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
