/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #04
* LAST MODIFIED:	09/06/18
*
* Energy Drink Consumption ****************************************************
*
* PROGRAM DESCRIPTION:
* This program will report a survey of an energy drink company's customers, using figures
* in the form of both percentages and exact numbers of people.
*
* ALGORITHM:
* 1. PRINT introduction to survey, stating that out of 16,500 people surveyed, 15%
*	 purchase one or more energy drinks per week with 58% of them preferring citrus
* 2. CALCULATE exact number of people purchasing >= one energy drink per week
* 3. CALCULATE exact number of people within the 15% demographic that prefer citrus
* 4. PRINT introduction statement rephrased to name the number of people rather than
*	 percentages
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* cmath - enables use of specific mathematical functions
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) 
{
	/** DECLARATIONS **/
	int numCustomers = 16500, numOneOrMore, numCitrus;
	double percentOneOrMore = 15, percentCitrus = 58;
	
	/** INTRO **/
	cout << "A soft drink company has surveyed " << numCustomers << " of its customers on "
		<< "their energy drink consumption. " << percentOneOrMore << "% of those surveyed purchase "
		<< "one or more energy drinks per week, with " << percentCitrus << "% of which preferring "
		<< "citrus-flavored energy drinks." << endl;
	
	/** PROCESSING **/
	numOneOrMore = floor(numCustomers * (percentOneOrMore / 100)); // Percentage within all those surveyed
	numCitrus = floor(numOneOrMore * (percentCitrus / 100)); // Percentage within those who purchase >= one per week
	
	/** OUTPUT **/
	cout << "\nIn other words, out of " << numCustomers << " of those surveyed, " << numOneOrMore
		<< " customers purchase one or more energy drinks per week, with " << numCitrus
		<< " of them preferring that of a citrus flavor." << endl;
		
	return 0;
}
