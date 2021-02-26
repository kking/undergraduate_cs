/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #06
* LAST MODIFIED:	09/06/18
*
* Blood Alcohol Content *******************************************************
*
* PROGRAM DESCRIPTION: 
* This program will calculate and print the blood alcohol content based on the number of 
* drinks(assuming there are 1.5 ounces of alcohol in every drink) and weight received from 
* the user. If the user's BAC exceeds the state's legal limit, a message declaring that they
* are legally intonixated will be presented in the console.
* 
* ALGORITHM:
* 1. PROMPT user to enter number of alcoholic drinks consumed
* 2. READ number of drinks
* 3. PROMPT user to enter weight in pounds
* 4. READ weight in pounds
* 5. CALCULATE BAC = (4.136 * number of drinks * drink in oz) / weight
* 6. PRINT BAC formatted to 3 decimal places
* 7. IF the BAC is >= 0.08
*	     PRINT "According to the state of California, you are legally intoxicated."
*    ELSE
* 	     PRINT "You are not legally intoxicated."
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
	const double OUNCES_OF_ALCOHOL = 1.5, LEGAL_BAC = 0.08;
	
	/** DECLARATIONS **/
	double numberOfDrinks, weight, bloodAlcoholContent;
	
	/** INPUT **/
	cout << "Enter the number of alcoholic drinks consumed: ";
	cin >> numberOfDrinks;
	
	cout << "Please enter your weight in lbs: ";
	cin >> weight;
	
	/** PROCESSING **/
	bloodAlcoholContent = (4.136 * numberOfDrinks * OUNCES_OF_ALCOHOL) / weight;
	
	/** OUTPUT **/
	cout << fixed << setprecision(3) << "\nYour BAC is " << bloodAlcoholContent << endl;
	
	// If the user's BAC exceeds the legal limit, present a message stating that they are
	// legally intoxicated. Otherwise, present a message stating that they are not. 
	if (bloodAlcoholContent >= LEGAL_BAC)
	{
		cout << "According to the state of California, you are legally intoxicated.";
	}
	else 
	{
		cout << "You are not legally intoxicated.";
	}
		
	return 0;
}
