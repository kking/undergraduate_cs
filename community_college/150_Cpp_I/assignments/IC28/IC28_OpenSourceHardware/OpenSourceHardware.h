// Header file for OpenSourceHardware, a base class to contain data and behaviors which
// define open source hardware.

#ifndef OPENSOURCEHARDWARE_H
#define OPENSOURCEHARDWARE_H

#include <string>
#include <iostream>

using namespace std;

class OpenSourceHardware {
	protected:
		string m_model;
		double m_power, m_price;
		
		// Constructors
		OpenSourceHardware();
		OpenSourceHardware(string model, double power, double price);
	public:
		// Accessors
		inline string getModel() const { return m_model; }
		inline double getPower() const { return m_power; }
		inline double getPrice() const { return m_price; }
		
		// Mutators
		inline void setModel(string model) { m_model = model; }
		inline void setPower(double power) { m_power = power; }
		inline void setPrice(double price) { m_price = price; }
		
		bool operator==(const OpenSourceHardware& other);
};

#endif
