/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #10
* LAST MODIFIED:	09/26/18
*
* Inca Quipu ******************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will create a digitalized quipu based on a given number between 0 and 999. The
* quipu was a device that was used by the Inca Epire to communicate numerical quantities. Using
* knots in a string to illustrate values in a positional base 10 represntation, the number 586
* would look like he following:
* 
*     (5)     (8)        (6)
* |---*****---********---******---|
* 
* ALGORITHM:
* 1.  DO
* 2.    PROMPT "Enter a number between 0 and 999"
* 3.    READ number
* 4.    IF number is not an integer between 0 and 999; inputFail = true
* 5.      PRINT "Error. Number must be between 0 and 999"
* 6.  END DO, WHILE inputFail == true
* 7.  CALCULATE hundreds = number / 100
* 8.  CALCULATE tens = (number % 100) / 10
* 9.  CALCULATE ones = (number % 100) % 10
* 10. PRINT "Hundreds = ... Tens = ... Ones = ... "
* 11. PRINT "As an Inca Quipu, " number " is expressed as: "
* 12. PRINT beginning segment of rope, "|---"
* 13. FOR 0 through hundreds' value
* 14.   PRINT "*"
* 15. END FOR
* 16. PRINT middle segment of rope, "---"
* 17. FOR 0 through tens' value
* 18.   PRINT "*"
* 19. END FOR
* 20. PRINT middle segment of rope, "---"
* 21. FOR 0 through ones' value
* 22.   PRINT "*"
* 23. END FOR
* 24. PRINT end segment of rope, "---|"
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

int main(int argc, char** argv) 
{
	int number, ones, tens, hundreds;
	bool inputFail; // Sentinel value for input validation
	
	/** INPUT **/
	do {
		cout << "Enter a number between 0 and 999: ";
		cin >> number;
		
		// Input validation;
		// Fails if wrong data type is read, or number is < 0 or > 999
		inputFail = cin.fail() || ((number < 0) || (number > 999));
		
		if (inputFail) {
			cout << "Error. Number must be between 0 and 999.\n";
			cin.clear();               // Clear error flag
			cin.ignore(INT_MAX, '\n'); // Ignore characters up to new line character
		}
		
	} while (inputFail);
	
	/** PROCESSING **/
	hundreds = (number / 100);
	tens = ((number % 100) / 10);
	ones = ((number % 100) % 10);
	
	/** OUTPUT **/
	cout << "\nHundreds = " << hundreds << "\nTens = " << tens << "\nOnes = " << ones << endl
		<< "\nAs an Inca Quipu, " << number << " is expressed as: " << endl;
	
	cout << "\n|---";
	
	for (int i = 0; i < hundreds; i ++)
		cout << "*";
		
	cout << "---";
	
	for (int i = 0; i < tens; i ++)
		cout << "*";
	
	cout << "---";
	
	for (int i = 0; i < ones; i ++)
		cout << "*";
	
	cout << "---|" << endl;
	
	return 0;
}
