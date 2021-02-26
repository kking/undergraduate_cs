/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	26
* LAST MODIFIED:	11/29/18
*
* Capstone Phase 1 ************************************************************
*
* PROGRAM DESCRIPTION: 
* Using the classes Keyboard and KeyboardList, this program will simulate an inventory 
* which handles the addition, removal, and display of musical keyboards in a music shop.
* 
* ALGORITHM:
* 1.  DO, WHILE option != 5
* 2.    PRINT keyboard inventory menu
* 3.    READ option as an integer [1, 4]
* 4.    SWITCH option
* 5.      CASE 1: Add a Keyboard to inventory
* 6.        PROMPT and READ brand
* 7.        " number of keys
* 8.        " weighted keys (1 = yes, 0 = no)
* 9.        " MIDI compatibility (1 = yes, 0 = no)
* 10.       " quantity
* 11.       " price
* 12.       Create a new Keyboard with the given values
* 13.       Add this Keyboard to KeyboardList
* 14.       IF Keyboard was successfully added
* 15.         PRINT "Keyboard added!"
* 16.       ELSE
* 17.         PRINT "Inventory is full."
* 18.     END CASE 1
* 19.     CASE 2: Remove a Keyboard from inventory
* 20.       PRINT KeyboardList to console
* 21.       PROMPT and READ id# to remove (or -1 to cancel)
* 22.       IF id# != -1
* 23.         Remove Keyboard from KeyboardList
* 24.         IF Keyboard was successfully removed
* 25.           PRINT "Keyboard removed!"
* 26.         ELSE
* 27.           PRINT "Keyboard not found."
* 28.       END IF
* 29.     END CASE 2
* 30.  	  CASE 3: Display inventory of Keyboards
* 31.       PRINT KeyboardList to console
* 32.     END CASE 3
* 33.     CASE 4: Exit program
* 34.       PRINT "Rock on \m/."
* 35.     END CASE 4
* 36.   END SWITCH
* 37. END DO, WHILE option != 4
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* "Keyboard.h" - a model class for information on a keyboard for sale
* "KeyboardList.h" - a container for handling multiple Keyboard objects
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include "Keyboard.h"
#include "KeyboardList.h"

using namespace std;

// Function Prototypes
void printMenu();
void addKeyboard(KeyboardList& keysList);
void removeKeyboard(KeyboardList& keysList);

int main(int argc, char** argv) {
	// A container of Keyboards
	KeyboardList inventory;
	// User selection for menu-based program
	int option = 0;
	
	do {
		printMenu();
		
		cin >> option;
		cin.ignore(INT_MAX, '\n');
		
		switch (option) {
			case 1: // Adds an item to the inventory
				addKeyboard(inventory);
				break;
			case 2: // Removes an item from the inventory
				removeKeyboard(inventory);
				break;
			case 3: // Displays the inventory of all items
				cout << inventory;
				break;
			case 4: // Exit program
				cout << "Rock on \\m/.";
				break;
			default:
				break;
		} // End of switch
		
	} while (option != 4);
	
	cout << endl;
	return 0;
	
} // End of main

// Prints a menu to the console.
void printMenu() {
	cout << endl 
		<< "**********************************************" << endl
		<< "*             KEYBOARD INVENTORY             *" << endl
		<< "**********************************************" << endl
		<< "* 1 - Add a keyboard to the inventory        *" << endl
		<< "* 2 - Remove a keyboard from the inventory   *" << endl
		<< "* 3 - Display entire inventory of keyboards  *" << endl
		<< "* 4 - Exit program                           *" << endl
		<< "**********************************************" << endl
		<< endl << "=> "; 
}

// Adds to this KeyboardList a Keyboard whose member variables are defined by the user.
void addKeyboard(KeyboardList& keysList) {
	// For defining member varialbes of a given Keyboard
	string brand;
	int numKeys, quantity;
	bool weightedKeys, midi;
	double price;
	
	// Receive values for the following member variables for a new Keyboard
	cout << "Enter brand: ";
	getline(cin, brand);
	cout << "Enter number of keys: ";
	cin >> numKeys;
	cout << "Weighted keys (1 = yes, 0 = no)? ";
	cin >> weightedKeys;
	cout << "MIDI compatible (1 = yes, 0 = no)? ";
	cin >> midi;
	cout << "Enter quantity: ";
	cin >> quantity;
	cout << "Enter price: $";
	cin >> price;
	
    // Declare a new Keyboard
    Keyboard kb(brand, numKeys, weightedKeys, midi, quantity, price);
    
    // Add it to KeyboardList
    cout << ((keysList.addKeyboard(kb)) ? "Keyboard added successfully!" : "Inventory is full.");
    cout << endl;
}

// Removes a Keyboard from this KeyboardList based on its assigned id#.
void removeKeyboard(KeyboardList& keysList) {
    int id;
    
    cout << keysList << endl;
    cout << "Which ID# would you like to remove? (or -1 to cancel) >> ";
    cin >> id;
     
    if (id != -1) {
    	cout << ((keysList.removeKeyboard(id)) ? "Keyboard removed successfully!" : "Keyboard not found!");
    }
    cout << endl;
}
