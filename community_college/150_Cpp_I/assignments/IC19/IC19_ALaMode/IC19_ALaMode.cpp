/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #19
* LAST MODIFIED:	11/01/18
*
* A La Mode *******************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will determine the mode of a pre-determined collection of integer values.
* 
* ALGORITHM:
* 1.  Create an array of integers; [2, 3, 3, 5, 5, 5, 7, 7, 6, 6, 5]
* 2.  PRINT "Here is the sample data set: " + CALL print array:
* 3.    PRINT "["
* 4.    FOR i = 0 through array size - 1
* 5.      PRINT array[i] + ","
* 6.    PRINT array[size - 1] + "]"
* 7.  END print array
* 8.  CALL get mode with given array
* 9.    Create a parallel array to track the counts of each value in given array
* 10.   FOR i = 0 through array size
* 11.     counts[i] = 0
* 12.   FOR i = 0 through array size
* 13.     value = array[i]
* 14.     FOR j = 0 through array size
* 15.       IF value == array[j]
* 16.         counts[i] ++
* 17.     END FOR
* 18.   END FOR
* 19.   FOR i = 0 through array size
* 20.     IF counts[i] > max count
* 21.       mode = array[i]
* 22.   END FOR
* 23.   RETURN mode
* 24. PRINT "The mode of this data set is: " + mode
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
******************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

/** FUNCTION PROTOTYPES **/
int getMode(int* numbers, int size);
void printArray(int* arr, int size);

int main(int argc, char** argv) {

	// Compile time array to store all elements
	const int SIZE = 11;
	int numbers[] = { 2, 3, 3, 5, 5, 5, 7, 7, 6, 6, 5 };
	
	// Print contents of numbers array
	cout << "Here is the sample data set:\n";
	printArray(numbers, SIZE);
	cout << "\n\n";
	
	// Calculate and print the mode of numbers array
	cout << "The mode of this data set is : " << getMode(numbers, SIZE) << "\n";
	
	system("pause");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/
/**
 * Calculates and returns the mode of a given array of numbers.
 *
 * @param numbers The array of numerical values
 * @param size The size of the given array
 * @return the mode (most frequent occurence), or -1 if none
 */
int getMode(int* numbers, int size) {
	// Parallel array to numbers, reprsenting the number of occurences of value
	int* counts = new int[size];
	int maxCount = 1, mode = -1;
	
	// Initialize each element of counts to 0
	for (int i = 0; i < size; i ++) {
		counts[i] = 0;
	}
	
	// Loop through both numbers and counts
	int value;
	for (int i = 0; i < size ; i ++) {
		
		// Set local variable equal to numbers value at i
		value = numbers[i];
		
		for (int j = 0; j < size; j ++) {
			// If value is equal to numbers at j, 
			// increment value in parallel array reprsenting the number of occurences of value
			if (value == numbers[j]) {
				counts[i] ++;
			}
		}
	}
	
	// Determine mode based on the element/s of the highest count value
	for (int i = 0; i < size; i ++) {
		if (counts[i] > maxCount) {
			// counts at i is parallel to numbers at i
			mode = numbers[i];
		}
	}
	
	// Delete local counts array
	delete[] counts;
	counts = 0;
	
	return mode;
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

