/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #10
* LAST MODIFIED:	09/26/18
*
* Sales Histogram *************************************************************
*
* PROGRAM DESCRIPTION: 
* Using valid data input for five stores' sales for the current day, this program 
* will simulate a store sales histogram.
* 
* ALGORITHM:
* 1.  FOR each sale value in a collection of five stores
* 2.    PROMPT "Enter today's sales for store #(1-5): "
* 3.    READ temp sale value
* 4.    IF temp sale value is < $0.00
* 5.      PRINT "Error: sale cannot be < $0.00"
* 6.    ELSE
* 7.      current store value = temp sale value
* 8.      total sales += temp sale value
* 9.  END FOR
* 10. CALCULATE average sales =  total sales / 5
* 11. PRINT "Total sales for all stores: $" + total sales
* 12. PRINT "Average sales for all stores: $" + average sales
* 13. PRINT "Histogram of Sales ... "
* 14. FOR each sale value in the collection of five stores
* 15.   CALCULATE number of stars = current store's sales / 100
* 16.   FOR number of stars
* 17.     PRINT "*"
* 18.   END FOR
* 19.   PRINT current store's sales
* 20. END FOR
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
	double stores[5] = { };					   // Array to contain five individual store sales
	double tempSale, totalSales, averageSales;
	int numStars;							   // Temp value for histogram display
	bool inputFail;							   // Sentinel value for input validation
	
	/** INPUT **/
	for (int i = 0; i < 5; i ++)
	{
		cout << "Enter today's sales for store #" << (i + 1) << ": $";
		cin >> tempSale;
		
		// Input validation;
		// Fails if wrong data type is read, or tempSale < $0.00
		inputFail = cin.fail() || (tempSale < 0.0);
			
		if (inputFail) {
			cout << "Error: sale cannot be < $0.00.\n";
			cin.clear();               // Clear error flag
			cin.ignore(INT_MAX, '\n'); // Ignore characters up to new line character
			i --;					   // Decrement i to repeat current iteration
		}
		else {
			stores[i] = tempSale;
			totalSales += tempSale;
		}
	}
	
	/** PROCESSING **/
	averageSales = (totalSales / 5);
	
	/** OUTPUT **/
	cout << fixed << setprecision(2)
		<< "\nTotal sales for all stores: $" << totalSales
		<<  "\nAverage sales for all stores: $" << averageSales << endl
		<< "\nHistogram of Sales (for each store)"
		<< "\n(each * represents $100 in sales):" << endl;
		
	for (int i = 0; i < 5; i ++) 
	{
		numStars = (stores[i] / 100);
		
		cout << "\nStore " << (i + 1) << " sales: ";
		
		for (int j = 0; j < numStars; j++) {
			cout << "*";
		}
	
		cout << fixed << setprecision(2) << " ($" << stores[i] << ")";	
	}
	
	return 0;
}
