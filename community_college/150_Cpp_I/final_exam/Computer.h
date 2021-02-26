#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>

using namespace std;

class Computer {
	protected:
		// Static Variables
		static int s_nextId; // to start at 100
		
		// Member Variables
		int m_id;
		string m_make, m_model;
		double m_price;
	public:
		// Constructors
		Computer();
		Computer(string make, string model, double price);
		
		// Accessors
		inline int getId() const { return m_id; }
		inline string getMake() const { return m_make; }
		inline string getModel() const { return m_model; }
		inline double getPrice() const { return m_price; }
		
		// Mutators
		inline void setMake(string make) { m_make = make; }
		inline void setModel(string model) { m_model = model; }
		inline void setPrice(double price) { m_price = price; }
		
		// Evaluate equivalency of two Computers
		bool operator==(const Computer& other);
		
		// For output to console
		friend ostream& operator<<(ostream& os, const Computer& c);
};

#endif
