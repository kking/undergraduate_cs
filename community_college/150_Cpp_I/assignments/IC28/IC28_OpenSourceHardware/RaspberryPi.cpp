// Class implementation for RaspberryPi, a derived class of OpenSourceHardware.

#include "RaspberryPi.h"

RaspberryPi::RaspberryPi() : OpenSourceHardware()
{
	m_os = "";
}

RaspberryPi::RaspberryPi(string model, double power, double price, string os)
			: OpenSourceHardware(model, power, price)
{
	m_os = os;
}

bool RaspberryPi::operator==(const RaspberryPi& other)
{
	return OpenSourceHardware::operator==(other) && m_os == other.m_os;
}

ostream& operator<<(ostream& os, const RaspberryPi& rp)
{
	os << "RaspberryPi [Model=" << rp.m_model
		<< ", Power=" << rp.m_power << "V"
		<< ", Price=$" << rp.m_price
		<< ", Operating System=" << rp.m_os
		<< "]";

	return os;
}

