/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #11
* LAST MODIFIED:	10/02/18
*
* Average Rainfall ************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will use nested loops and input validation to collect data and calculate
* the average rainfall over a period of years.
* 
* ALGORITHM:
* 1.  DO
* 2.    PROMPT "Please enter number of years ..."
* 3.    READ numYears
* 4.    inputFail = true if input is not a whole number, or numYears <= 0
* 5.    IF (inputFail)
* 6.      PRINT "Error: number of years must be > 0"
* 7.  END DO, WHILE (inputFail)
* 8.  FOR i = 1 through numYeara
* 9.    PRINT "Starting year number " i
* 10.   FOR j = 0 through 12
* 11.     PROMPT "Enter amount of rain for" current month
* 12.     READ rain
* 13.     inputFail = true if input is not a number, or rain < 0.0
* 14.     IF (inputFail)
* 15.       PRINT "Error: amount of rain cannot be < 0 inches."
* 16.       DECREMENT j to repeat reading the rainfall for current month
* 17.     ELSE
* 18.       totalRainfall += rain
* 19.   END FOR
* 20. END FOR
* 21. CALCULATE averageRainfall = totalRainfall / (12 * numYears)
* 22. PRINT "Over " (12 * numYears) " months:"
*           "Total of " totalRainfall " inches of rain"
*           "Average of " averageRainfall " inches per month"
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
	/** CONSTANTS **/
	const string MONTHS[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
								"Jul", "Aug", "Sept", "Oct", "Nov", "Dec" };
	
	/** DECLARATIONS **/
	int numYears;
	double rain, totalRainfall = 0.0, averageRainfall;
	bool inputFail; // Sentinel value for input validation
	
	/** INPUT **/
	// Prompt and read for number of years
	do {
		cout << "Please enter the number of years: ";
		cin >> numYears;
		
		// Input validation;
		// Fails if wrong data type is read, or numYears <= 0
		inputFail = cin.fail() || (numYears <= 0);
		
		if (inputFail) {
			cout << "Error: number of years must be > 0.\n";
			cin.clear();               // Clears error flag
			cin.ignore(INT_MAX, '\n'); // Ignores characters up to new line character
		}
		
	} while (inputFail);
	
	// Read rainfall through a given number of years
	for (int i = 1; i <= numYears; i ++) {
		cout << "\nStarting year number " << i << endl;
		
		// Iterate through each month
		for (int j = 0; j < 12; j ++) {
			cout << "Enter amount of rain for " << MONTHS[j] << ": ";
			cin >> rain;
			
			// Input validation;
			// Fails if wrong data type is read, or rain < 0.0
			inputFail = cin.fail() || (rain < 0.0);
				
			if (inputFail) {
				cout << "Error: amount of rain cannot be < 0 inches.\n";
				cin.clear();               // Clear error flag
				cin.ignore(INT_MAX, '\n'); // Ignore characters up to new line character
				j --;					   // Decrement j to repeat current month iteration
			}
			else {
				totalRainfall += rain; // Otherwise, add given amount to total rainfall
			}
		}
	}
	
	/** PROCESSING **/
	averageRainfall = totalRainfall / (12 * numYears);
	
	/** OUTPUT **/
	cout << fixed << setprecision(2)
		<< "\nOver " << (12 * numYears) << " months: \n"
		<< "Total of " << totalRainfall << " inches of rain\n"
		<< "Average of " << averageRainfall << " inches per month\n\n";
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
