/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #18
* LAST MODIFIED:	10/29/18
*
* Reverser ********************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will read a given number of integer values from the console, print a list of said values
* in addition to a list produced from the original list in reverse order.
* 
* ALGORITHM:
* 1.  PROMPT "How many values...?"
* 2.  READ numValues as an integer >= 1
* 3.  Create a collection to store the given amount of numerical values
* 4.  FOR i = 0 through numValues
* 5.    PROMPT "Enter value #" + i
* 6.    READ values at i as any numerical value
* 7.  END FOR
* 8.  PRINT "The contents of the original array are:"
* 9.  Call method printArray
* 10.   PRINT "["
* 11.   FOR i = 0 through numValues - 1
* 12.     PRINT values at i + ","
* 13.   END FOR
* 14.   PRINT values at numValues - 1 + "]"
* 15. END printArray
* 16. Create a collection to store values of the existing collection in reverse order
* 17. reversedValues = call method reverseArray:
* 18.   count = 0
* 19.   FOR i = numValues - 1 decremented through 0
* 20.     reversedValues at i = values at i
* 21.     count ++
* 22.   END FOR
* 23.   RETURN reversedValues
* 24. PRINT "The contents of the reversed array are:"
* 25. Call method printArray, (steps 9 through 15 for reversedValues)
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

/** FUNCTION PROTOTYPES **/
int* reverseArray(int* original, int size);
void printArray(int* arr, int size);
double getValidInput(string message, string error, double min, double max);

int main(int argc, char** argv) {
	// Declarations
	int* values = NULL;
	int* reversedValues = NULL;
	int numValues;
	
	// Obtain size of which values is dynamically allocated
	numValues = getValidInput("How many values would you like to enter? ", "Error: input must be a numerical value.", 1, INT_MAX);

	// Dynamically allocate the original array
	values = new int[numValues];
	
	cout << endl;
	
	// Populate values with integers received from the user
	for (int i = 0; i < numValues; i ++) {
		cout << "Enter value #" << (i + 1) << ": ";
		values[i] = getValidInput("", "Error: ", INT_MIN, INT_MAX);
	}
	
	// Print contents of original array
	cout << "\nThe contents of the original array are: \n";
	printArray(values, numValues);
	
	// Dynamically allocate the reversed array, calling the reverseArray function 
	// which returns an array whose elements mirror those of values in reverse order
	reversedValues = reverseArray(values, numValues);
	
	// Print contents of reversed array
	cout << "\n\nThe contents of the reversed array are: \n";
	printArray(reversedValues, numValues);
	
	cout << "\n\n";
	
	// Deletes dynamically allocated arrays
	delete[] values; // Prevents memory leak
	delete[] reversedValues;
	values = NULL; // Frees reservation of a location in RAM
	reversedValues = NULL;
	
	system("pause");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/
/**
 * Returns a collection of integer values whose contents are in reverse order of the given.
 *
 * @param original an array containing integer values
 * @param size the size of original
 * @return an array of the given size with integers populated in reverse order of original
 */
int* reverseArray(int* original, int size) {
	// Create new dynamically allocated array, parallel to original
	int* reversedArray = new int[size];
	
	// To be incremented in following loop to populate reversedArray in ascending order
	int count = 0;
	
	// Loop through original in descending order from its last index
	for (int i = (size - 1); i >= 0; i --) {
		reversedArray[count] = original[i];
		count ++;
	}
	
	return reversedArray;
}

/**
 * Prints the formatted contents of the given array.
 *
 * @param arr pointer to an existing array
 * @param size the size of arr
 */
void printArray(int* arr, int size) {
	// Print opening bracket
	cout << "[";
	// Print elements 0 through size - 1, separated by commas
	for (int i = 0; i < (size - 1); i ++) {
		cout << arr[i] << ", ";
	}
	// Print final element and closing bracket
	cout << arr[size - 1] << "]";
}

/**
 * Function handling input validation.
 *
 * @param message a custom message prompting for user input
 * @param error an error message to be presented in the case of erroneous input
 * @param min the minimum numerical value for user input
 * @param max the maximum numerical value for user input
 * @return a valid number entered by the user
 */
double getValidInput(string message, string error, double min, double max) 
{
	bool inputFail;
	double input;
	
	do {
		cout << message;
		cin >> input;
		
		// Input validation;
		// fails if wrong data type is read, or input > max or < min
		inputFail = cin.fail() || (input < min) || (input > max);
		
		if (inputFail) {
			cout << error << endl;
			cin.clear();               // Clears error flag
			cin.ignore(INT_MAX, '\n'); // Ignores characters up to new line character
		}
		
	} while (inputFail);

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	return input;
}
