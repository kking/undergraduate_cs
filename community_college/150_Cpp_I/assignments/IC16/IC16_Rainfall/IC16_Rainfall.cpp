/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #16
* LAST MODIFIED:	10/22/18
*
* Rainfall ********************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will receive data for the amount of rainfall per month in a year, store
* the data into an array, and calculate and display a record for the total, average,
* minimum month and maximum month's worth in rainfall.
* 
* ALGORITHM:
* 1.  FOR every month of the year, January through December
* 2.    PROMPT "Enter rainfall amount (in inches) for " + current month
* 3.    READ current month's rainfall as a positive numerical value
* 4.    total += current month's rainfall
* 5.    IF current month's rainfall > maximum
* 6.      maximum = current month's rainfall
* 7.    IF current month's rainfall < minimum
* 8.  END FOR
* 9.  CALCULATE average = total / size
* 10. PRINT "Total Rainfall for the Year (in inches): " + total
* 12. PRINT "Average Rainfall for the Year (in inches): " + average
* 13. PRINT "Minumum Monthly Rainfall (in inches): " + minimum
* 14. PRINT "Maximum Monthly Rainfall (in inches): " + maximum
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
	/** Number of months. */
	const int SIZE = 12;
	/** Names indices for parallel array storing monthly rainfall. */
	const string MONTHS[] = { "January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December" };
	
	double monthlyRainfall[SIZE];
	double total = 0.0, average, minimum = INT_MAX, maximum = INT_MIN;
	
	// Loop through each month to collect rainfall values
	for (int i = 0; i < SIZE; i ++) {
		monthlyRainfall[i] = getValidInput(("Enter rainfall amount (in inches) for " + MONTHS[i] + " >> "),
										"Error: Rainfall value cannot be < 0 inches.", 0, INT_MAX);			
			
		// Add current month's rainfall to total	
		total += monthlyRainfall[i];
		
		// Update if current month's rainfall is the minimum or maximum						
		if (monthlyRainfall[i] > maximum) {
			maximum = monthlyRainfall[i];
		}
		if (monthlyRainfall[i] < minimum) {
			minimum = monthlyRainfall[i];
		}		
	}
	
	// Calculate the average rainfall for the year
	average = total / SIZE;

	// Print statistics for this year's rainfall
	cout << fixed << setprecision(2)
		<< "\nTotal Rainfall for the Year (in inches): " << total
		<< "\nAverage Rainfall for the Year (in inches): " << average
		<< "\nMinumum Monthly Rainfall (in inches): " << minimum
		<< "\nMaximum Monthly Rainfall (in inches): " << maximum << "\n\n";

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
	
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	return input;
}
