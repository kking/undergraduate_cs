
#include "Computer.h"
#include <iomanip>

int Computer::s_nextId = 100;

// Default constructor
Computer::Computer() {
	m_id = 0;
	m_make = "";
	m_model = "";
	m_price = 0.0;
}

// Parameterized constructor
Computer::Computer(string make, string model, double price) {
	m_id = s_nextId++;
	m_make = make;
	m_model = model;
	m_price = price;
}

// Evaluates equivalency of two Computers
bool Computer::operator==(const Computer& other) {
	return (m_id == other.m_id) 
		&& (m_make == other.m_make) 
		&& (m_model == other.m_model) 
		&& (m_price == other.m_price);
}

// For output to console
ostream& operator<<(ostream& os, const Computer& c) {
	os << "|" << left << setw(6) << c.m_id
		<< "|" << left << setw(7) << c.m_make
		<< "|" << left << setw(15) << c.m_model
		<< "|" << left << fixed << setprecision(2) << setw(8) << c.m_price << "|";
	return os;
}
