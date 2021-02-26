#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Line: header file for inline functions and function prototypes
class Line {
	
	private:
		Point m_p1, m_p2;
	public:
		// Constructors (prototype only)
		Line(int x1, int y1, int x2, int y2);
		Line(Point p1, Point p2);
		
		// Accessors
		inline Point getP1() const { return m_p1; }
		inline Point getP2() const { return m_p2; }
		
		inline int getX1() const { return m_p1.getX(); }
		inline int getY1() const { return m_p1.getY(); }
		
		inline int getX2() const { return m_p2.getX(); }
		inline int getY2() const { return m_p2.getY(); }
		
		// Mutators
		inline void setP1(Point p1) { m_p1 = p1; }
		inline void setP2(Point p2) { m_p2 = p2; }
		
		inline void setX1(int x) { m_p1.setX(x); }
		inline void setY1(int y) { m_p1.setY(y); }
		
		inline void setX2(int x) { m_p2.setX(x); }
		inline void setY2(int y) { m_p2.setY(y); }
		
		// Calculates the length of the line
		inline double length() { return m_p1.distanceTo(m_p2); }
		
		// Overloaded == operator to check if one Line is the same as another
		bool operator== (const Line& other);
		
		// Overloarded = operator to set member variables of this Line to those of another
		void operator= (const Line& other);
	
	// Overloads cout's << to display a Line as a string	
	friend ostream& operator<< (ostream& os, const Line& ln);
	
}; // End of class Line

#endif
