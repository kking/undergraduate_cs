#include "Point.h"
#include <cmath>

using namespace std;

// When you implement functions from the header file, you have to prefix
// each with a namespace (class name)

// Parameterized constructor
Point::Point(int x, int y) {
	m_x = x;
	m_y = y;
}

// Calculates the distance from this Point to another
double Point::distanceTo(const Point& other) {
	double deltaX = pow((other.m_x - m_x), 2.0);
	double deltaY = pow((other.m_y - m_y), 2.0);
	
	return sqrt(deltaX + deltaY);
}

// Overloarded = operator to set member variables of this Point to those of another
void Point::operator= (const Point& other) {
	m_x = other.m_x;
	m_y = other.m_y;
}

// Overloads cout's << to display a Point as a string
ostream& operator<< (ostream& os, const Point& p) {
	os << "Point [x = " << p.m_x << ", y = " << p.m_y << "]";
	return os;
}

// End of class Point
