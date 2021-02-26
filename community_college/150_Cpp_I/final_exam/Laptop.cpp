
#include "Laptop.h"
#include <iomanip>

// Default constructor
Laptop::Laptop() : Computer() {
	m_batteryLife = 0.0;
	m_weight = 0.0;
}

// Parameterized constructor
Laptop::Laptop(string make, string model, double price, double batteryLife, double weight)
		: Computer(make, model, price) {
	m_batteryLife = batteryLife;
	m_weight = weight;
}

// Evaluates equivalency of two Laptops
bool Laptop::operator==(const Laptop& other) {
	return Computer::operator==(other)
		&& (m_batteryLife == other.m_batteryLife)
		&& (m_weight == other.m_weight);
}

// For output to console
ostream& operator<<(ostream& os, const Laptop& l) {
	os << "|" << left << setw(6) << l.m_id
		<< "|" << left << setw(7) << l.m_make
		<< "|" << left << setw(15) << l.m_model
		<< "|" << left << fixed << setprecision(2) << setw(8) << l.m_price
		<< "|" << left << setprecision(1) << setw(15) << l.m_batteryLife
		<< "|" << left << setw(15) << l.m_weight << "|";
	return os;
}

