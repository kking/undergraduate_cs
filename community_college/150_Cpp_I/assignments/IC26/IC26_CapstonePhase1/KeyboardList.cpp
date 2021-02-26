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
* Implementation for a KeyboardList class. Includes member variables and functions
* relating to the addition, removal and display of Keyboard objects in a 
* collection.
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* iostream - input/output stream within the console
* iomanip - for manipulation of input/output data
* "Keyboard.h" - a model class for a musical keyboard for sale
* "KeyboardList.h" - a container for Keyboard objects
******************************************************************************/

#include "KeyboardList.h"
#include "Keyboard.h"

// Adds a Keyboard to this list. If list is full, return false.
bool KeyboardList::addKeyboard(Keyboard kb) {
    // Check if list is full (m_count >= SIZE - 1)
    if (m_count >= SIZE - 1)
        return false;
    else {
        // Add the Surfboard to m_list
        m_list[m_count++] = kb;
        return true;
    }
}

// Removes a Keyboard based on its id#. If id is not found, return false.
bool KeyboardList::removeKeyboard(int id) {
	// Loop through the list to find the board's id
    for (int i = 0; i < m_count; i++) {
        // If a match is found, move everything down
        if (m_list[i].getId() == id) {
        	for (int j = i; j < m_count; j ++) {
        		m_list[j] = m_list[j+1];
    		}
        	m_count--;
        	return true;
        }
    }
    // A match was not found, return false
    return false;
}

		
// Turns this KeyboardList into a string for display.
ostream& operator<< (ostream& os, const KeyboardList& kb) {
    os << "~~~Current Inventory of Keyboards~~~\n";
    if (kb.m_count > 0) {
    	for (int i = 0; i < kb.m_count; i++) {
        	os << kb.m_list[i] << endl;
		}
	}
	else {
		os << "[Empty]" << endl;
	}
    return os;
}

// End of KeyboardList class implementation
