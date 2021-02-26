#ifndef COFFEE_H
#define COFFEE_H

#include "Beverage.h"

using namespace std;

class Coffee : public Beverage {
	private:
		// Member variables
		int m_caffeine;
		string m_roast;
	public:
		// Constructors
		Coffee();
		Coffee(string name, int calories, int size, int caffeine, string roast);
		
		// Accessors
		inline int getCaffeine() const { return m_caffeine; }
		inline string getRoast() const { return m_roast; }
		
		// Mutators
		inline void setCaffeine(int caffeine) { m_caffeine = caffeine; }
		inline void setRoast(string roast) { m_roast = roast; }
		
		bool operator==(const Coffee& other);
		
	friend ostream& operator<<(ostream& os, const Coffee& c);
};

#endif
