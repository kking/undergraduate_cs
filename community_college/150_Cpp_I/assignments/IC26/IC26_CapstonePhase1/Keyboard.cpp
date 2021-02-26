/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	26
* LAST MODIFIED:	11/29/18
*
* Keyboard ********************************************************************
*
* PROGRAM DESCRIPTION: 
* Implementation for a Keyboard class. Includes member variables and functions which define
* a musical keyboard's hardware specifications and specifications as a sales item.
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* iostream - input/output stream within the console
******************************************************************************/

#include "Keyboard.h"
#include <iomanip>

// Initialize static variable (next id)
int Keyboard::s_nextId = 10000;

// Default constructor
Keyboard::Keyboard() {
	m_id = 0;
	m_brand = "n/a";
	m_numKeys = 88;
	m_weightedKeys = false;
	m_midi = false;
	m_quantity = 0;
	m_price = 0.0;
}

// Parameterized constructor
Keyboard::Keyboard(string brand, int numKeys, bool weightedKeys, bool midi, int quantity, double price) {
	m_id = s_nextId++;
	m_brand = brand;
	m_numKeys = numKeys;
	m_weightedKeys, weightedKeys;
	m_midi = midi;
	m_quantity = quantity;
	m_price = price;
}

// Determines the equivalency of two Keyboards based on member variables
bool Keyboard::operator== (const Keyboard& other) {
	return (m_brand == other.m_brand) && (m_numKeys == other.m_numKeys) && (m_weightedKeys == other.m_weightedKeys)
		&& (m_midi == other.m_midi) && (m_quantity == other.m_quantity) && (m_price == other.m_price);
}

// Turns this Keyboard into a string for display.
ostream& operator<< (ostream& os, const Keyboard& kb) {
	os << "Keyboard [ID#" << kb.m_id << ", Brand = " << kb.m_brand
		<< ", Number of Keys = " << kb.m_numKeys << ", Weighted Keys = "
		<< ((kb.getWeightedKeys()) ? "yes" : "no") << ", MIDI Compatability = "
		<< ((kb.getMidi()) ? "yes" : "no") << ", Quantity = " << kb.m_quantity
		<< ", Price = $" << fixed << setprecision(2) << kb.m_price << "]";
	
	return os;
}

// End of Keyboard class implementation
