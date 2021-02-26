// ==================================================================
// CS311 Yoshii
// 
// HW#: 			HW2P1 Binary Search
// NAME: 			King
// COMPILER: 		g++
// ==================================================================

#include <iostream>	// for console input/output
#include <cmath>	// for floor function

using namespace std;

// PARAM L: a n array of integers to be searched
// PARAM x: the element to be found in L
// PARAM first, last: slot numbers
// RETURNS: the slot number in which x was found, or -1 if x is not found
int binarySearch(int L[], int x, int first, int last) {
	
	// Compare with middle entry
	int middle = floor((first+last)/2); // use floor to round down
	cout << "binarySearch: comparing against an element in slot " << middle << endl;
		
	if (x == L[middle]) {
		return middle; // base case: found x at middle, so return the location
	}
	else if (first == last) {
		return -1; // base case: last element and x is not found, so return -1
	}
	else if (x < L[middle]) {
		last = middle - 1; // go to first half
	}
	else if (x > L[middle]) {
		first = middle + 1; // go to second half
	}
		
	return binarySearch(L, x, first, last); // recursive call


} // end of binarySearch

int main() { 

	int A[10]; // array to contain fixed elements
	int element;  // element to be found in A

	// define elements for A
	A[0] = 1;  A[1] = 3; 
	A[2] = 5;  A[3] = 7; 
	A[4] = 9;  A[5] = 11; 
	A[6] = 13; A[7] = 15; 
	A[8] = 17; A[9] = 19;
	
	cout << "> What do you want to look for? ";
	cin >> element;
	
	// call binarySearch here to look for element in A
	int respos = binarySearch(A, element, 0, 9);
	
	if (respos == -1) {
		cout << "> Element " << element << " not found" << endl; 
	}
	else {
		cout << "> Found element " << element << " in position " << (respos+1) << endl;
	}

} // end of main

