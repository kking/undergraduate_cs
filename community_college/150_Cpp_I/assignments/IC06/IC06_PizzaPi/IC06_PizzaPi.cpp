/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #06
* LAST MODIFIED:	09/06/18
*
* Pizza Pi ********************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will calculate and display the number of slices a pizza of any size can
* be divided into.
* 
* ALGORITHM:
* 1. PROMPT "What is the diameter of the pizza in inches?"
* 2. READ diameter of pizza
* 3. PROMPT "How many people are attending the party?
* 4. READ number of people
* 5. CALCULATE area of pizza = pi * (diameter / 2)^2
* 6. CALCULATE number of slices per pizza = area / 14.125 inches
* 7. CALCULATE number of pizzas to order = (number of people * 2.5 slices) / slices per pizza
* 8. PRINT number of slices in one pizza, number of slices per person (2.5), and number of pizzas to order
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* cmath - enables use of mathematic functions
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv) 
{
	/** CONSTANTS **/
	const double AVERAGE_SLICES_PER_PERSON = 2.5, 
		SLICE_AREA = 14.125; // Each slice of pizza should be 14.125 sq. in.

	/** DECLARATIONS **/
	double diameter, area, totalSlices;
	int numPeople, numPizzas;

	/** INPUT **/
	cout << "What is the diameter of the pizza (in inches)? ";
	cin >> diameter;
	
	cout << "How many people are attending the party? ";
	cin >> numPeople;
	
	/** PROCESSING **/
	area = M_PI * pow((diameter / 2), 2);
	totalSlices = area / SLICE_AREA;
	numPizzas = round((numPeople * AVERAGE_SLICES_PER_PERSON) / totalSlices);
	
	/** OUTPUT **/
	cout << fixed << setprecision(1)
		<< "\nThe total slices in one pizza is: " << totalSlices
		<< "\nIf each of the " << numPeople << " people eats an average of " << AVERAGE_SLICES_PER_PERSON
		<< " slices, you will need to order " << numPizzas << " pizzas.\n";
	
	return 0;
}
