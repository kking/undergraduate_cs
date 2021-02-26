#include <iostream>
#include <cstdlib>

#include "Computer.h"
#include "Laptop.h"

using namespace std;

// Constant allocating size to the two arrays
const int SIZE = 30;

// Function Prototypes
void printMenu();
bool addComputer(Computer cList[SIZE], Laptop lList[SIZE], int& numC, int& numL);
void displayComputers(Computer cList[SIZE], Laptop lList[SIZE], int numC, int numL);
double getValidInput(string m, string e, double min, double max);

int main(int argc, char* argv[])
{
	Computer cList[SIZE];
	Laptop lList[SIZE];
	int numC = 0, numL = 0, option;
	
	do  {
		printMenu();
		cin >> option;
		
		switch (option) {
			case 1: // Add computer to inventory
				addComputer(cList, lList, numC, numL);
				break;
			case 2: // Display entire inventory
				displayComputers(cList, lList, numC, numL);
				break;
			case 3: // Quit
				cout << endl << "Thanks!!" << endl;
				break;
			default:
				cout << "Invalid option.";
				break;
		} // switch
		
		cout << endl;
		
	} while (option != 3);
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

// Prints Computer Depot menu to console.
void printMenu() {
	cout
		<< "*************************************************************************\n"
		<< "**                 Welcome to the Computer Depot                       **\n"
		<< "*************************************************************************\n"
		<< "** Please enter choice :                                               **\n"
		<< "** 1) Add computer to inventory                                        **\n"
		<< "** 2) Display entire inventory                                         **\n"
		<< "** 3) Quit                                                             **\n"
		<< "*************************************************************************\n";
}

// Adds a new Computer or Laptop to either of the given collections.
bool addComputer(Computer cList[SIZE], Laptop lList[SIZE], int& numC, int& numL) {
	// For defining member variables of a new Computer or Laptop
	string make, model;
	double price, batteryLife, weight;
	int option;
	
	// 1. Obtain member variable values from console
	option = getValidInput("Enter 1 for Computer or 2 for Laptop >> ", "Invalid option.", 1, 2);
	
	cout << "Enter make               >> ";
	getline(cin, make);
	
	cout << "Enter model              >> ";
	getline(cin, model);
	
	price = getValidInput("Enter price              >> $", "Value cannot be < 0.", 0, INT_MAX);

	// If the user is adding a new Laptop, obtain additional values
	if (option == 2) {
		batteryLife = getValidInput("Enter battery life (hrs) >> ", "Value cannot be < 0.", 0, INT_MAX);
	
		weight = getValidInput("Enter weight (lbs)       >> ", "Value cannot be < 0.", 0, INT_MAX);
	}
	
	// 2. Add Computer or Laptop to inventory
	if (option == 1 && numC < SIZE) {
		cList[numC++] = Computer(make, model, price);
		return true;
	}
	else if (numL < SIZE){
		lList[numL++] = Laptop(make, model, price, batteryLife, weight);
		return true;
	}
	
	// If the given inventory is full
	return false;
}

// Displays inventories of Computers and Laptops
void displayComputers(Computer cList[SIZE], Laptop lList[SIZE], int numC, int numL) {
	cout
		<< "*************************************************************************\n"
		<< "**                          Entire Inventory                           **\n"
		<< "*************************************************************************\n"
		<< "| Id # | Make       | Model    | Price  | Battery (hrs) | Weight (lbs)  |\n"
		<< "*************************************************************************\n";
	
	// 1. Print each Computer to the console
	for (int i = 0; i < numC; i ++) {
		cout << cList[i] << endl;
	}
	
	// 2. Print each Laptop to the console
	for (int i = 0; i < numL; i++) {
		cout << lList[i] << endl;
	}
	
}

// For input validation
double getValidInput(string m, string e, double min, double max) {
	double input;
	bool inputFail;
	
	do {
		cout << m;
		cin >> input;
		
		inputFail = (cin.fail()) || (input < min) || (input > max);
		
		if (inputFail) {
			cout << e << endl;
			
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (inputFail);
	
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	return input;
}
