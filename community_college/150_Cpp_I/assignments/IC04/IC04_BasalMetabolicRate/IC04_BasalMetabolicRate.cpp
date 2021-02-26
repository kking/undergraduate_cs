/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #04
* LAST MODIFIED:	09/04/18
*
* Basal Metabolic Rate ********************************************************
*
* PROGRAM DESCRIPTION: 
* This program will estimate the number of calories the user expends at rest using the Harris-
* Benedict equations for determining the Basal Metabolic Rate (BMR). 
* 
* ALGORITHM:
* 1. READ weight in pounds
* 2. READ height in inches
* 3. READ age in years
* 4. CALCULATE female BMR (calories) = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age)
* 5. CALCULATE male BMR =  66 + (6.23 * weight) + (12.7 * height) - (6.8 * age)
* 6. PRINT BMR for women and men
* 7. PRINT number of chocolate bars to be consumed to maintain weight for women and men
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
	int weight, height, age;
	double femaleBMR, maleBMR;
	
	/** INPUT **/
	cout << "Please enter your weight (lb): ";
	cin >> weight;
	
	cout << "Please enter your height (in): ";
	cin >> height;
	
	cout << "Please enter your age: ";
	cin >> age;
	
	/** PROCESSING **/
	femaleBMR = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	maleBMR = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	
	/** OUTPUT **/
	cout << fixed << setprecision(0)
		<< "\nBMR (female): " << femaleBMR << " calories"
		<< "\nBMR (male): " << maleBMR << " calories" << endl
		<< setprecision(1)
		<< "\nIf you are female, you need to consume " << (femaleBMR / CHOCOLATE_BAR_CALORIES) << " chocolate bars to maintain weight."
		<< "\nIf you are male, you need to consume " << (maleBMR / CHOCOLATE_BAR_CALORIES) << " chocolate bars to maintain weight." << endl;
	
	return 0;
}
