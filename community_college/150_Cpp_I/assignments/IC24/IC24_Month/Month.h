#ifndef MONTH_H
#define MONTH_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Month {
	// Member Variables
	private:
		string m_name;
		int m_number;
	// Member Functions
	public:
		// Constructor prototype
		Month(string name="January", int number=1);
		
		// Accessors
		inline string getName() const { return m_name; }
		inline int getNumber() const { return m_number; }
		
		// Mutators
		inline void setName(string name) { m_name = name; }
		inline void setNumber(int number) { m_number = number; }
		
		// Determines equivalency of two Months
		inline bool operator== (const Month& other) {
			return (m_name == other.m_name) && (m_number == other.m_number);
		}
		
		// Prefix increments month by 1
		Month operator++ ();
		
		// Postfix increments month by 1
		Month operator++ (int);
		
		// Prefix decrements month by 1
		Month operator-- ();
		
		// Postfix decrements month by 1
		Month operator-- (int);
		
		// Assigns all member variables of this Month to those of another
		void operator= (const Month& other);
		
	// Converts a Month into a string for display, "Month[January (1)]"
	friend ostream& operator<< (ostream& os, const Month& m);
		
};

#endif
