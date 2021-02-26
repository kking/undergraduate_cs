/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #19
* LAST MODIFIED:	11/01/18
*
* Student Budget **************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will create a MonthlyBudget structure designed to hold expenditure categories
* on housing, utilities, household, transportation, food, insurance, entertainment, clothing, and
* miscellaneous. One variable will store target values, and another will read values received
* from the console. Then, a formatted report of the amounts spent over/under the target expenditures.
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

struct MonthlyBudget {
	double housing, utilities, household, transportation, food,
		medical, insurance, entertainment, clothing, misc;
	
};

/** CONSTANTS **/
const int COLUMN_WIDTH = 30;

/** FUNCTION PROTOTYPES **/
void printMonthlyReport(MonthlyBudget target, MonthlyBudget actual);
double getValidInput(string message, string error, double min, double max);

int main(int argc, char** argv) {
	
	const double TARGET_VALUES[] = {500.00, 150.00, 65.00, 50.00,
								250.00, 30.00, 100.00, 150.00,
								75.00, 50.00};
	MonthlyBudget target, actual;
	
	// Store target values for monthly budget, statically defined
	target.housing = TARGET_VALUES[0];
	target.utilities = TARGET_VALUES[1];
	target.household = TARGET_VALUES[2];
	target.transportation = TARGET_VALUES[3];
	target.food = TARGET_VALUES[4];
	target.medical = TARGET_VALUES[5];
	target.insurance = TARGET_VALUES[6];
	target.entertainment = TARGET_VALUES[7];
	target.clothing = TARGET_VALUES[8];
	target.misc = TARGET_VALUES[9];
	
	// Store actual values for monthly budget
	actual.housing = getValidInput("Enter amount spent on housing: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.utilities = getValidInput("Enter amount spent on utilities: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.household = getValidInput("Enter amount spent on household expenses: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.transportation = getValidInput("Enter amount spent on transportation: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.food = getValidInput("Enter amount spent on food: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.medical = getValidInput("Enter amount spent on medical: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.insurance = getValidInput("Enter amount spent on insurance: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.entertainment = getValidInput("Enter amount spent on entertainment: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.clothing - getValidInput("Enter amount spent on clothing: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	actual.misc = getValidInput("Enter miscellaneous spendings: $", "Error: value must be a number >= 0.", 0, INT_MAX);
	
	// Call function which displays a formatted list indicating
	// the difference between the actual and target values, as well
	// as the amount or over the entire monthly budget.
	printMonthlyReport(target, actual);

	system("pause");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/

/**
 * Prints a monthly report of the differences between two MonthlyBudgets. 
 *
 * @param target a MonthlyBudget whose values are the target expenditures for the month
 * @param actual a MonthlyBudget whose values are defined by the user
 */
void printMonthlyReport(MonthlyBudget target, MonthlyBudget actual) {
	double totalTarget = (target.housing + target.utilities + target.household + target.transportation
						+ target.food + target.medical + target.insurance + target.entertainment
						+ target.clothing + target.misc);
						
	double totalActual = (actual.housing + actual.utilities + actual.household + actual.transportation
						+ actual.food + actual.medical + actual.insurance + actual.entertainment
						+ actual.clothing + actual.misc);
						
	cout << "Based on your established target expenditure for this month:\n\n"
		<< fixed << setprecision(2)
		<< left << setw(COLUMN_WIDTH) << "Housing"<< actual.housing - target.housing << endl
		<< setw(COLUMN_WIDTH) << "Utilties" << actual.utilities - target.utilities << endl
		<< setw(COLUMN_WIDTH) << "Household Expenses" << actual.household - target.household << endl
		<< setw(COLUMN_WIDTH) << "Transportation" << actual.transportation - target.transportation << endl
		<< setw(COLUMN_WIDTH) << "Food" << actual.food - target.food << endl
		<< setw(COLUMN_WIDTH) << "Medical" << actual.medical - target.medical << endl
		<< setw(COLUMN_WIDTH) << "Insurance" << actual.insurance - target.insurance << endl
		<< setw(COLUMN_WIDTH) << "Entertainment" << actual.entertainment - target.entertainment << endl
		<< setw(COLUMN_WIDTH) << "Clothing" << actual.clothing - target.clothing << endl
		<< setw(COLUMN_WIDTH) << "Miscellaneous" << actual.misc - target.misc << endl
		<< setw(COLUMN_WIDTH) << "Total amount: " << totalActual - totalTarget << "\n\n";
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
