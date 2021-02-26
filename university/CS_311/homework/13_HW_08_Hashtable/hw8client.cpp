// ==================================================================
// CS311 Yoshii - HW8 Client file
// 
// HW#: 			HW8 hashing client
// NAME: 			King
// COMPILER: 		g++
// FILE TYPE: 		client hw8client.cpp (tester)
// 
// INSTRUCTION: 	Note that the client knows about elem.h functions.
//				It can create el_t objects.
//				This tester gets input data interactively but
//				for a useful client, input should come from a file.
//				Note that el_t X; will create a blank element X using the regular constructor.
//				Note that the second constructor of el_t can be used to
//				create key+name to add to the table. e.g. el_t X(30, "mary");
// ==================================================================
// PURPOSE: 		This program will demonstrate the functionality of the custom "htable.h"
//				hash table implementation containing elements of the el_t class type.
//				
// ALGORITHM: 		1. FOR 20 iterations:
//					a. READ a key,
//					b. READ a name,
//					c. Add a new element with the given key and name to the table.
//				2. DISPLAY the table, with each index followed by its corresponding linked list.
//				3. WHILE the user has entered an integer >= 0:
//					a. READ a key,
//					b. IF the key is >= 0, obtain the el_t found in the table,
//					c. IF the el_t's key != -1, PRINT "Found...".
//					d. ELSE, PRINT "... not found."
// ==================================================================

#include <iostream>
#include "htable.h"

using namespace std;

int main()
{
	htable table; // the hashtable
	int key;      // an integer key from user input
	string name;  // a name from user input
	
	// Loop to interactively add about 20 keys and names to the table,
	// making sure some of them collide (function add). You can create el_t
	// containing a key and name using a constructor.
	for (int i = 0; i < 20; i++) {
		cout << "Enter a key: ";
		cin >> key;
		cout << "Enter a name: ";
		cin >> name;
		
		el_t newElement(key, name);
		table.add(newElement);
	}
	
	cout << endl << "========== The Hashtable: ==========" << endl;
	table.displayTable(); // display the table
	cout << "====================================" << endl;
	
	// Loop to interactively look up names using keys (function find). Print
	// the key + name if found else (blank element was returned i.e. key part is -1)
	// an error message.
	while (key >= 0) {
		cout << "Look for? ";
		cin >> key;
		
		if (key >= 0) {
			el_t foundElement = table.find(key);
			if (foundElement.getkey() != -1) {
				cout << "Found " << key << ": " << foundElement << endl;
			}
			else {
				cout << key << " not found." << endl;
			}
		}
	}
	
	cout << "Done." << endl;
    
 } // end of main
 
