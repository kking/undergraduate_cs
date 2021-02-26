/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #04
* LAST MODIFIED:	09/06/18
*
* Stock Commission ************************************************************
*
* PROGRAM DESCRIPTION:
* This program will determine commissions on the sale of stocks based on information
* received from the user.
*
* ALGORITHM:
* 1. READ number of shares of stock purchased
* 2. READ the price of each share of stock
* 3. READ the commission percentage
* 4. CALCULATE the amount paid for the stock alone
* 5. CALCULATE the amount of the commission
* 6. CALCULATE the total amount paid (stock + commission)
* 7. PRINT the amount paid for the stock, commission amount, and total amount paid
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
	const int COLUMN_WIDTH = 30;
	
	/** DECLARATIONS **/
	int numberOfShares;
	double sharePrice, commissionPercentage, amountPaid, commissionAmount, totalAmount;
	
	/** INPUT **/
	cout << "Enter the number of stock shares purchased: ";
	cin >> numberOfShares;
	
	cout << "Enter the price of each share: $";
	cin >> sharePrice;
	
	cout << "Enter the commission percentage: ";
	cin >> commissionPercentage;
	
	/** PROCESSING **/
	amountPaid = sharePrice * numberOfShares;
	commissionAmount = amountPaid * (commissionPercentage / 100);
	totalAmount = amountPaid + commissionAmount;
	
	/** OUTPUT **/
	cout << left << fixed << setprecision(2) << "\n"
		<< setw(COLUMN_WIDTH) << "Amount paid for stock alone:" << " $" << amountPaid << endl
		<< setw(COLUMN_WIDTH) << "Commission amount:" << " $" << commissionAmount << endl
		<< setw(COLUMN_WIDTH) << "Total amount paid:" << " $" << totalAmount << endl;
	
	return 0;
}
