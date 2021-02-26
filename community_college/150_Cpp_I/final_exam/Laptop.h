
#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computer.h"

using namespace std;

class Laptop : public Computer {
	private:
		// Member Variables
		double m_batteryLife, m_weight;
	public:
		// Constructors
		Laptop();
		Laptop(string make, string model, double price, double batteryLife, double weight);
		
		// Accessors
		inline double getBatteryLife() const { return m_batteryLife; }
		inline double const getWeight() const { return m_weight; }
		
		// Mutators
		inline void setBatteryLife(double batteryLife) { m_batteryLife = batteryLife; }
		inline void setWeight(double weight) { m_weight = weight; }
		
		// Evaluates equivalency of two Laptops
		bool operator==(const Laptop& other);
	
		// For output to console
		friend ostream& operator<<(ostream& os, const Laptop& l);
};

#endif
