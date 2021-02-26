/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #09
* LAST MODIFIED:	09/25/18
*
* Basic Calculator ************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will process two operands as a simple calculator with the following 
* operations:
*
* '+' for addition
* '-' for subtraction
* '*' for multiplication
* '/' for division
* '%' for modulo
* '^' for exponentiation
* 
* ALGORITHM:
* 1. PRINT menu, prompting to "type one of the following operators ... "
* 2. READ operator
* 3. PROMPT "Enter an operand (number) ... "
* 4. READ first operand
* 5. PROMPT "Enter an operand (number) ... "
* 6. READ second operand
* 7. SWITCH (operator)
*      CASE '+':
*        CALCULATE result = first + second
*      CASE '-':
*        CALCULATE result = first - second
*      CASE '*':
*        CALCULATE result = first * second
*      CASE '/':
*        CALCULATE result = first / second
*      CASE '%':
*        CALCULATE result = first % second
*      CASE '^':
*        CALCULATE result = first ^ second
*      DEFAULT:
*        PRINT "Error! Operator undefined ... "
*        CLOSE program
*    END SWITCH
* 8. PRINT result
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* cmath - enables use of mathematical functions
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv) 
{
	/** DECLARATIONS **/
	char op;
	int operandOne, operandTwo;
	double result;
	
	/** INTRO **/
	cout << "**********************************************************************\n"
		<< "**                                                                  **\n"
		<< "**                WELCOME TO KING'S BASIC CALCULATOR                **\n"
		<< "**                                                                  **\n"
		<< "**********************************************************************\n"
		<< "Type one of the following operators: \n"
		<< "+ (for adding numbers) \n- (for subtracting numbers) \n"
		<< "* (for multiplyig numbers) \n/ (for dividing numbers) \n"
		<< "% (for dividing the remainder when two numbers are divided) \n"
		<< "^ (for exponentiation - one number raised to the power of the other) \n"
		<< "**********************************************************************\n";
		
	/** INPUT **/
	cin >> op;
	
	cout << "Enter an operand (number): ";
	cin >> operandOne;
	
	cout << "Enter an operand (number): ";
	cin >> operandTwo;
	
	/** PROCESSING **/
	switch (op)
	{
		case '+':
			result = operandOne + operandTwo;
			break;
		case '-':
			result = operandOne - operandTwo;
			break;
		case '*':
			result = operandOne * operandTwo;
			break;
		case '/':
			result = double(operandOne) / operandTwo;
			break;
		case '%':
			result = operandOne % operandTwo;
			break;
		case '^':
			result = pow(operandOne, operandTwo);
			break;
		default:
			cout << "Error! Operator undefined in this version of the calculator.\n";
			system("PAUSE");
			return EXIT_FAILURE;
	}
	
	/** OUTPUT **/
	cout << fixed << setprecision(2) 
		<< operandOne << " " << op << " " << operandTwo << " = " << result << "\n\n";
	
	system("PAUSE");
	return EXIT_FAILURE;
}
