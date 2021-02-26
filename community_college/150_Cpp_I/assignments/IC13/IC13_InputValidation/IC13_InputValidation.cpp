/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #13
* LAST MODIFIED:	10/09/18
*
* Input Validation ************************************************************
*
* PROGRAM DESCRIPTION: 
* Using a single function, this program will handle input validation for receiving both 
* integers and doubles within a given range.
* 
* ALGORITHM:
* 1.  PROMPT "enter attendance between (1-30)..."
* 2.  READ attendance
* 3.  IF attendance is not an integer between 1-30
* 4.    PRINT error message
* 5.    REPEAT steps 1-2
* 6.  PROMPT "enter GPA between (0.0 to 4.0)..."
* 7.  READ gpa
* 8.  IF gpa is not a value between 0.0-4.0
* 9.    PRINT error message
* 10.   REPEAT steps 6-7
* 11. PROMPT menu, items 1-4, to "have some fun," "write some code", "study", "exit"
* 12. READ menu item selection
* 13. PRINT "You chose to..."
* 14. SWITCH menu item selection
* 15.   CASE 1: PRINT "to have some fun(ctions)"
* 16.   CASE 2: PRINT "to write some code"
* 17.   CASE 3: PRINT "study for the midterm
* 18.   CASE 4: PRINT "to exit"
* 19. END SWITCH
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
double getValidInput(string message, string error, double min, double max);
void processMenuItem(int menuSelection);

int main(int argc, char** argv) 
{
	string menu = "********************************************************************\n";
		menu += "**                                                                **\n";
		menu += "**                      THE SUPER DUPER MENU                      **\n";
		menu += "**                                                                **\n";
		menu += "********************************************************************\n";
		menu += "** Please select from the following choices:                      **\n";
		menu += "** 1) Have some fun(ctions)                                       **\n";
		menu += "** 2) Write some code                                             **\n";
		menu += "** 3) Study for the midterm                                       **\n";
		menu += "** 4) Exit                                                        **\n";
		menu += "********************************************************************\n";
	
	int attendance, menuSelection;
	double gradePointAverage;
	
	cout << "Transaction #1 - Integer Input\n\n";
	attendance = getValidInput("Please enter attendance between (1-30): ", "Error: Attendance must be between 1 to 30.", 1.0, 30.0);
	cout << "\nThe attendance you entered is: " << attendance << endl;
	
	cout << "\nTransaction #2 - Double Input\n\n";
	gradePointAverage = getValidInput("Please enter GPA between (0.0 to 4.0): ", "Error: GPA must be between 0.0 and 4.0.", 0.0, 4.0);
	cout << "\nThe GPA you entered is: " << gradePointAverage << endl;
	
	cout << "\nTransaction #3 - Menu Input\n\n";
	menuSelection = getValidInput(menu, "Error: Menu item selection must be between 1 and 4.", 1.0, 4.0);
	processMenuItem(menuSelection);
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/
/**
 * Function handling input validation.
 *
 * @param message a custom message prompting for user input
 * @param error an error message to be presented in the case of erroneous input
 * @param min the minimum numerical value for user input
 * @param max the maximum numerical value for user input
 * @return a valid number entered by the user
 */
double getValidInput(string message, string error, double min, double max) 
{
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

/**
 * Processes menu item selection.
 *
 * @param menuSelection an integer representing an item in a console-based menu
 */
void processMenuItem(int menuSelection)
{
	cout << "You chose to ";
	
	switch (menuSelection) {
		case 1: // Have some fun(ctions)
			cout << "have some fun(ctions)!";
			break;
		case 2: // Write some code
			cout << "write some code!";
			break;
		case 3: // Study for the midterm
			cout << "study for the midterm!";
			break;
		case 4: // Exit
			cout <<" exit the program. Thanks for playing along!";
			break;
		default:
			break;
	}
	
	cout << endl;
}
