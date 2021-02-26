#include "SurfboardList.h"
#include "Surfboard.h"

bool SurfboardList::addBoard(Surfboard sb) {
    // Check if list is full (m_count >= SIZE - 1)
    if (m_count >= SIZE - 1)
        return false;
    else {
        // Add the Surfboard to m_list
        m_list[m_count++] = sb;
        return true;
    }
}

bool SurfboardList::removeBoard(int id) {
    // Loop through the list to find the board's id
    for (int i = 0; i < m_count; i++) {
        // If a match is found, move everything down
        if (m_list[i].getId() == id) {
        	for (int j = i; j < m_count; j ++) {
        		m_list[j] = m_list[j+1];
    		}
        	m_count--;
        	return true;
        }
    }
    // A match was not found, return false
    return false;
}
             
ostream& operator<< (ostream& os, const SurfboardList& sb) {
    os << "~~~Current Inventory of Surfboards~~~\n";
    
    if (sb.m_count > 0) {
    	for (int i = 0; i < sb.m_count; i++) {
        	os << sb.m_list[i] << endl;
		}
	}
	else {
		os << "[Empty]" << endl;
	}
       
    return os;
}
