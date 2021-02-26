#include <iostream>
#include <string>
#include "Coffee.h"

using namespace std;

const int SIZE = 30;

// Function Prototypes
void printMenu();
bool placeOrder(Beverage bOrders[SIZE], Coffee cOrders[SIZE], int& numBeverages, int& numCoffees);
void displayOrders(Beverage bOrders[SIZE], Coffee cOrders[SIZE], int numBeverages, int numCoffees);
double getValidInput(string message, string error, double min, double max);

int main(int argc, char* argv[]) {

	Beverage bOrders[SIZE];
	Coffee cOrders[SIZE];
	int numBeverages = 0, numCoffees = 0;
	int option;
	
	do {
		printMenu();
		cin >> option;
		
		switch (option) {
			case 1: // Place a beverage order
				placeOrder(bOrders, cOrders, numBeverages, numCoffees);
				break;
			case 2: // Display all beverage orders
				displayOrders(bOrders, cOrders, numBeverages, numCoffees);
				break;
			case 3: // Quit
				break;
			default:
				cout << "Thanks for visiting BevMoMo!" << endl;
				break;
				
		} // end switch
		
	} while (option != 3);

	system("pause");
	return 0;
	
} // end main

// Function Implementtations

// Prints menu to welcome user to BevMoMo.
void printMenu() {
	cout << endl
		<< "*************************************************************************\n"
		<< "**                         Welcome to BevMoMo                          **\n"
		<< "*************************************************************************\n"
		<< "** Please enter choice :                                               **\n"
		<< "** 1) Place a beverage order                                           **\n"
		<< "** 2) Display all beverage orders                                      **\n"
		<< "** 3) Quit                                                             **\n"
		<< "*************************************************************************\n"
		<< "=> ";
}

// Adds a new Beverage to the given array of Beverage orders.
bool placeOrder(Beverage bOrders[SIZE], Coffee cOrders[SIZE], int& numBeverages, int& numCoffees) {
	int option;
	string name, roast;
	int calories, size, caffeine;
	
	option = getValidInput("Enter 1 for Beverage or 2 for Coffee >> ","Invalid selection.", 1, 2);

	cout << "Enter beverage name     >> ";
	getline(cin, name);
	
	calories = getValidInput("Enter calories          >> ",
			"Calories cannot be less than 0.", 0, INT_MAX);
	
	size = getValidInput("Enter size (0=Small, 1=Medium, or 2=Large) >> ",
				"Invalid size value.", 0, 2);
	
	if (option == 2 && numCoffees < SIZE) {
		caffeine = getValidInput("Enter caffeine (in mg)   >> ", 
				"Caffeine value cannot be less than 0, especially during finals week.", 0, INT_MAX);
	
		cout << "Enter roast type         >> ";
		getline(cin, roast);
		
		Coffee newC = cOrders[numCoffees];
		newC.setName(name);
		newC.setCalories(calories);
		newC.setSize(size);
		newC.setCaffeine(caffeine);
		newC.setRoast(roast);
		
		cOrders[numCoffees++] = newC;
		return true;
	}
	else if (numBeverages < SIZE) {
		Beverage newB = bOrders[numBeverages];
		newB.setName(name);
		newB.setCalories(calories);
		newB.setSize(size);
		
		bOrders[numBeverages++] = newB;
		return true;
	}
	
	cout << "Order failed: Too many orders in progress.";
	return false;
}

// Displays each Beverage's information to the console.
void displayOrders(Beverage bOrders[SIZE], Coffee cOrders[SIZE], int numBeverages, int numCoffees) {
	cout << endl
		<< "*************************************************************************\n"
		<< "**                         All Beverage Orders                         **\n"
		<< "*************************************************************************\n"
		<< "| Order # | Name           | Calories | Size | Caffeine (mg) | Roast    |\n"
		<< "*************************************************************************\n";
		
	for (int i = 0; i < numBeverages; i ++) {
		cout << bOrders[i] << endl;
	}
	for (int i = 0; i < numCoffees; i ++) {
		cout << cOrders[i] << endl;
	}
}

// Function handling input validation.
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

