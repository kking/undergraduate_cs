/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #21
* LAST MODIFIED:	11/08/18
*
* Vehicle ************************************************************************
*
* PROGRAM DESCRIPTION: 
* Using a class named Vehicle, this program will store information for the programmer's
* car and display its information through functions which simulate acceleration and
* braking while driving.
* 
* ALGORITHM:
* 1.  Create a new Vehicle, a 2004 Chevrolet Cavalier belonging to King
* 2.  PRINT the vehicle's information to the console
* 3.  PRINT "Accelerating 10 times (+10.0 mph each)"
* 4.  FOR i = 0 through range < 10
* 5.    Call function which will accelerate its speed by 10.0
* 6.    PRINT the vehicle's information to the console
* 7.  END FOR
* 8.  PRINT "Braking 5 times (-5.0 mph each)"
* 9.  FOR i = 0 through range < 5
* 10.   Call function which will brake (decrement its speed by 5.0)
* 11.   PRINT the vehicle's information to the console
* 12. END FOR
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

class Vehicle {
	private:
		// Member variables
		int m_year;
		string m_make, m_model, m_owner;
		double m_speed;
	
	public:
		// Constructor
		Vehicle(int year, string make, string model, string owner) {
			m_year = year;
			m_make = make;
			m_model = model;
			m_owner = owner;
			m_speed = 0.0;
		}
		
		// Accessors
		string getMake() {
			return m_make;
		} 
		
		string getModel() {
			return m_model;
		}
		
		string getOwner() {
			return m_owner;
		}
		
		double getSpeed() {
			return m_speed;
		}
		
		int getYear() {
			return m_year;
		}
		
		// Friend function to overload << 
		// Define function prototype
		friend ostream& operator<< (ostream& os, const Vehicle& v);
		
		// Mutators
		void setMake(string make) {
			m_make = make;
		}
		
		void setModel(string model) {
			m_model = model;
		}
		
		void setOwner(string owner) {
			m_owner = owner;
		}
		
		// Helper/misc. function adds the given acceleration value to the speed 
		// member variable
		double accelerate(double a) {
			m_speed += a;
			return m_speed;
		}
		
		// Helper/misc. function subtracts the given deceleration value from the 
		// speed member variable; does not go below 0.0
		double brake(double d) {
			m_speed -= ((m_speed >= d) ? d : 0.0);
			return m_speed;
		}
};

// Function implementations
// Overloads << operator to print a Vehicle's member variables
ostream& operator<< (ostream& os, const Vehicle& v) {
	os << "Vehicle [" << v.m_year << " " << v.m_make << " "
		<< v.m_model << ", owner = " << v.m_owner
		<< ", speed = " << fixed << setprecision(1) << v.m_speed << " mph]";
		
	return os;
}

int main(int argc, char** argv) {
	const int ACCELERATION = 10.0, DECELERATION = 5.0;

	// Instantiate a new Vehicle
	Vehicle myCar(2004, "Chevrolet", "Cavalier", "King");
	
	// Print new Vehicle's data to the console
	cout << "~~~My Car~~~\n" << myCar << endl;
	
	cout << "\nAccelerating 10 times (+" << ACCELERATION << " mph each)\n";
	
	// Call the Vehicle's accelerate function five times,
	// Printing its member variables to the console each time
	for (int i = 0; i < 10; i++) {
		myCar.accelerate(ACCELERATION);
		cout << myCar << endl;
	}
	
	cout << "\nBraking 5 times (-" << DECELERATION << " mph each)\n";
	
	// Call the Vehicle's brake function five times,
	// Printing its member variables to the cosnole each time
	for (int i = 0; i < 5; i++) {
		myCar.brake(DECELERATION);
		cout << myCar << endl;
	}
	
	system("pause");
	return EXIT_SUCCESS;
}

