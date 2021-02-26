// Header file for RaspberryPi, a derived class of OpenSourceHardware.

#ifndef RASPBERRYPI_H
#define RASPBERRYPI_H

// Include base class
#include "OpenSourceHardware.h"

#include <string>
#include <iostream>

using namespace std;

class RaspberryPi : public OpenSourceHardware
{
	private:
		string m_os;
	public:
		RaspberryPi();
		RaspberryPi(string model, double power, double price, string os);
		
		inline string getOS() const { return m_os; }

		inline void setOS(string os) { m_os = os; }

		bool operator==(const RaspberryPi& other);
		friend ostream& operator<<(ostream& os, const RaspberryPi& rp);
};

#endif
