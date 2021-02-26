#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cstdlib>

using namespace std;

// Point: header file for inline functions and function prototypes
class Point {
	
	// Member Variables
	private:
		int m_x, m_y;
	// Member Functions
	public:
		// Constructor (prototype only)
		Point(int x=0, int y=0);
		
		// Accessors
		// 1 line == inline; note const keyword
		inline int getX() const { return m_x; }
		inline int getY() const { return m_y; }
		
		// Mutators
		inline void setX(int x) { m_x = x; }
		inline void setY(int y) { m_y = y; }
		
		// Calculates the distance from this Point to another
		double distanceTo(const Point& other);
		
		// Overloaded == operator to check if one Point is the same as another
		inline bool operator== (const Point& other) {
			return (m_x == other.m_x) && (m_y == other.m_y);
		}
		
		// Overloarded = operator to set member variables of this Point to those of another
		void operator= (const Point& other);
		
	// Overloads cout's << to display a Point as a string
	friend ostream& operator<< (ostream& os, const Point& p);
	
}; // End of class Point

#endif
