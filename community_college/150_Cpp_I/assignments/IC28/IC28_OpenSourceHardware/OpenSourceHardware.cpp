// Class implementation for OpenSourceHardware, a base class to contain data and 
// behaviors which define open source hardware.

#include "OpenSourceHardware.h"

OpenSourceHardware::OpenSourceHardware() {
	m_model = "n/a";
	m_power = 0;
	m_price = 0.0;
}

OpenSourceHardware::OpenSourceHardware(string model, double power, double price) {
	m_model = model;
	m_power = power;
	m_price = price;
}

bool OpenSourceHardware::operator==(const OpenSourceHardware& other) {
	return (m_model == other.m_model) && (m_power == other.m_power)
		&& (m_price == other.m_price);
}

