/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #20
* LAST MODIFIED:	11/05/18
*
* MiraCosta Parking App *******************************************************
*
* PROGRAM DESCRIPTION: 
* This program will utilize a structure of type name Vehicle and an enum of automobile 
* types to populate a multi-dimensional array representing spaces of MiraCosta's OC-5A 
* parking lot.
* 
* ALGORITHM:
* 1.  PRINT app header, "MIRACOSTA ... PARKING LOT APP"
* 2.  FOR i = 0 through 7 rows
* 3.    FOR j = 0 through 20 columns
* 4.      assign a random passNumber for current Vehicle at lot[i][j]
* 5.      assign a random year for current Vehicle at lot[i][j]
* 6.      assign a random AutoType (name of make) for current Vehcicle at lot [i][j]
* 7.      PRINT Vehicle's lot #, passNumber, year, and AutoType
* 8.      increment space # for next Vehicle to occupy
* 9.    END FOR
* 10. END FOR 
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - manipulation of I/O
* ctime - functions which handle information with this system's time
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// An enumeration to contain names of Vehicle makes
enum AutoType {
	BMW, Ford, Kia, Mercedes, Toyota, Chevrolet
};

// A structure which stores information of a automotive vehicle
struct Vehicle {
	int passNumber, year;
	AutoType make;
};

/** FUNCTION PROTOTYPES **/
string convertTypeToString(AutoType type);
void printAppHeader();

/** CONSTANTS **/
const int ROWS = 7, COLUMNS = 20, TABLE_WIDTH = 15;

int main(int argc, char** argv) {
	// A two-dimsional array to represent the Mordor Lot
	Vehicle mordorLot[ROWS][COLUMNS];
	
	// To randomize numbers, "seed" random number generator based on system clock
	srand(time(NULL));
	
	printAppHeader();

	int spaceNumber = 1;
	// Initialize values for each space with Vehicles of randomly generated values
	for (int i = 0; i < ROWS; i ++) {
		for (int j = 0; j < COLUMNS; j ++) {
			// Assign a random passNumber for current Vehicle
			mordorLot[i][j].passNumber = (rand() % 9000) + 1000;
			// Assign a random year for current Vehicle
			mordorLot[i][j].year = (rand() % 135) + 1885;
			// Assign a random AutoType for current Vehicle
			mordorLot[i][j].make = static_cast<AutoType>((rand() % (Chevrolet - BMW + 1)) + BMW); 
			
			// Print Vehicle's member values and its location in Mordor to the console
			cout << left << setw(TABLE_WIDTH) << spaceNumber
				<< setw(TABLE_WIDTH) << mordorLot[i][j].passNumber
				<< setw(TABLE_WIDTH) << convertTypeToString(mordorLot[i][j].make)
				<< setw(TABLE_WIDTH) << mordorLot[i][j].year << endl;	
			
			// Increment space # for next Vehicle to occupy
			spaceNumber ++;
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/

// Prints the app's header to the console
void printAppHeader() {
	cout 
		<< "******************************************************\n"
		<< "                  MIRACOSTA COLLEGE                   \n"
		<< "                OC-5A PARKING LOT APP                 \n"
		<< "******************************************************\n"
		<< "SPACE #        PASS #         MAKE           YEAR\n"
		<< "******************************************************" << endl;
}

// Converts the given type of AutoType to a string
string convertTypeToString(AutoType type) {
	string types[] = { "BMW", "Ford", "Kia", "Mercedes", "Toyota", "Chevrolet" };
	
	return types[type];
}

