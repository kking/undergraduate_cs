/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #18
* LAST MODIFIED:	10/29/18
*
* Movie Buffs *****************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will gather and produce statistical data about the number of movies a given number
* of college students see in a month.
* 
* ALGORITHM:
* 1.  PROMPT "How many movie watchers ...?"
* 2.  READ numWatchers as an integer > 0
* 3.  Create a collection for each buff's name
* 4.  Create a collection for each buff's number of watched movies
* 5.  FOR i = 0 through numWatchers
* 6.    PROMPT "Enter name of movie watcher:"
* 7.    READ name at i
* 8.    PROMPT "Enter number of movies watched:"
* 9.    READ movies watched at i as an integer >= 0
* 10.   total movies += movies watched at i
* 11.   IF movies watched at i > max movies
* 12.     max movies = movies watched at i
* 13.     max watcher = name at i
* 14.   IF movies watched at i < min movies
* 15.     min movies = movies watched at i
* 16.     min watcher = name at i
* 17. END FOR
* 18. CALCULATE average watched = total movies / numWatchers
* 19. PRINT min watcher, min movies, max watcher, max movies, average watched
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
double getValidInput(string message, string error, double min, double max);

int main(int argc, char** argv) {
	
	int numWatchers, totalMovies = 0, minMovies = INT_MAX, maxMovies = INT_MIN;
	string minWatcher = "", maxWatcher = "";
	double averageMovies;
	
	// Parallel arrays tracking watcher names and their movies watched
	string* watchers = 0;
	int* moviesWatched = 0;
	
	// Receive number of watchers surveyed
	numWatchers = getValidInput("How many movie watchers were surveyed? ", "Error: value must be > 0.", 1, INT_MAX);
	
	// Dynamically allocate the two arrays
	watchers = new string[numWatchers];
	moviesWatched = new int[numWatchers];
	
	// Loop through each watcher
	for (int i = 0; i < numWatchers; i ++) {
		// Read name of current student
		cout << "\nEnter name of movie watcher: ";
		cin >> watchers[i];
		
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		
		// Read number of movies watched for current buff
		moviesWatched[i] = getValidInput("Enter number of movies watched: ", "Error: ", 0, INT_MAX);
		
		// Add to sum of all movies watched
		totalMovies += moviesWatched[i];
		
		// Update if current number of movies watched is max or min
		if (moviesWatched[i] > maxMovies) {
			maxMovies = moviesWatched[i];
			maxWatcher = watchers[i];
		}
		if (moviesWatched[i] < minMovies) {
			minMovies = moviesWatched[i];
			minWatcher = watchers[i];
		}
	}
	
	// Calculate average number of movies watched among all buffs
	averageMovies = (double)totalMovies / numWatchers;
	
	// Print movie buff statistics
	cout << "\nThe minimum movie watcher is " << minWatcher << " with "
		<< minMovies << ((minMovies == 1) ? " movie" : " movies") << " this month.\n"
		<< "The maximum movie watcher is " << maxWatcher << " with "
		<< maxMovies << ((maxMovies == 1) ? " movie" : " movies") << " this month.\n"
		<< "The average movies watched is " << fixed << setprecision(1) << averageMovies << "\n\n";	
	
	// Deletes dynamically allocated arrays
	delete[] watchers; // Prevents memory leak
	delete[] moviesWatched;
	watchers = 0; 	   // Frees reservation of a location in RAM
	moviesWatched = 0;
	
	system("pause");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/
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
