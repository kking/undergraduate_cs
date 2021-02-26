#include "Coffee.h"
#include <iomanip>

Coffee::Coffee() : Beverage() {
	m_caffeine = 0;
	m_roast = "";
}

Coffee::Coffee(string name, int calories, int size, int caffeine, string roast)
		: Beverage(name, calories, size) {
	m_caffeine = caffeine;
	m_roast = roast;	
}

bool Coffee::operator==(const Coffee& other) {
	return Beverage::operator==(other)
		&& (m_caffeine == other.m_caffeine)
		&& (m_roast == other.m_roast);
}
		
ostream& operator<<(ostream& os, const Coffee& c) {
	os << "| " << left << setw(8) << c.m_orderNumber
		<< "| " << left << setw(15) << c.m_name
		<< "| " << left << setw(9) << c.m_calories << "| "; 
		
	switch (c.m_size) {
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
		
	os << "| " << left << setw(14) << c.m_caffeine
		<< "| " << left << setw(8) << c.m_roast << " |";
		
	return os;	
}
