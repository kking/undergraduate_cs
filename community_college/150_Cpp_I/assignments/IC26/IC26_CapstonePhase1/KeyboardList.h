/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	26
* LAST MODIFIED:	11/29/18
*
* KeyboardList ****************************************************************
*
* PROGRAM DESCRIPTION: 
* Header file for a KeyboardList class. Includes member variables and functions
* relating to the addition, removal and display of Keyboard objects in a 
* collection.
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* iostream - input/output stream within the console
* iomanip - for manipulation of input/output data
* "Keyboard.h" - a model class for a musical keyboard for sale
* "KeyboardList.h" - a container for Keyboard objects
******************************************************************************/

#ifndef KEYBOARDLIST_H
#define KEYBOARDLIST_H

#include "Keyboard.h"
#include <iostream>

using namespace std;

class KeyboardList {
	private:
		const static int SIZE = 100; // Capacity of this inventory
		int m_count;
		Keyboard m_list[SIZE];
	public:
		// Constructors
		KeyboardList() { m_count = 0; }
		
		// Adds a Keyboard to this list. If list is full, return false.
		bool addKeyboard(Keyboard kb);
		
		// Removes a Keyboard based on its id#. If id is not found, return false.
		bool removeKeyboard(int id);
		
	// Turns this KeyboardList into a string for display.
	friend ostream& operator<< (ostream& os, const KeyboardList& kb);
};

#endif
