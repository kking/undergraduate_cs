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
	// Step 1: Prompt user to enter pay amount
	cout << "Enter employee's pay amount (per paycheck): $";
	
	/** INPUT **/
	// Step 2: Read pay check amount from user
	cin >> payAmount;
	
	/** PROCESSING **/
	// Step 3: Calculate total annual pay
	totalAnnualPay = (payAmount * PAY_PERIODS);
	
	/** OUTPUT **/
	// Step 4: Output total annual pay formatted as currency
	cout << fixed 		   // sets to fixed point decimal notation
		<< setprecision(2) // formats to given number of decimal places
		<< "\nThe employee's total annual pay is $" << totalAnnualPay << endl;
	
	return 0;
}
