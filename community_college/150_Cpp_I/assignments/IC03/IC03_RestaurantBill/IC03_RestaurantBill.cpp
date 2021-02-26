/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #03
* LAST MODIFIED:	09/03/18
*
* Restaurant Bill *************************************************************
*
* PROGRAM DESCRIPTION:
* This program will calculate and display the subtotal, tax charge, gratuity fee, and total 
* bill for a restaurant order based the meal cost and tip percentage received from the user
* with 7.75% tax.
*
* ALGORITHM:
* 1. READ cost of meal
* 2. READ tip as a percentage (i.e. 20 == 20%)
* 3. CALCULATE tip = cost of meal * (tip / 100)
* 4. CALCULATE tax = cost of meal * tax percentage <sales tax in Oceanside is 7.75%>
* 5. CALCULATE total bill = cost of meal + tax + tip
* 6. PRINT a formatted list of the bill's subtotal, tax, gratuity, and total
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
	const double TAX_PERCENTAGE = 0.0775; // Oceanside sales tax, 7.75%
	const int COLUMN_WIDTH = 15; // A set width for each column of the bill output
	
	/** DECLARATIONS **/
	double mealCost, tip, tax, totalBill;
	
	/** INPUT **/
	cout << "Enter meal cost: $";
	cin >> mealCost;
	
	cout << "Enter tip amount as a percentage (e.g. 20 = 20%): ";
	cin >> tip;
	
	/** PROCESSING **/
	tax = (mealCost * TAX_PERCENTAGE);
	tip = (mealCost * (tip / 100));
	totalBill = (mealCost + tax + tip);
	
	/** OUTPUT **/
	// Display a formatted list of the bill
	cout << left << fixed << setprecision(2)
		<< "\n-- Bill --"
		<< setw(COLUMN_WIDTH) << "\nSUBTOTAL:" << "$" << mealCost
		<< setw(COLUMN_WIDTH) << "\nTAX:" << "$" << tax
		<< setw(COLUMN_WIDTH) << "\nGRATUITY:" << "$" << tip
		<< setw(COLUMN_WIDTH) << "\nTOTAL:" << "$" << totalBill << endl;
	
	return 0;
}
