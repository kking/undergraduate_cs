// Header file for Arduino, a derived class of OpenSourceHardware.

#ifndef ARDUINO_H
#define ARDUINO_H

// Include base class
#include "OpenSourceHardware.h"

#include <string>
#include <iostream>

using namespace std;

// Derived class from OpenSourceHardware
class Arduino : public OpenSourceHardware
{
	private:
		string m_microcontroller;	

	public:
		Arduino();
		
		Arduino(string model, double power, double price, string microcontroller);
	
		inline string getMicrocontroller() const { return m_microcontroller; }

		inline void setMicrocontroller(string microcontroller) { m_microcontroller = microcontroller; }

		bool operator==(const Arduino& a);
		friend ostream& operator<<(ostream& os, const Arduino& a);
};

#endif
