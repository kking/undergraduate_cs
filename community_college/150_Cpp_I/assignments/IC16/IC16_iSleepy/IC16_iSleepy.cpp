/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #16
* LAST MODIFIED:	10/22/18
*
* iSleepy *********************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will monitor how much sleep the user obtained each night last week, determining
* if the hours or each night substantiated "recommended", "not recommended", or "may be appropriate"
* qualities of sleep based on the National Sleep Foundation's criteria for a young adult.
* 
* ALGORITHM:
* 1.  FOR every day of the week, Sunday through Saturday
* 2.    PROMPT "Enter hours slept on... "
* 3.      READ current day's hours as a value between 0 to 24
* 4.      total hours += current day's hours
* 5.      IF hours >= 7 AND hours <= 9
* 6.        INCREMENT number of "recommended" nights
* 7.      ELSE IF hours < 6 OR hours > 11
* 8.        INCREMENT number of "not recommended" nights
* 9.      ELSE
* 10.       INCREMENT number of "appropriate" nights
* 11. END FOR
* 12. CALCULATE average = total hours / number of days
* 13. PRINT total hours of sleep per night and the average
* 14. PRINT "According to the NSF, last week you slept:"
* 15. PRINT number of "recommended" nights, "not recommended" nights, and "appropriate" nights
* 16. PRINT "Overall, your sleep health (on average) is:"
* 17. IF average >= 7 AND average <= 9
* 18.   PRINT "Recommended"
* 19. ELSE IF average < 6 OR average > 11
* 20.   PRINT "Not recommended"
* 21. ELSE
* 22.   PRINT "May be Appropriate"
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

int main(int argc, char** argv) {
	/** CONSTANTS **/
	const int SIZE = 7;
	const string DAYS[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
						"Thursday", "Friday", "Saturday" };
						
	/** DECLARATIONS **/
	double hours[SIZE], total = 0.0, average;
	int recommended = 0, appropriate = 0, notRecommended = 0;
	
	/** INPUT and PROCESSING **/
	// Loop through each day of the week
	for (int i = 0; i < SIZE; i ++) {
		hours[i] = getValidInput(("Enter hours slept on " + DAYS[i] + ": "), 
								"Error: Input must be between 0 and 24 hours.", 0, 24);
		
		// Add day's hours slept to total						
		total += hours[i];
		
		// Increment quantity based on a young adult's recommended hours of sleep in a given night
		if (hours[i] >= 7 && hours[i] <= 9) {
			recommended ++;
		}
		else if (hours[i] < 6 || hours[i] > 11) {
			notRecommended ++;
		}
		else {
			appropriate ++;
		}
	}
	
	// Calculate average hours of sleep per night
	average = total / SIZE;
	
	/** OUTPUT **/
	cout << fixed << setprecision(1)
		<< "\nTotal number of hours slept last week: " << total
		<< "\nAverage number of hours slept per night: " << average;
		
	cout << "\n\nAccording to the NSF, last week you slept:\n"
		<< recommended << ((recommended == 1) ? " night" : " nights")
		<< " of \"recommended\" sleep.\n"
		<< appropriate << ((appropriate == 1) ? " night" : " nights")
		<< " of \"may be appropriate\" sleep.\n"
		<< notRecommended << ((notRecommended == 1) ? " night" : " nights")
		<< " of \"not recommended\" sleep.\n";
		
	cout << "\nOverall, your sleep health (on average) is ";
	
	if (average >= 7 && average <= 9) {
		cout << "\"Recommended\".\n";
	}
	else if (average < 6 || average > 11) {
		cout << "\"Not Recommended\".\n";
	}
	else {
		cout << "\"May be Appropriate\".\n\n";
	}

	system("pause");
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
