/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #03
* LAST MODIFIED:	09/03/18
*
* Change Maker ****************************************************************
*
* PROGRAM DESCRIPTION:
* This program will determine the dollars and change to be dispensed from a register in a
* grocery store. The number of $100, $50, $20, $10, $5 and $1 bills, in addition to the number of
* quarters, dimes, nickels, and pennies, will be printed to the console.
*
* ALGORITHM:
* 1. READ amount of money to return
* 2. CALCULATE dollar and cents as independent values
* 3. CALCULATE highest possible return combination of bills and coins through simple arithmetic
* 4. PRINT number of $100s, $50s, $20s, $5s, $1s, quarters, dimes, nickels, and pennies returned
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
	double amount;
	int dollars, cents, 
		hundreds, fifties, twenties, tens, fives, ones, 
		quarters, dimes, nickels, pennies;
	
	/** INPUT **/
	cout << "Enter an amount of money to return: $";
	cin >> amount;
	
	/** PROCESSING **/
	dollars = ((int) amount); // typecast double => int
	cents = ((amount - dollars) * 100);
	
	// Calculate highest possible return combination of bills and coins
	hundreds = (dollars / 100);
	fifties = (dollars % 100) / 50;
	twenties = ((dollars % 100) % 50) / 20;
	tens = (((dollars % 100) % 50) % 20) / 10;
	fives = ((((dollars % 100) % 50) % 20) % 10) / 5;
	ones = (((((dollars % 100) % 50) % 20) % 10) % 5); // surely an elegant solution
	quarters = (cents / 25);
	dimes = (cents % 25) / 10;
	nickels = ((cents % 25) % 10) / 5;
	pennies = (((cents % 25) % 10) % 5);
	
	/** OUTPUT **/
	cout << fixed << setprecision(2)
		<< "\n$" << amount << " can be returned as:\n\n"
		<< hundreds << " $100 bill(s)\n"
		<< fifties << " $50 bills(s)\n"
		<< twenties << " $20 bill(s)\n"
		<< tens << " $10 bill(s)\n"
		<< fives << " $5 bill(s)\n"
		<< ones << " $1 bill(s)\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< quarters << " quarter(s)\n"
		<< dimes << " dime(s)\n"
		<< nickels << " nickel(s)\n"
		<< pennies << " penny(ies)" << endl;
	
	return 0;
}
