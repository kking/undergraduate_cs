// ==================================================================
// CS311 Yoshii - Hash Table
// 
// HW#: 			HW8 Hash Table
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		implementation htable.cpp
// 
// INSTRUCTION: 	complete all ** parts.
//				Note: this class does not know the parts of element except for key
//				so that it would work even if each element in the hash table changed
// ==================================================================

#include <iostream>
#include "htable.h"

using namespace std;

htable::htable() {
	
}

htable::~htable() {
	
}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key) {
	key = key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element) {
	int slot = hash(element.getkey()); // hash with the key part
	table[slot].addRear(element); // ** adding the element to a slist in the slot (addRear)
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey) { 
	int slot = hash(skey); // hash with skey
	// ** the element to look for in slist - initialize with just the skey
	el_t selement(skey, "");  
	// ** call slist's search2 with selement which returns the found element (could be blank)
	return table[slot].search2(selement); 
}

// displays the entire table with slot#s too
void htable::displayTable() {
	for (int i = 0; i < 37; i++) { 
		cout << i << ":" ;   
		table[i].displayAll(); // call slist's displayAll
    }
}

// end of htable.cpp implementation

