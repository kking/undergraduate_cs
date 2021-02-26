// ==================================================================
// CS311 Yoshii
// 
// HW#:			HW1P1 stack application (post-fix evaluation)
// NAME:		King
// COMPILER:	g++
// FILE TYPE:	client program client1.cpp
// 
// INSTRUCTION:	Look for ** to complete the program (do control-S)
// 				The output should match my hw1stackDemo.out
// ==================================================================
// PURPOSE:		This client program will evaluate postfix expressions by the use of a stack. These
// 				postfix expressions are comprised only of single-digit operands and the following
// 				oeprators: addidion (+), subtraction (-), division (/), and multiplication (*).
//
// ALGORITHM: 	1. PRINT "type a postfix expression"
// 				2. WHILE expression[index++] != '\0'
// 					3. READ an item (a character)
// 					4. IF it is an operand (number)
// 						a. push it (may throw Overflow "expression is too long")
// 					5. ELSE IF it is an operator ('+', '-', '/', or '*'),
// 						a. pop the two operands (may throw Underflow, "too few operands/numbers")
// 						b. apply the operator to the two operands
// 						c. push the result
// 					6. ELSE it is an invalid item (throws exception)
// 				7. END WHILE. if successful, the result will be at the top of the stack.
// 				8. PRINT result after popping
// 				9. IF anything is still left on the stack, PRINT "incomplete expression found."
// ==================================================================

#include <iostream>
#include <stdlib.h>
#include <string>

#include "stack.h"

using namespace std;

int main() {
	stack postfixstack;  // integer stack
	string expression;   // user entered expression
	  
	int i = 0;  // character position within expression
	char item;  // one char out of the expression
	  
	int box1, box2;  // receive things from pop
	
	cout << "type a postfix expression: " ;
	cin >> expression;
	  
	while (expression[i] != '\0') {
		try {
			item = expression[i];  // read an item (a character)
	
			if (isdigit(item)) {
				postfixstack.push(item - '0'); // push operand; throws Overflow
			}
			else if (item == '+' || item == '-' || item == '/' || item == '*') {
				// pop two operands (throws Underflow)
				postfixstack.pop(box2); // right operand
				postfixstack.pop(box1); // left operand
				
				// apply the operator to the two operands, and push the result
				switch (item) {
					case '+':
						postfixstack.push(box1 + box2);
						break;
					case '-':
						postfixstack.push(box1 - box2);
						break;
					case '/':
						postfixstack.push(box1 / box2);
						break;
					case '*':
						postfixstack.push(box1 * box2);
						break;
					default: 
						break;
				}
			}
			else {
				throw "ERROR: invalid element.";
			}
		} // end of try
		catch (stack::Overflow) {
			cerr << "ERROR: overflow occurred - expression is too long.\n";
			exit(1);
		}
		catch (stack::Underflow) {
			cerr << "ERROR: underflow occured - too few operands/numbers.\n";
			exit(1);
		}
		catch (char const* errormsg) {
			cerr << errormsg << '\n'; // invalid item case
			exit(1);
		}

		i++; // goto loop after incrementing expression index i
		
	} // end of while; successful completion means the result will be at the top.
	
	try {
		postfixstack.pop(box1); // pop result; throws Underflow
	}
	catch (stack::Underflow) {
		cerr << "ERROR: underflow occured - too few operands/numbers.\n";
		exit(1);
	}
	
	cout << "result = " << box1 << '\n'; // print result
	
	if (!postfixstack.isEmpty()) {
		cout << "Incomplete expression found - stack is not empty.\n"; // incomplete expression found
	}	

} // end of main

/*
into Test2.txt:

1.  34+ (7)
2.  345+* (27)
3.  722+- (3)
4.  34+56++ (18)
5.  12+34*45+-+ (6)
6.  1234567891234 (expression too long)
7.  + (too few operands)
8.  3+ (too few operands)
9.  3# (invalid element)
10. 2345+ (incomplete expression)
*/
