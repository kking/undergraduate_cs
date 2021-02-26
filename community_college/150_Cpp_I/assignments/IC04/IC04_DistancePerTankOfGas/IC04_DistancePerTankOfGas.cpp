/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #04
* LAST MODIFIED:	08/30/18
*
* Distance Per Tank of Gas ****************************************************
*
* PROGRAM DESCRIPTION:
* This program will calculate and display the distance a car can travel on one tank of
* gas when driven in town and when driven on the highway.
*
* ALGORITHM:
* 1. PROMPT user to enter the capacity of the gas tank (in gallons)
* 2. READ gas tank capacity
* 3. PROMPT user to enter the car's miles per gallon in the city
* 4. READ MPG in city
* 5. PROMPT user to enter the price per gallon of gas
* 6. READ current gas price per gallon
* 7. CALCULATE the mileage range (in miles) for both city and highway; 
* 	 distance = number of gallons * average miles per gallon
* 8. CALCULATE cost per tank of gas
* 9. OUTPUT mileage range for city and highway as well as the cost per tank of gas
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
	double tankCapacity, cityMPG, highwayMPG, costPerGallon,
		mileageCity, mileageHighway, costPerTank; 
	
	/** INTRO **/
	cout << "~~~ Welcome to the Gas App ~~~\n";
	
	/** INPUT **/
	cout << "\nEnter vehicle's gas tank capacity (gallons): ";
	cin >> tankCapacity;
	
	cout << "Enter vehicle's MPG (city): ";
	cin >> cityMPG;
	
	cout << "Enter vehicle's MPG (highway): ";
	cin >> highwayMPG;
	
	cout << "Enter current gas price (gallon): $";
	cin >> costPerGallon;
	
	/** PROCESSING **/
	mileageCity = tankCapacity * cityMPG;
	mileageHighway = tankCapacity * highwayMPG;
	costPerTank = tankCapacity * costPerGallon;
	
	/** OUTPUT **/
	cout << fixed << setprecision(0)
		<< "\n~~~ Vehicle Statistics~~~\n"
		<< "\nMileage range (city): " << mileageCity << " miles"
		<< "\nMileage range (hwy): " << mileageHighway << " miles"
		<< setprecision(2)
		<< "\nCost per tank of gas: $" << costPerTank << endl;
	
	return 0;
}
