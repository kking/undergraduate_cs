/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #03
* LAST MODIFIED:	09/03/18
*
* Total Purchase **************************************************************
*
* PROGRAM DESCRIPTION:
* This program will store the prices of five items as received from the user. Additionally, the prices
* will be displayed to the console with the subtotal of the sale, the sales tax (7.75%), and the total
* amount of the sale. 
*
* ALGORITHM:
* 1. READ prices of five items into five independent variables
* 2. CALCULATE the subtotal as the sum of the five items' prices
* 3. CALCULATE the tax amount = subtital * 0.00775
* 4. CALCULATE the total sale amount
* 5. DISPLAY the prices of the five items, the subtotal of the sale, the sales tax, and total sale amount
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
	const double TAX_PERCENTAGE = 0.0775; // Sales tax, 7.75%
	const int COLUMN_WIDTH = 20; // A set width for each column of the bill output
	
	/** DECLARATIONS **/
	double itemOne, itemTwo, itemThree, itemFour, itemFive,
		subtotal, tax, totalAmount;
		
	/** INPUT **/
	cout << "Price of item 1 = $";
	cin >> itemOne;
	
	cout << "Price of item 2 = $";
	cin >> itemTwo;
	
	cout << "Price of item 3 = $";
	cin >> itemThree;
	
	cout << "Price of item 4 = $";
	cin >> itemFour;
	
	cout << "Price of item 5 = $";
	cin >> itemFive;
	
	/** PROCESSING **/
	subtotal = (itemOne + itemTwo + itemThree + itemFour + itemFive);
	tax = (subtotal * TAX_PERCENTAGE);
	totalAmount = (subtotal + tax);
	
	/** OUTPUT **/
	// Display a formatted list of the receipt
	cout << left << fixed << setprecision(2)
		<< setw(COLUMN_WIDTH) << "\nItem One" << "$" << itemOne
		<< setw(COLUMN_WIDTH) << "\nItem Two" << "$" << itemTwo
		<< setw(COLUMN_WIDTH) << "\nItem Three" << "$" << itemThree
		<< setw(COLUMN_WIDTH) << "\nItem Four" << "$" << itemFour
		<< setw(COLUMN_WIDTH) << "\nItem Five" << "$" << itemFive
		<< "\n--------------------------------"
		<< setw(COLUMN_WIDTH) << "\nSubtotal" << "$" << subtotal
		<< setw(COLUMN_WIDTH) << "\nSales Tax" << "$" << tax
		<< setw(COLUMN_WIDTH) << "\nTotal" << "$" << totalAmount;
	
	return 0;
}
