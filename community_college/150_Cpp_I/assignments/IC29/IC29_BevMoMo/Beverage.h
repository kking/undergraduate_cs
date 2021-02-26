#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>

using namespace std;

class Beverage {
	protected:
		// Static variable
		static int s_nextOrderNumber;
		
		// Member variables
		string m_name;
		int m_orderNumber, m_size, m_calories;
	public:
		// Constructors
		Beverage();
		Beverage(string name, int calories, int size);
		
		// Accessors
		inline int getCalories() const { return m_calories; }
		inline string getName() const { return m_name; }
		inline int getOrderNumber() const { return m_orderNumber; }
		inline int getSize() const { return m_size; }
		
		// Mutators
		inline void setCalories(int calories) { m_calories = calories; }
		inline void setName(string name) { m_name = name; }
		inline void setSize(int size) { m_size = size; }
		
		bool operator==(const Beverage& other);
		
	friend ostream& operator<<(ostream& os, const Beverage& b);
};

#endif
