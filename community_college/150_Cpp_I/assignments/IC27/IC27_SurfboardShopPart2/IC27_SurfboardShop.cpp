/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #27
* LAST MODIFIED:	11/27/18
*
* Surfboard Shop **************************************************************
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* iostream - input/output stream within the console
* string - provides string functions
******************************************************************************/

#include <iostream>
#include <string>

#include "Surfboard.h"
#include "SurfboardList.h"

int main(int argv, char* argc[])
{

	string brand, model;
	double length, width, thickness, price;
	int id, quantity;
	SurfboardList boardList;

	int userChoice = 0;

	do {
		cout << "************************************************************************" << endl;
		cout << "**                                                                    **" << endl;
		cout << "**                          WELCOME TO                                **" << endl;
		cout << "**                      ENCHILADA SURFBOARDS                          **" << endl;
		cout << "**               \"Where you get the whole enchilada!\"                 **" << endl;          
		cout << "**                                                                    **" << endl;
		cout << "************************************************************************" << endl;
		cout << "** Please make a choice from the following options:                   **" << endl;
		cout << "** 1)  Add a new Surfboard to Inventory                               **" << endl;
		cout << "** 2)  Remove a Surfboard from Inventory                              **" << endl;
		cout << "** 3)  Update an existing Surfboard                                   **" << endl;
		cout << "** 4)  Display all Surfboards in Inventory                            **" << endl;
		cout << "** 5)  Exit                                                           **" << endl;
		cout << "************************************************************************" << endl;
		cout << ">> ";
		cin >> userChoice;
		cin.ignore(INT_MAX, '\n');
		switch (userChoice)
		{
		case 1:
		{
			cout << "Enter Brand: ";
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

			Surfboard s(brand, model, length, width, thickness, quantity, price);
			if (boardList.addBoard(s))
				cout << "~~~Surfboard added successfully!~~~" << endl;
			else
				cout << "~~~Failed to add Surfboard to Inventory~~~" << endl;


			cout << endl;
			break;
		}
		case 2:
			cout << boardList << endl;
			cout << "\nWhich ID# would you like to remove? (or -1 to cancel) >> ";
			cin >> id;
			if (id == -1) break;
			if (boardList.removeBoard(id))
				cout << "~~~Surfboard removed successfully!~~~" << endl;
			else
				cout << "~~~Failed to remove Surfboard from Inventory~~~" << endl;
			break;
		case 3:
            cout << boardList << endl;
			cout << "\nWhich ID# would you like to update? (or -1 to cancel) >> ";
			cin >> id;
			if (id == -1) break;

			cin.ignore(INT_MAX, '\n');
			cout << "\nEnter Updated Brand: ";
			getline(cin, brand);
			cout << "Enter Updated Model: ";
			getline(cin, model);
			cout << "Enter Updated Length: ";
			cin >> length;
			cout << "Enter Updated Width: ";
			cin >> width;
			cout << "Enter Updated Thickness: ";
			cin >> thickness;
			cout << "Enter Updated Quantity: ";
			cin >> quantity;
			cout << "Enter Updated Price $";
			cin >> price;

            // Now update the board!
            if (boardList.updateBoard(id, brand, model, length, width, thickness, quantity, price)) {
            	cout << "Board updated successfully!" << endl;
			}
			else {
				cout << "Board not found." << endl;
			}
            break;
		case 4:
			cout << boardList << endl;
			break;
		case 5:
			cout << "Aloha, enjoy the ride!!!" << endl;
			break;
		default:
            cout << "Choice not recognized, please drop in again." << endl;
		}

	} while (userChoice != 5);
	
	cout << endl;
	return 0;
}
