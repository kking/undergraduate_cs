#include "Month.h"

using namespace std;

// Constants
const string NAMES[] = { "January", "February", "March", "April", 
						"May", "June", "July", "August", "September",
						"October", "November", "December" };

// When you implement functions from the header file, you have to prefix
// each with a namespace (class name)

Month::Month(string name, int number) {
	m_name = name;
	m_number = number;
}

// Prefix increments month by 1
Month Month::operator++ () {
	m_number += ((m_number != 12) ? (1) : (-11));
	m_name = NAMES[m_number - 1];
	
	// Return new Month (prefix incrementation)
	Month newM(m_name, m_number);
	return newM;
}

// Postfix increments month by 1
Month Month::operator++ (int) {
	// Store previous Month's member variables
	Month oldM(m_name, m_number);
	
	m_number += ((m_number != 12) ? (1) : (-11));
	m_name = NAMES[m_number - 1];
	
	// Return old Month (postfix)
	return oldM;
}

// Prefix decrements month by 1
Month Month::operator-- () {
	m_number -= ((m_number != 1) ? (1) : (-11));
	m_name = NAMES[m_number - 1];
	
	// Return new Month (prefix incrementation)
	Month newM(m_name, m_number);
	return newM;
}

// Postfix derements month by 1
Month Month::operator-- (int) {
	// Store previous Month's member variables
	Month oldM(m_name, m_number);

	m_number -= ((m_number != 1) ? (1) : (-11));
	m_name = NAMES[m_number - 1];
	
	// Return old Month (postfix)
	return oldM;
}

// Assigns all member variables of this Month to those of another
void Month::operator= (const Month& other) {
	m_name = other.m_name;
	m_number = other.m_number;
}

// Converts a Month into a string for display, "Month[January (1)]"
ostream& operator<< (ostream& os, const Month& m) {
	os << "Month [" << m.m_name << " (" << m.m_number << ")]";
	return os;
}

// End of class Month
