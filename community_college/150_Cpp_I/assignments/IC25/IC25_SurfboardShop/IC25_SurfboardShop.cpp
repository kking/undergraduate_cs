/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #25
* LAST MODIFIED:	11/26/18
*
* Surfboard Shop **************************************************************
*
* PROGRAM DESCRIPTION: 
* Using the classes Surfboard and SurfboardList, this program will allow the user to
* add, remove, and display information regarding a list of Surfboards in a shop.
* 
* ALGORITHM:
* 1.  DO, WHILE (choice != 4)
* 2.    PRINT menu for surfboard shop, with menu options 1-4 for the following
* 3.    READ choice as an integer in the range [1, 4]
* 4.    SWITCH (choice)
* 5.      CASE 1: "Add a new Surfboard to Inventory"
* 6.        PROMPT "Enter brand"
* 7.        READ brand
* 8.        PROMPT "Enter model"
* 9.        READ model
* 10.       PROMPT "Enter length"
* 11.       READ length as a positive number
* 12.       PROMPT "Enter width"
* 13.       READ width as a positive number
* 14.       PROMPT "Enter thickness"
* 15.       READ thickness as a positive number
* 16.       PROMPT "Enter quantity"
* 17.       READ quantity as a positive number
* 18.       PROMPT "Enter price"
* 19.       READ price as a positive number
* 20.       create a new Surfboard with the above values
* 21.       add the new Surfboard to the SurfboardList
* 22.     CASE 2: "Remove a Surfboard from Inventory"
* 23.       PRINT the SurfboardList to the console
* 24.       PROMPT "Which ID# would you like to remove?"
* 25.       READ id
* 26.       IF id != -1
* 27.         remove Surfboard from SurfboardList based on id#
* 28.         IF an existing Surfboard was removed
* 29.           PRINT "Board removed successfully!"
* 30.         ELSE
* 31.           PRINT "Board not found."
* 32.       END if
* 33.     CASE 3: "Display all Surfboards in Inventory"
* 34.       PRINT the SurfboardList to the console
* 35.     CASE 4: "Exit"
* 36.       PRINT "Aloha, enjoy the ride!!!"
* 37.   END SWITCH
* 38. END DO, WHILE (choice != 4)
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* string - provides string functions
* "Surfboard.h" - a model class for information on a surfboard on sale
* "SurfboardList.h" - a container for handling multiple Surfboard objects
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

#include "Surfboard.h"
#include "SurfboardList.h"

using namespace std;

// Function Prototypes
void printMenu();
void addSurfboard(SurfboardList& boardList);
void removeSurfboard(SurfboardList& boardList);

int main(int argv, char* argc[]) 
{
	// A container of Surfboards
	SurfboardList inventory;
	// User selection for menu-based program
	int choice = 0;

	do {
		printMenu();
		
		cin >> choice;
		cin.ignore(INT_MAX, '\n');
		
		switch (choice)
		{
			case 1: // Add a new Surfboard to Inventory
				addSurfboard(inventory);
                break;
            case 2: // Remove a Surfboard from Inventory
                removeSurfboard(inventory);
                break;
            case 3: // Display all Surfboards in Inventory
                cout << inventory << endl;
                break;
            case 4: // Exit
                cout << "Aloha, enjoy the ride!!!" << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
		} // End of switch

	} while (choice != 4);
	
	cout << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
	
} // End of main

// Prints a guide for this menu-based program.
void printMenu() {
    cout << "************************************************************************" << endl
    	<< "**                                                                    **" << endl
        << "**                          WELCOME TO THE                            **" << endl
        << "**                          SURFBOARD SHOP                            **" << endl
        << "**                                                                    **" << endl
        << "************************************************************************" << endl
        << "** Please make a choice from the following options:                   **" << endl
        << "** 1)  Add a new Surfboard to Inventory                               **" << endl
        << "** 2)  Remove a Surfboard from Inventory                              **" << endl
        << "** 3)  Display all Surfboards in Inventory                            **" << endl
        << "** 4)  Exit                                                           **" << endl
        << "************************************************************************" << endl
        << ">> ";
}

// Adds a new Surfboard to the given SurfboardList, if said list is not at capacity.
void addSurfboard(SurfboardList& boardList) {
    // For defining member variables of a given Surfboard
    string brand, model;
    double length, width, thickness, price;
    int id, quantity;
    
    // Receive values for the following member variables for a new Surfboard
    cout << "Enter brand: ";
    getline(cin, brand);
    cout << "Enter Model: ";
    getline(cin, model);
    cout << "Enter Length: ";
    cin >> length;
    cout << "Enter Width: ";
    cin >> width;
    cout << "Enter Thickness: ";
    cin >> thickness;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Price $";
    cin >> price;
	     
    // Declare a new Surfboard
    Surfboard sb(brand, model, length, width, thickness, quantity, price);
    
    // Add it to SurfboardList
    cout << ((boardList.addBoard(sb)) ? "Board added successfully!" : "Inventory is full.");
    cout << endl;
}

// Removes an existing Surfboard in the given SurfboardList.
void removeSurfboard(SurfboardList& boardList) { 
    int id;
    
    cout << boardList << endl;
    cout << "Which ID# would you like to remove? (or -1 to cancel) >> ";
    cin >> id;
     
    if (id != -1) {
    	cout << ((boardList.removeBoard(id)) ? "Board removed successfully!" : "Board not found!");
    }
    cout << endl;
}
