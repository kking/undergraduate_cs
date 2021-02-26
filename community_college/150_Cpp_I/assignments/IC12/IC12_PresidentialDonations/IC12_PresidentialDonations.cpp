/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #12
* LAST MODIFIED:	10/04/18
*
* Presidential Donations ******************************************************
*
* PROGRAM DESCRIPTION: 
* This program will read two files, "clinton2016donations.txt" and "trump2016donations.txt",
* record their respective sums of campaign contributions, and display the largest contribution,
* the smallest contribution, and the average of all contrbutions for each candidate. 
* 
* ALGORITHM:
* 1.  OPEN "clinton2016donations.txt"
* 2.  IF file has not been opened
* 3.    PRINT "Error: file... not found."
* 4.    CLOSE program
* 5.  END IF
* 6.  WHILE end of file has not been reached
* 7.    READ current donation
* 8.    INCREMENT number of donations
* 9.    CALCULATE sum += current donation
* 10.   IF current donation < minimum donation
* 11.     SET minimum donation = current donation
* 12.   IF current donation > maximum donation
* 13.     SET maximum donation = current donation
* 14. END WHILE
* 15. CLOSE "clinton2016donations.txt"
* 16. CALCULATE average = sum / number of donations
* 17. PRINT "For candidate ... "
* 18.       "The number of donations was: " + numDonations
* 19.       "The minimum contribution was: " + minumum
* 20.       "The maximum contribution was: " + maximum
* 21.       "The average contribution was: " + average
* 22.       "The total amount was: " + sum
* 23. REPEAT steps 1 through 22, using "trump2016donations.txt"
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* fstream - enables file I/O
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/** FUNCTION PROTOTYPES **/
int processDonations(string fileName, string candidiate);

int main(int argc, char** argv)
{
	processDonations("clinton2016donations.txt", "Hillary Clinton");
	
	processDonations("trump2016donations.txt", "Donald Trump");
	
	system("PAUSE");
	return EXIT_SUCCESS;
	
} // End of main method

/**
 * Function which records contribution amounts afforded to a given political candidate from
 * a given text file, and prints statistical information for the total number of contributions.
 * 
 * @param fileName the name of the file containing a list of donation values
 * @param candidate the full name of the candidate
 */
int processDonations(string fileName, string candidate) 
{
	int donation, numDonations = 0, min = INT_MAX, max = INT_MIN;
	double sum = 0.0, average;
	
	// Declare an ifstream
	ifstream inFile;
	
	// Open file
	inFile.open(fileName.c_str());
	
	// Check to see if an existing file has been opened
	if (! inFile.is_open()) {
		cout << "Error: File \"" << fileName << "\" not found.\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	// Loop through file until end of file is reached
	while (! inFile.eof()) {
		// Read donation from file
		inFile >> donation;
		numDonations ++;
		
		// Add donation to sum
		sum += donation;
		
		// Determine if donation is min
		if (donation < min)
			min = donation;
			
		// Determine if donation is max
		if (donation > max);
			max = donation;
	}
	
	// Close file
	inFile.close();
	
	// Calculate average donation
	average = sum / numDonations;
	
	// Display donation statistics to console
	cout << "~~~ For candidate " << candidate << " ~~~" << endl
		<< "\nThe number of contributions was:  " << numDonations
		<< fixed << setprecision(2)
		<< "\nThe minimum contribution was:     $" << min
		<< "\nThe maximum contribution was:     $" << max
		<< "\nThe average contribution was:     $" << average
		<< "\nThe total amount contributed was: $" << sum << endl << endl;
		
	return EXIT_SUCCESS;
		
} // End of method processDonations
