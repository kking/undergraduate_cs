#include "Beverage.h"
#include <iomanip>

int Beverage::s_nextOrderNumber = 1;

Beverage::Beverage() {
	m_name = "";
	m_orderNumber = s_nextOrderNumber++;
	m_calories = 0;
	m_size = 1; // small
}

Beverage::Beverage(string name, int calories, int size) {
	m_orderNumber = s_nextOrderNumber++;
	m_name = name;
	m_calories = calories;
	m_size = size;
}

bool Beverage::operator==(const Beverage& other) {
	return (m_name == other.m_name) 
		&& (m_orderNumber == other.m_orderNumber)
		&& (m_calories == other.m_calories)
		&& (m_size == other.m_size);
}

ostream& operator<<(ostream& os, const Beverage& b) {
	os << "| " << left << setw(8) << b.m_orderNumber
		<< "| " << left << setw(15) << b.m_name
		<< "| " << left << setw(9) << b.m_calories << "| ";
	
	switch (b.m_size) {
		case 0:
			os << left << setw(5) << "S";
			break;
		case 1:
			os << left << setw(5) << "M";
			break;
		case 2:
			os << left << setw(5) << "L";
			break;
		default:
			break;
	}

	return os;
}

