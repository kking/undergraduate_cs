/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #06
* LAST MODIFIED:	09/13/18
*
* Basal Metabolic Rate Part Deux **********************************************
*
* PROGRAM DESCRIPTION: 
* As an extension of IC04_BasalMetabolicRate, this program will calculate and print 
* the user's Basal Metabolic Rate based on the ..., in addition to their gender and 
* activity level as rated on a scale of 1 (sedentary) through 4 (highly active).
* 
* ALGORITHM:
* 1. PROMPT "Enter weight in pounds"
* 2. READ weight in pounds
* 3. PROMPT "Enter height in inches"
* 4. READ height in inches
* 5. PROMPT "Enter age in years"
* 6. READ age
* 7. PROMPT "Enter Male or Female"
* 8. READ gender
* 7. PROMPT "Enter activity level; 1 (Sedentary), 2 (Somewhat active), 3 (Active),
*    or 4 (Highly active).
* 8. READ activity level
* 9. IF (gender == "Female")
*      CALCULATE BMR = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age)
*    ELSE IF (gender == "Male")
*      CALCULATE BMR = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age)
* 10. IF (activity level == 1)
*       CALCULATE BMR = BMR * 1.2
*     ELSE IF (activity level == 2)
*       CALCULATE BMR = BMR * 1.3
*     ELSE IF (activity level == 3)
*       CALCULATE BMR = BMR * 1.4
*     ELSE, activity level is assumed 4
*       CALCULATE BMR = BMR * 1.5
* 11. CALCULATE number of chocolate bars = BMR / 230 calories
* 12. PRINT BMR and number of alotted chocolate bars
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
	const int CHOCOLATE_BAR_CALORIES = 230;
	
	/** DECLARATIONS **/
	int weight, height, age, activityLevel;
	double basalMetabolicRate, numberOfChocolateBars;
	string gender;
	
	/** INPUT **/
	cout << "Enter weight in pounds:\n";
	cin >> weight;
	
	cout << "Enter height in inches:\n";
	cin >> height;
	
	cout << "Enter age in years:\n";
	cin >> age;
	
	cout << "Please enter Male or Female:\n";
	cin >> gender;
	
	cout << "Please enter the number corresponding with your activity factor:\n"
		<< "1. Sedentary (not active)\n"
		<< "2. Somewhat active (exercise occasionally)\n"
		<< "3. Active (exercise 3-4 times per week)\n"
		<< "4. Highly active (exercise every day)" << endl;
	cin >> activityLevel;
	
	/** PROCESSING **/
	if ((gender == "Female") || (gender == "female"))
	{
		basalMetabolicRate = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);	
	}
	else if ((gender == "Male") || (gender == "male"))
	{
		basalMetabolicRate = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);	
	}
	
	// Apply activity level multiplier to calculated BMR
	if (activityLevel == 1) // sedentary
	{
		basalMetabolicRate *= 1.2;
	}
	else if (activityLevel == 2) // somewhat active
	{
		basalMetabolicRate *= 1.3;
	}
	else if (activityLevel == 3) // active
	{
		basalMetabolicRate *= 1.4;
	}
	else // highly active
	{
		basalMetabolicRate *= 1.5;
	}
	
	// Calculate number of allotted chocolate bars
	numberOfChocolateBars = (basalMetabolicRate / CHOCOLATE_BAR_CALORIES);
	
	/** OUTPUT **/
	cout << fixed << setprecision(0)
		<< "As a " << gender << " your BMR x Activity Factor is "
		<< basalMetabolicRate << " and you need to eat "
		<< setprecision(1)
		<< numberOfChocolateBars << " chocolate bars to maintain this amount "
		<< "of calories.\n";
		
	return 0;
}
