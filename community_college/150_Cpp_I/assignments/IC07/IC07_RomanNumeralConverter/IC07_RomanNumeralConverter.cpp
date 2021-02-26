/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #07
* LAST MODIFIED:	09/17/18
*
* Roman Numeral Converter *****************************************************
*
* PROGRAM DESCRIPTION: 
* This program will display the Roman numeral equivalent of any number in the range 1 through
* 10 as given by the user. 
* 
* ALGORITHM:
* 1. PROMPT "Enter a number in the range 1 to 10"
* 2. READ number in the range 1 to 10
* 3. IF number < 1 or number > 10
* 4.   PRINT "Error: number must be in the range 1 to 10"
* 5.   TERMINATE program
* 6. END IF
* 7. PRINT "As a Roman numeral, " number " is expressed as "
* 8. IF number == 1, PRINT "I"
* 9. ELSE IF number == 2, PRINT "II"
* 10. ELSE IF number == 3, PRINT "III"
* 11. ELSE IF number == 4, PRINT "IV"
* 12. ELSE IF number == 5, PRINT "V"
* 13. ELSE IF number == 6, PRINT "VI"
* 14. ELSE IF number == 7, PRINT "VII"
* 15. ELSE IF number == 8, PRINT "VIII"
* 16. ELSE IF number == 9, PRINT "IX"
* 17. ELSE, PRINT "X"
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
	/** DECLARATIONS **/
	int number;
	
	/** INPUT **/
	cout << "Enter a number in the range 1 to 10: ";
	cin >> number;
	
	// Input validation: to ensure input matches expectation
	if ((number < 1) || (number > 10))
	{
		cout << "Error: number must be in the range 1 to 10.\n\n";
		system("PAUSE");
		return EXIT_FAILURE; // Terminates program
	}
	
	/** OUTPUT **/
	cout << "As a Roman Numeral, " << number << " is expressed as ";
	
	if (number == 1)
		cout << "I";
	else if (number == 2)
		cout << "II";
	else if (number == 3)
		cout << "III";
	else if (number == 4)
		cout << "IV";
	else if (number == 5)
		cout << "V";
	else if (number == 6)
		cout << "VI";
	else if (number == 7)
		cout << "VII";
	else if (number == 8)
		cout << "VIII";
	else if (number == 9)
		cout << "IX";
	else
		cout << "X";

	cout << endl << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
