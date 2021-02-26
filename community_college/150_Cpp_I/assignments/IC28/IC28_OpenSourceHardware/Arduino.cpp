// Class implementation for Arduino, a derived class of OpenSourceHardware.

#include "Arduino.h"

Arduino::Arduino()
		: OpenSourceHardware() // calls base class constructor
{
	m_microcontroller = "";
}

Arduino::Arduino(string model, double power, double price, string microcontroller)
		 : OpenSourceHardware(model, power, price) // calls base class constructor
{
	m_microcontroller = microcontroller;
}

bool Arduino::operator==(const Arduino& other)
{
	return 
		 OpenSourceHardware::operator==(other)
		 && m_microcontroller == other.m_microcontroller;
}

ostream& operator<<(ostream& os, const Arduino& a)
{
	os << "Arduino [Model=" << a.m_model
		<< ", Power=" << a.m_power << "V"
		<< ", Price=$" << a.m_price
		<< ", Microcontroller=" << a.m_microcontroller
		<< "]";

	return os;
}

