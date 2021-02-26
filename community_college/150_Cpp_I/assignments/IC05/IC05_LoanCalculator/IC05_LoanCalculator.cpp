/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #05
* LAST MODIFIED:	09/11/18
*
* Loan Calculator *************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will calculate the monthly payment on a loan based on a monthly interest rate, number
* of payments, and loan amount received by the user using the following formula:

* Payment = ((Rate * (1 + Rate)^N) / ((1 + Rate)^N - 1)) * L
*
* Rate refers to the monthly interest rate, which is the annual interest rate divided by 12
* N is the number of payments
* L is the amount of the loan
* 
* ALGORITHM:
* 1. READ loan amount = L
* 2. READ number of payments = N
* 3. READ annual interest rate
* 4. CALCULATE monthly rate, annual rate / 12 = Rate
* 5. CALCULATE monthly payment = ((Rate * (1 + Rate)^N) / ((1 + Rate)^N - 1)) * L
* 6. CALCULATE amount paid back, monthly payment * number of payments
* 7. CALCULATE interest paid, amount paid back - loan amount
* 8. PRINT table which displays loan amount, annual and monthly interest rate, number of payments,
*	 monthly payment, amount paid back, and interest paid
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* cmath - enables use of mathematical functions
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv) 
{
	/** CONSTANTS **/
	const int COLUMN_WIDTH = 25;
	
	/** DECLARATIONS **/
	double loanAmount, annualRate, numPayments, monthlyRate, monthlyPayment, paidBack, interestPaid;
	
	/** INPUT **/
	// Step 1: Read loan amount
	cout << "Enter loan amount: $";
	cin >> loanAmount;
	
	// Step 2: Read number of payments
	cout << "Enter number of payments: ";
	cin >> numPayments;
	
	// Step 3: Read annual interest rate
	cout << "Enter annual interest rate: ";
	cin >> annualRate;
	
	/** PROCESSING **/
	// Step 4: Calculate monthly rate
	monthlyRate = (annualRate / 12);
	
	// Step 5: Calculate monthly payment based on given formula
	monthlyPayment = (monthlyRate / 100) * pow((1 + (monthlyRate / 100)), numPayments);
	monthlyPayment = ((monthlyPayment) / (pow((1 + (monthlyRate / 100)), numPayments) - 1)) * (loanAmount);
	
	// Step 6: Calculate amount paid back
	paidBack = (monthlyPayment * numPayments);
	
	// Step 7: Calculate interest paid
	interestPaid = (paidBack - loanAmount);
	
	/** OUTPUT **/
	// Step 8: Display formatted table of loan details
	cout << left << fixed << setprecision(2) << "\n"
		<< setw(COLUMN_WIDTH) << "Loan Amount: " << "$" << loanAmount << "\n"
		<< setprecision(0)
		<< setw(COLUMN_WIDTH) << "Annual Interest Rate: " << annualRate << " %\n"
		<< setw(COLUMN_WIDTH) << "Monthly Interest Rate: " << monthlyRate << " %\n"
		<< setw(COLUMN_WIDTH) << "Number of Payments: " << numPayments << "\n"
		<< setprecision(2)
		<< setw(COLUMN_WIDTH) << "Monthly Payment: " << "$" << monthlyPayment << "\n"
		<< setw(COLUMN_WIDTH) << "Amount Paid Back: " << "$" << paidBack << "\n"
		<< setw(COLUMN_WIDTH) << "Interest Paid: " << "$" << interestPaid << endl;
	
	return 0;
}
