/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #05
* LAST MODIFIED:	09/10/18
*
* Currency Converter **********************************************************
*
* PROGRAM DESCRIPTION: 
* This program will convert given U.S. dollar amounts to five other denominations of currency using
* the most up-to-date exchange rates.
* 
* ALGORITHM:
* 1. PROMPT user to enter an amount in USD
* 2. READ amount in USD
* 3. CALCULATE the equivalent amount in each of the five currencies 
* 4. PRINT the amount of each currency to the user
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
	const int COLUMN_WIDTH = 24;
	const double GBP_PER_DOLLAR = 0.77421,	// Global British Pound, 2018-09-10 06:40 UTC
		CAD_PER_DOLLAR = 1.31832,			// Canadian Dollar, 2018-09-10 06:40 UTC
		EUR_PER_DOLLAR = 0.86577,			// Euro, 2018-09-10 06:40 UTC
		AUD_PER_DOLLAR = 1.40641,			// Australian Dollar, 2018-09-10 06:40 UTC
		SGD_PER_DOLLAR = 1.38064;			// Singapore Dollar, 2018-09-10 06:40 UTC
	
	/** DECLARATIONS **/
	double amountUSD;
	
	/** INPUT **/
	// Step 1: Read amount in USD
	cout << "Enter amount in U.S. dollars: $";
	cin >> amountUSD;
	
	/** OUTPUT **/
	// Step 2-3: Calculate and display the equivalent amounts in GBP, CAD, EUR, AUS, and SGD
	cout << fixed << setprecision(2)
		<< "\n" << amountUSD << " USD is ... \n\n"
		<< (amountUSD / GBP_PER_DOLLAR) << " GBP\n"
		<< (amountUSD / CAD_PER_DOLLAR) << " CAD\n"
		<< (amountUSD / EUR_PER_DOLLAR) << " EUR\n"
		<< (amountUSD / AUD_PER_DOLLAR) << " AUD\n"
		<< (amountUSD / SGD_PER_DOLLAR) << " SGD\n";
		
	return 0;
}
