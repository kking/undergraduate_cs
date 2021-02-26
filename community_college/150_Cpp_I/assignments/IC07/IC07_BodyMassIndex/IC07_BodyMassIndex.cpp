/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #07
* LAST MODIFIED:	09/17/18
*
* Body Mass Index *************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will calculate and display a sedentary person's body mass index (BMI) 
* based on valid weight and height values ( <= 0) given by the user. 
* 
* ALGORITHM:
* 1. PROMPT "Enter weight in lbs"
* 2. READ weight
* 3. IF weight <= 0
* 4.   PRINT "Weight must be greater than 0 lbs"
* 5.   TERMINATE program
* 6. END IF
* 7. PROMPT "Enter height in inches"
* 8. READ height
* 9. IF height <= 0
* 10.   PRINT "Height must be greater than 0 in"
* 11.   TERMINATE program
* 12. CALCULATE BMI = (weight * 703) / (height^2)
* 13. PRINT "Your BMI is: " BMI formatted to one decimal
* 14. PRINT "The National Heart, Lung and Blood Institute category is "
* 15. IF BMI >= 30
* 16.   PRINT "Obese"
* 17. ELSE IF BMI >= 25 and BMI <= 29.9
* 18.   PRINT "Overweight"
* 19. ELSE IF BMI >= 18.5 and BMI <= 24.9
* 20.   PRINT "Normal"
* 21. ELSE
* 22.   PRINT "Underweight"
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* cmath - for use of mathematical functions
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv) 
{
	/** DECLARATIONS **/
	double weight, height, bodyMassIndex;
	
	/** INPUT **/
	// Read weight
	cout << "Enter weight in lbs: ";
	cin >> weight;
	
	// Validate input for weight
	if (weight <= 0)
	{
		cout << "\nWeight must be greater than 0 lbs.\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	// Read height
	cout << "Enter height in inches: ";
	cin >> height;
	
	// Validate input for height
	if (height <= 0)
	{
		cout << "\nHeight must be greater than 0 inches.\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	/** PROCESSING **/
	// Calculate BMI
	bodyMassIndex = ((weight * 703) / (pow(height, 2)));
	
	/** OUTPUT **/	
	cout << fixed << setprecision(1)
		<< "\nYour BMI is: " << bodyMassIndex << endl
		<< "The National Heart, Lung and Blood Institute category is ";
	
	// Print weight category based on BMI value	
	if (bodyMassIndex >= 30)
		cout << "Obese \n";
	else if (bodyMassIndex >= 25 && bodyMassIndex <= 29.9)
		cout << "Overweight \n";
	else if (bodyMassIndex >= 18.5 && bodyMassIndex <= 24.9)
		cout << "Normal \n";
	else
		cout << "Underweight \n";
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
