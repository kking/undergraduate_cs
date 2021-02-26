#ifndef SURFBOARDLIST_H
#define SURFBOARDLIST_H

#include "Surfboard.h"
class SurfboardList
{
	private:
		const static int SIZE = 100;
		int m_count;
		Surfboard m_list[SIZE];

	public:
    	SurfboardList() { m_count = 0; }
    	
		bool addBoard(Surfboard s);
		bool removeBoard(int id);
		bool updateBoard(int id, string brand, string model, double length, double width, double thickness, int quantity, int price);

	friend ostream& operator<<(ostream& os, const SurfboardList& sl);
};

#endif
