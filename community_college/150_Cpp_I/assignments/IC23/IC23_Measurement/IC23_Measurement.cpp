/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #23
* LAST MODIFIED:	11/18/18
*
* Measurement *****************************************************************
*
* PROGRAM DESCRIPTION: 
* Using a class named Measurment, this program will handle the instantiation, comparison,
* incrementation, decrementation, addition and subtraction of datum related to an imperial 
* measurement (in feet and inches).
* 
* ALGORITHM:
* 1.  Create a Measurement m1 with 5 feet and 8 inches (should convert to 6ft, 6in)
* 2.  Create a Measurement m2 whose data is copied from that of m1
* 3.  Display both Measurements to the console
* 4.  Determine and display the equality of m1 and m2 to the console (true)
* 5.  Prefix increment m1 while displaying to the console (displays 6ft, 7in)
* 6.  Prefix decrement m2 while displaying to the console (displays 6ft, 5in)
* 7.  Determine and display the equality of m1 and m2 to the console (false)
* 8.  Create a Measurement m3 that is m1 + m2 (should convert to 13ft, 0in)
* 9.  Display m3 to the console
* 10. Create a Measurement m4 that is m1 - m2 (should convert to 0ft, 2 in)
* 11. Display m4 to the console
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
******************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

class Measurement {
	private:
		double m_feet, m_inches;
		
	public:
		// Parameterized constructor
		Measurement(double feet, double inches) {
			m_feet = feet;
			m_inches = inches;
			
			// Convert inches to feet if inches >= 12
			while (m_inches >= 12) {
				if ((m_inches - 12) >= 0) {
					m_inches -= 12;
					m_feet++;
				}
			}
		}
		
		// Default constructor
		Measurement() {
			m_feet = 0.0;
			m_inches = 0.0;
		}
		
		// Copy constructor
		Measurement(const Measurement& original) {
			Measurement copy(original.m_feet, original.m_inches);
			
			m_feet = copy.m_feet;
			m_inches = copy.m_inches;
		}
		
		// Accessors
		double getFeet() {
			return m_feet;
		}
		
		double getInches() {
			return m_inches;
		}
		
		// Mutators
		double setFeet(double feet) {
			m_feet = feet;
			return m_feet;
		}
		
		double setInches(double inches) {
			m_inches = inches;
			return m_inches;
		}
		
		// operator++ member function to increment inches by 1 (prefix)
		Measurement operator++ () {
			// If inches >= 12, set inches to 0 and add 1 to feet
			if (m_inches >= 12) {
				m_inches = 0;
				m_feet++;
			}
			else {
				m_inches++;
			}
			// Return new Measurement (prefix incrementation)
			Measurement newM(m_feet, m_inches);
			return newM;
		}
		
		// operator-- member function to decrment the inches by 1 (prefix)
		Measurement operator-- () {
			// If inches <= 0, set inches to 11 and subtract 1 from feet
			if (m_inches <= 0) {
				m_inches = 11;
				m_feet--;
			}
			else {
				m_inches--;
			}
			
			// Return new Measurement (prefix decrementation)
			Measurement newM(m_feet, m_inches);
			return newM;
		}
		
		// operator== member function to check if one Measurement is the same as another
		bool operator== (const Measurement& other) {
			return (m_feet == other.m_feet) && (m_inches == other.m_inches);
		}
		
		// operator+ member function to add one Measurement to another
		Measurement operator+ (const Measurement& other) {
			int newInches = m_inches + other.m_inches;
			int newFeet = m_feet + other.m_feet;
			
			Measurement newM(newFeet, newInches);
			return newM;
		}
		
		// operator- member function to subtract one Measurement from another
		Measurement operator- (const Measurement& other) {
			int newInches = (m_inches - other.m_inches) + ((m_feet - other.m_feet) * 12);
			
			Measurement newM(0, newInches);
			return newM;
		}
		
		// operator<< friend function to overload operator<< of iostream
		// to display this Measurement, i.e. "Measurement [6 feet, 1 inch]"
		friend ostream& operator<< (ostream& os, const Measurement& t);
		
}; // End of class Measurement

// Function Implementations
// Overloads << operator to print a Measurement's member variables
ostream& operator<< (ostream& os, const Measurement& m) {
	os << "Measurement [" << m.m_feet << ((m.m_feet == 1) ? " foot, " : " feet, ")
		<< m.m_inches << ((m.m_inches == 1) ? " inch" : " inches") << "]";
		
	return os;
}

int main(int argc, char** argv) {
	
	// Create a Measurement m1 with 5 feet 18 inches
	Measurement m1(5, 18);
	
	// Create a Measurement m2 using copy constructor on m1
	Measurement m2(m1);
	
	// Display both Measurements to the console
	cout << "~~~Instantiating m1 and m2 with 5 feet, 18 inches~~~\n"
		<< "m1 = " << m1 << endl
		<< "m2 = " << m2 << endl;
	
	// Use == to determine equality
	cout << "m1 == m2? " << ((m1 == m2) ? "true" : "false") << "\n\n";
	
	// Prefix increment m1 while displaying to console
	// and prefix decrement m2 while displaying to console
	cout << "~~~++m1 (prefix increment) and --m2 (prefix decrement)~~~\n"
		<< "++m1 = " << (++m1) << endl
		<< "--m2 = " << (--m2) << endl;
	
	// Use == to determine equality
	cout << "m1 == m2? " << ((m1 == m2) ? "true" : "false") << "\n\n";
	
	// Instantiate m3 = m1 + m2
	Measurement m3 = m1 + m2;
	
	// Display m3 to the console
	cout << "~~~Instantiating m3 = m1 + m2~~~\n" << m3 << "\n\n";
	
	// Instantiate m4 = m1 - m2
	Measurement m4 = m1 - m2;
	
	// Display m4 to the console
	cout << "~~~Instantiating m4 = m1 - m2~~~\n" << m4 << "\n\n";
	
	return 0;
}
