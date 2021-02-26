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
* Header file for a Keyboard class. Includes member variables and functions which define
* a musical keyboard's hardware specifications and specifications as a sales item.
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* iostream - input/output stream within the console
******************************************************************************/

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>

using namespace std;

class Keyboard {
	private:
		static int s_nextId; // Static variable to keep track of next id to assign
		int m_id, m_quantity, m_numKeys;
		double m_price;
		string m_brand;
		bool m_weightedKeys, m_midi; // Weighted keys, MIDI (Musical Instrument Digital Interface) compatible
	public:
		// Constructors
		Keyboard();
		Keyboard(string brand, int numKeys, bool weightedKeys, bool midi, int quantity, double price);
		
		// Accessors
		inline int getId() const { return m_id; }
		inline int getQuantity() const { return m_quantity; }
		inline int getNumKeys() const { return m_numKeys; }
		inline double getPrice() const { return m_price; }
		inline string getBrand() const { return m_brand; }
		inline bool getWeightedKeys() const { return m_weightedKeys; }
		inline bool getMidi() const { return m_midi; }
		
		// Mutators
		inline void setQuantity(int quantity) { m_quantity = quantity; }
		inline void setNumKeys(int numKeys) { m_numKeys = numKeys; }
		inline void setPrice(double price) { m_price = price; }
		inline void setBrand(string brand) { m_brand = brand; }
		inline void setWeightedKeys(bool weightedKeys) { m_weightedKeys = weightedKeys; }
		inline void setMidi(bool midi) { m_midi = midi; }
		
		// Determines the equivalency of two Keyboards based on member variables
		bool operator== (const Keyboard& other);
	
	// Turns this Keyboard into a string for display.
	friend ostream& operator<< (ostream& os, const Keyboard& kb);
};

#endif
