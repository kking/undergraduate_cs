#include "Line.h"

using namespace std;

// When you implement functions from the header file, you have to prefix
// each with a namespace (class name)

// Parameterized constructor
Line::Line(int x1, int y1, int x2, int y2) {
	Point p1(x1, y1);
	Point p2(x2, y2);
	
	m_p1 = p1;
	m_p2 = p2;
}

// Parameterized constructor
Line::Line(Point p1, Point p2) {
	m_p1 = p1;
	m_p2 = p2;
}

// Overloaded == operator to check if one Line is the same as another
bool Line::operator== (const Line& other) {
	return ((m_p1 == other.m_p1) && (m_p2 == other.m_p2)) ||
		((m_p1 == other.m_p2) && (m_p2 == other.m_p1));
}

// Overloarded = operator to set member variables of this Line to those of another
void Line::operator= (const Line& other) {
	m_p1 = other.m_p1;
	m_p2 = other.m_p2;
}

// Overloads cout's << to display a Line as a string
ostream& operator<< (ostream& os, const Line& ln) {
	os << "Line[(x1 = " << ln.m_p1.getX() << ", y1 = " << ln.m_p1.getY()
		<< "), (x2 = " << ln.m_p2.getX() << ", y2 = " << ln.m_p2.getY()
		<< ")]";
		
	return os;
}

// End of class Line
