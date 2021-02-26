/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #13
* LAST MODIFIED:	10/02/18
*
* CS Dashboard ****************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will 
* 
* ALGORITHM:
* 1. 
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
******************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

// Function Prototypes
int dashboardMenu();
double getAgeSuccess(int age);
double getEthnicitySuccess(int ethnicity);
double getAgeAndEthnicitySuccess(int age, int ethnicity);

// Constants
const double AGE_STATISTICS[] = { 71.4, 60.8, 54.6, 57.9, 62.5,
								61.7, 47.1, 65.9, 60.7, 33.3 };
								
const double ETHNICITY_STATISTICS[] = { 66.7, 67.2, 39.2, 48.5, 20.0,
									58.7, 62.8, 53.0 };

int main()
{
	int option, age;
	const string AGE_MESSAGE = "% of students of this age group earn a grade of \"C\" of higher in Computer Science courses.\n\n",
				ETHNICITY_MESSAGE = "";
				EXIT_MESSAGE = "Thank you for exploring the CS Success Dashboard. Let's strive to always do better for students.";
	
	do {
		option = dashboardMenu();
		
		switch (option) {
			case 1:
				cout << "Enter age of student: ";
				cin >> age;
				cout << "\n" << getAgeSuccess(age) << AGE_MESSAGE;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				cout << EXIT_MESSAGE;
				break;
			default:
				cout << "Invalid option. Try again.\n";
		}
		
	} while (option != 4);
	
	system("pause");
	return EXIT_SUCCESS;
}

void printMenuHeader() {
	cout 
		<< "********************************************************************\n"
		<< "**                                                                **\n"
		<< "**                 MIRACOSTA CS SUCCESS DASHBOARD                 **\n"
		<< "**                                                                **\n"
		<< "********************************************************************\n"
}

int dashboardMenu()
{
	int choice;
	
	printMenuHeader();
	cout
		<< "** Please select from the following choices:                      **\n"
		<< "** 1) View Success by Age Group                                   **\n"
		<< "** 2) View Success by Ethnicity                                   **\n"
		<< "** 3) View Success by Ethnicity and Gender (Hacker Challenge)     **\n"
		<< "** 4) Exit                                                        **\n"
		<< "********************************************************************\n";
		
	cin >> choice;
	return choice;
}

int ethnicityMenu() {
	int choice;
	
	printMenuHeader();
	cout
		<< "** Please select from the following ethnicities:                  **\n"
		<< "** 1) American Indian/Alaska Native                               **\n"
		<< "** 2) Asian                                                       **\n"
		<< "** 3) Black/African American                                      **\n"
		<< "** 4) Hispanic                                                    **\n"
		<< "** 5) Pacific Islander                                            **\n"
		<< "** 6) Two or More Races                                           **\n"
		<< "** 7) White                                                       **\n"
		<< "** 8) Unknown                                                     **\n"
		<< "********************************************************************\n";
		
	cin >> choice;
	return getEthnicitySuccess(choice);
}

double getAgeSuccess(int age) {
									
	if (age <= 17)
		return AGE_STATISTICS[0];
	else if (age <= 20)
		return AGE_STATISTICS[1];
	else if (age <= 24)
		return AGE_STATISTICS[2];
	else if (age <= 29)
		return AGE_STATISTICS[3];
	else if (age <= 34)
		return AGE_STATISTICS[4];
	else if (age <= 39)
		return AGE_STATISTICS[5];
	else if (age <= 44)
		return AGE_STATISTICS[6];
	else if (age <= 54)
		return AGE_STATISTICS[7];
	else if (age <= 64)
		return AGE_STATISTICS[8];
	else if (age >= 65)
		return AGE_STATISTICS[9];
}

double getEthnicitySuccess(int ethnicity) {
	switch (ethnicity) {
		case 1: // American Indian/Alaska Native
			break;
		case 2: // Asian
			break;
		case 3: // Black/African American
			break;
		case 4: // Hispanic
			break;
		case 5: // Pacific Islander
			break;
		case 7: // Two or More Races
			break;
		case 8: // White
			break;
		default: // Unknown
			break;
	}
}

double getAgeAndEthnicitySuccess(int age, int ethnicity) {
	return 0.0;
}
