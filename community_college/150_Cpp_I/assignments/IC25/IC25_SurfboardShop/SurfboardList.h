#ifndef SURFBOARDLIST_H
#define SURFBOARDLIST_H

#include "Surfboard.h"
#include <iostream>

using namespace std;

class SurfboardList {
    private:
        const static int SIZE = 100; // consts can be initialized in header file
        int m_count;
        Surfboard m_list[SIZE];
    public:
        SurfboardList() { m_count = 0; }
             
        bool addBoard(Surfboard sb);
        bool removeBoard(int id);
             
	friend ostream& operator<< (ostream& os, const SurfboardList& sb);
};

#endif
