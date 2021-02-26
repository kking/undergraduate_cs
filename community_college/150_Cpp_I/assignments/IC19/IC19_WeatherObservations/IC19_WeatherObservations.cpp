/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #19
* LAST MODIFIED:	11/01/18
*
* Weather Observations ********************************************************
*
* PROGRAM DESCRIPTION: 
* This program will use a structure WeatherReport to record weather observations, which
* include a data in the form MM/DD/YY, time (e.g. 11:00 PDT), zipcode (e.g. 92056), temperature,
* humidity percentage, visibility, and a string "IMPERIAL" or "METRIC" to determine if units are in
* Fahrenheit/miles or Celsius/kilometers.
* 
* ALGORITHM:
* 1.  PROMPT "Enter date ... MM/DD/YY: "
* 2.  READ Weather's date
* 3.  PROMPT "Enter time: "
* 4.  READ Weather's time
* 5.  PROMPT "Enter zip code: "
* 6.  READ Weather's zip code
* 7.  PROMPT "Enter temperature: "
* 8.  READ Weather's temperature
* 9.  PROMPT "Enter humidity: "
* 10. READ Weather's humidity as a value >= 0
* 11. PROMPT "Enter visibility: "
* 12. READ Weather's visibility as a value >= 0
* 13. PROMPT "Enter units (IMPERIAL OR METRIC)
* 14. READ units as "IMPERIAL" or "METRIC"
* 15. PRINT weather report populated by the above values
*           "~~~ Weather Report ~~~"
*           "On {date} @ {time}, zip code {zip code}
*            experienced a temperature of {temperature}
*            {"F"/"C"}, humidity {humidity}% and visibility
*            of {visibility} {"miles"/"km"}."
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

struct Weather {
	string date, time, zipcode, units;
	int temperature, humidity;
	double visibility;	
};

/** FUNCTION PROTOTYPES **/
void printWeatherReport(Weather observation);
double getValidInput(string message, string error, double min, double max)

int main(int argc, char** argv) {

	Weather observation;
	
	// Obtain input for all members of observation
	cout << "Enter date in the form MM/DD/YY: ";
	cin >> observation.date;
	
	cout << "Enter time: ";
	cin.ignore(INT_MAX, '\n');
	getline(cin, observation.time);
	
	cout << "Enter zip code: ";
	cin >> observation.zipcode;
	
	cout << "Enter temperature: ";
	cin >> observation.temperature;
	
	cout << "Enter humidity: ";
	cin >> observation.humidity;
	
	cout << "Enter visibility: ";
	cin >> observation.visibility;
	
	cout << "Enter units (IMPERIAL or METRIC): ";
	cin >> observation.units;

	// Print submitted data in a formatted message
	printWeatherReport(observation);
	
	system("pause");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/
/**
 * Prints the constituent data of a given Weather structure in a formatted message,
 * which includes the observation's date, time, zip code, temperature (in Fahrenheit or
 * Celsius), humidity and visibility (in miles). 
 *
 * @param observation a Weather structure
 */
void printWeatherReport(Weather observation) {
	cout << "~~~Weather Report~~~" << endl
		<< "On " << observation.date << " @ " << observation.time
		<< ", zip code " << observation.zipcode
		<< " experienced a temperature of " << observation.temperature " degrees ";
		
		// Validate temperature as Fahrenheit or Celsius and print accordingly
		if (observation.units == "IMPERIAL")
			cout << "F";
		else if (observation.units == "METRIC")
			cout << "C";
		
		cout << ", humidity " << observation.humidity 
			<< "% and visibility of " << observation.visibility;
			
		// Validate visibility distance as miles or kilometers
		if (observation.units == "IMPERIAL")
			cout << "miles.";
		else if (observation.units == "METRIC")
			cout << "km.";			
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
double getValidInput(string message, string error, double min, double max) {
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
