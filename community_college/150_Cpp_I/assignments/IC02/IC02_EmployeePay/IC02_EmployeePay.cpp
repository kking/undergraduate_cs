/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #03
* LAST MODIFIED:	08/28/18
*
* Employee Pay ****************************************************************
*
* PROGRAM DESCRIPTION:
* This program will calculate and display an employee's total annual pay based on the 
* number of pay periods in a year multiplied by a pay amount given by the user. 
* 
* ALGORITHM:
* 1. PROMPT "Enter employee's pay amount ... "
* 2. READ pay amount from user
* 3. CALCULATE total annual pay = (pay amount * number of pay periods)
* 4. OUTPUT total annual pay formatted as currency
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
	const int PAY_PERIODS = 26; // named constant- the number of pay periods in a year
	
	/** DECLARATIONS **/
	double payAmount;
	double totalAnnualPay;
	
	/** INTRO **/
	cout << "Enter employee's pay amount (per paycheck): $";
	
	/** INPUT **/
	cin >> payAmount;
	
	/** PROCESSING **/
	totalAnnualPay = (payAmount * PAY_PERIODS);
	
	/** OUTPUT **/
	// fixed => sets to fixed point decimal notation
	// setprecision(int) => formats to given number of decimal places
	cout << fixed << setprecision(2) << "\nThe employee's total annual pay is $" << totalAnnualPay;
	
	return 0;
}
