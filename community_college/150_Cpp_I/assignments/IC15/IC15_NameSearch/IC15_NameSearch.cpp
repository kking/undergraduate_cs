/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #15
* LAST MODIFIED:	10/16/18
*
* Name Search *****************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will read two text files, "Girls2018" and "Boys2018", and populate arrays for the top
* 1000 baby names for boys and top 1000 baby names for girls. The user is prompted to enter a name, and
* these arrays will be searched to find and present the ranking of said name for both genders.
* 
* ALGORITHM:
* 1.  OPEN "Girls2018.txt"
* 2.  WHILE inFilehas not reached end of file
* 3.    girlNames[count] = inFile's next line
* 4.    count ++
* 5.  END WHILE
* 6.  CLOSE "Girls2018.txt"
* 7.  REPEAT steps 1 through 6, using "Boys2018.txt" and boyNames[]
* 8.  PROMPT "Please enter a name"
* 9.  READ name
* 10. FOR each element i in girlNames[]
* 11.   IF name == girlNames[i]
* 12.     RETURN i + 1 for girlRank
* 13. END FOR
* 14. RETURN -1 for girlRank as a match was not found
* 15. FOR each element i in boyNames[]
* 16.   IF name == boyNames[i]
* 17.     RETURN i + 1 for boyRank
* 18. END FOR
* 19. RETURN -1 for boyRank as a match was not found
* 20. PRINT "The name " + name " is... "
* 21. IF girlRank > 0
* 22.   PRINT " ranked #" + girlRank + " for girls in 2018."
* 23. ELSE
* 24.   PRINT " is quite unique this year for girls."
* 25. PRINT "The name " + name " is... "
* 26. IF boyRank > 0
* 27.   PRINT " ranked #" + boyRank + " for boys in 2018."
* 28. ELSE
* 29.   PRINT " is quite unique this year for boys."
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* fstream - enables I/O interaction with files
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/** FUNCTION PROTOTYPES **/
int fillArray(string fileName, string names[], int namesSize);
int nameSearch(string target, string names[], int namesSize);

int main(int argc, char** argv) {
	/** CONSTANTS **/
	const int NUM_NAMES = 1000;
	
	/** DECLARATIONS **/
	string girlsFile = "Girls2018", boysFile = "Boys2018";
	string girlNames[NUM_NAMES], boyNames[NUM_NAMES];
	string input;
	int girlRank, boyRank;
	
	if ((! fillArray(girlsFile, girlNames, NUM_NAMES)) || (! (fillArray(boysFile, boyNames, NUM_NAMES)))) {
		cout << "Error: File not found.\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	//fillArray(girlsFile, girlNames, NUM_NAMES);
	//fillArray(boysFile, boyNames, NUM_NAMES);
	
	//for (int i = 0; i < NUM_NAMES; i ++) cout << boyNames[i] + "\n";
	
	// Prompt user to enter a name
	cout << "Please enter a name: ";
	cin >> input;
	
	girlRank = nameSearch(input, girlNames, NUM_NAMES);
	cout << "The name " << input; 
	if (girlRank > 0)
		cout << " is ranked #" << girlRank << " for girls in 2018.\n";
	else
		cout << " is quite unique this year for girls.\n";
		
	boyRank = nameSearch(input, boyNames, NUM_NAMES);
	cout << "The name " << input; 
	if (boyRank > 0)
		cout << " is ranked #" << boyRank << " for boys in 2018.\n";
	else
		cout << " is quite unique this year for boys.\n";
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/
/**
 * Populates an array with names read from a text file ranking the top 1000 boys/girls names.
 *
 * @param fileName a text file containing the top 1000 baby names
 * @param names an array to contain the top 1000 baby names in descending order of popularity
 * @param nameSize the size of the array
 * @return true if the file has successfully been read, false otherwise
 */
int fillArray(string fileName, string names[], int namesSize) {
	// Declare an ifstream
	ifstream inFile;
	
	// Open file
	inFile.open(fileName.c_str());
	
	// Check to see if an existing file has been opened
	if (! inFile.is_open()) {
		cout << "fillArray: inFile.is_open() == false \n"; // logic error checking
		return EXIT_FAILURE;
	}

	// Loop through file until end of file is reached,
	// populating the list of names in the order in which they are read
	int count = 0;
	while (! inFile.eof()) {
		inFile >> names[count];
		count ++;
	}
	
	// Close file
	inFile.close();
	
	return EXIT_SUCCESS;
}

/**
 * Searches for the given name in a list of names read from "Girls2018.txt" or "Boys2018.txt" and-
 * if it exists in the list- returns the ranking in which said name is ordered.
 *
 * @param target the name to be found
 * @param names an array to contain the top 1000 baby names in descending order of popularity
 * @param nameSize the size of the array
 * @return the numerical rank of the baby name if found, -1 otherwise
 */
int nameSearch(string target, string names[], int namesSize) {
	// Search through list of names
	for (int i = 0; i < namesSize; i ++) {
		// If a match is found
		if (target == names[i]) {
			return i + 1;
		}
	}
	// If a match was not found
	return -1;
}

