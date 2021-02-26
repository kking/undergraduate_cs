/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #22
* LAST MODIFIED:	11/13/18
*
* Time ************************************************************************
*
* PROGRAM DESCRIPTION: 
* Using a class named Time to store information about the time of day, this program will simulate
* a 12-hour clock set through both incrementation and decrementation.
* 
* ALGORITHM:
* 1. Create a Time t1 at 11:59 PM
* 2. Create a Time t2 at its default for midnight
* 3. Print both Times to the console
* 4. Determine and print the equality of the two Times using ==
* 5. Prefix increment t1 while simultaneously printing to the console
* 6. Print t2 to the console
* 7. Determine and print the equality of the two Times using ==
* 8. Print t1 to the console
* 9. Postfix increment t2 while simultaneously printing to the console
* 10. Determine and print the equality of the two Times using ==
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Time {
	private:
		// Member variables
		int m_hour, m_minute;
		string m_meridiem;
		
	public:
		// Parameterized constructor
		// May also assign default values to parameters; default
		Time(int hour=12, int minute=0, string meridiem="AM") {
			m_hour = hour;
			m_minute = minute;
			m_meridiem = meridiem;
		}
		
		// Copy constructor
		Time(const Time& other) {
			m_hour = other.m_hour;
			m_minute = other.m_minute;
			m_meridiem = other.m_meridiem;
		}
		
		// Member functions
		// Accesssors
		int getHour() {
			return m_hour;
		}
		
		int getMinute() {
			return m_minute;
		}
		
		string getMeridiem() {
			return m_meridiem;
		}
		
		// Mutators
		int setHour(int hour) {
			m_hour = hour;
			return m_hour;
		}
		
		int setMinute(int minute) {
			m_minute = minute;
			return m_minute;
		}
		
		string setMeridiem(string meridiem) {
			m_meridiem = meridiem;
			return m_meridiem;
		}
		
		// Friend function to overload << of iostream
		friend ostream& operator<< (ostream& os, const Time& t);
		
		// Friend function to check if one Time is the same as another
		bool operator== (const Time& other) {
			return (m_hour == other.m_hour) && (m_minute == other.m_minute) && (m_meridiem == other.m_meridiem);
		}
		
		// Friend function to overload ++; without parameters => prefix incrementation
		Time operator++ () {
			if (m_minute == 59) {
				m_minute = 0;
				
				m_hour++;
				if (m_hour == 13) {
					m_hour = 1;
					
				}
				
				m_meridiem = ((m_meridiem == "AM") ? "PM" : "AM");
			}
			// Return new time (prefix)
			Time newTime(m_hour, m_minute, m_meridiem);
			return newTime;
		}
		
		// Friend function to overload ++; dummy parameter int => postfix incrementation
		Time operator++ (int) {
			// Store previous Time's member variables
			Time oldTime(m_hour, m_minute, m_meridiem);
			
			if (m_minute == 59) {
				m_minute = 0;
				
				m_hour++;
				if (m_hour == 13) {
					m_hour = 1;
				}
				
				m_meridiem = ((m_meridiem == "AM") ? "PM" : "AM");
			}
			
			// Return old Time (postfix)
			return oldTime;
		}
		
		// Friend function to overload --; without parameters => prefix incrementation
		Time operator-- () {
			if (m_minute == 0) {
				m_minute = 59;
				
				m_hour--;
				if (m_hour == 0) {
					m_hour = 12;
				}
				
				if (m_hour == 11) {
					m_meridiem = ((m_meridiem == "AM") ? "PM" : "AM");
				}
			}
			// Return new Time (prefix)
			Time newTime(m_hour, m_minute, m_meridiem);
			return newTime;
		}
		
		// Friend function to overload --; dummy parameter int => postfix decrementation
		Time operator-- (int) {
			// Store previous Time's member variables
			Time oldTime(m_hour, m_minute, m_meridiem);
			
			if (m_minute == 0) {
				m_minute = 59;
				
				m_hour--;
				if (m_hour == 0) {
					m_hour = 12;
				}
				
				if (m_hour == 11) {
					m_meridiem = ((m_meridiem == "AM") ? "PM" : "AM");
				}
			}
			// Return old Time (postfix)
			return oldTime;
		}
		
}; // End of class Time

// Function implementations
// Overloads << operator to print a Time's member variables
ostream& operator<< (ostream& os, const Time& t) {
	os << "Time [" << t.m_hour 
		<< ":" << ((t.m_minute < 10) ? "0" : "") << t.m_minute
		<< " " << t.m_meridiem << "]";
		
	return os;
}

int main(int argc, char** argv) {
	// Create a Time t1 at 11:59 PM
	Time t1(11, 59, "PM");
	
	// Create a Time t2 at midnight
	Time t2;
	
	// Display both times to the console
	cout << "~~~Original Times~~~"
		<< "\nt1: " << t1
		<< "\nt2: " << t2 << endl;
	
	// Use == to determine equality
	cout << "T1 is equal to T2? "
		<< ((t1 == t2) ? "true" : "false") << endl;
	
	// Prefix increment t1 while displaying to console
	// Display t2 to the console
	cout << "\n~~~cout << ++t1~~~"
		<< "\nt1: " << ++t1
		<< "\nt2: " << t2 << endl;
	
	// Use == to determine equality
	cout << "T1 is equal to T2? "
		<< ((t1 == t2) ? "true" : "false") << endl;
	
	// Display t1 to the console
	// Postfix increment t2 while displaying to console
	cout << "\n~~~cout << t2++~~~"
		<< "\nt1: " << t1
		<< "\nt2: " << t2++ << endl;
	
	// Use == to determine equality
	cout << "T1 is equal to T2? " << t2 << endl
		<< ((t1 == t2) ? "true" : "false") << "\n\n";


	system("pause");
	return EXIT_SUCCESS;
	
} // End of main
