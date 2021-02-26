/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #08
* LAST MODIFIED:	09/20/18
*
* Password Strength ***********************************************************
*
* PROGRAM DESCRIPTION: 
* This program will prompt a user to enter a password twice, ensure that the entries are 
* identical and satisfying the minimum requirements for a NIST standard "enterprise password":
*
* 1. Password should be a minimum of 8 characters in length.
* 2. Password must meet at least three of the four following criteria:
*    Contains at least one uppercase letter
*    Contains at least one lowercase letter
*    Contains at least one number
*    Contains at least one of the following symbols: !@#$%^&*()
* 
* ALGORITHM:
* 1.  PROMPT "Please enter your enterprise password"
* 2.  READ password
* 3.  PROMPT "Confirm your password"
* 4.  READ confirmation
* 5.  IF password == confirmation
* 6.    PRINT "Passwords match."
* 7.  ELSE
* 8.   PRINT "Passwords do not match."
* 9.   CLOSE program
* 10. FOR each character c in password
* 11.   IF c is uppercase
* 12.     SET hasUpperCase = 1
* 13.   IF c is lowercase
* 15.     SET hasLowerCase = 1
* 15.   IF c is a digit
* 16.     SET hasDigit = 1
* 17.   IF c is any of the following: !@#$%^&*()
* 18.     SET hasSymbol = 1
* 19. END FOR
* 20. IF password length is < 8 characters
* 21.   PRINT "Password should be a minimum of 8... "
* 22.   CLOSE program
* 23. IF (hasUpperCase + hasLowerCase + hasDigit + hasSymbol) < 3
* 24.   PRINT "Password does not meet NIST requirements."
* 25.   PRINT "Add 1 or more of the following criteria."
* 26.   IF hasUppercase = false
* 27.     PRINT "At least one uppercase letter"
* 28.   IF hasLowercase = false
* 29.     PRINT "At least one lowercase letter"
* 30.   IF hasDigit = false
* 31.     PRINT "At least one digit"
* 32.   IF hasSymbol = false
* 33.     PRINT "At least one symbol"
* 34.   CLOSE program
* 35. END IF
* 36. ELSE
* 37.   PRINT "The enterprise password was successfully set."
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) 
{
	/** DECLARATIONS **/
	string password, confirmation;
	bool hasUpperCase = 0, hasLowerCase = 0, hasDigit = 0, hasSymbol = 0;
	char c; // Refers to current character during the iteration through the given password
	
	/** INPUT **/
	cout << "Please enter your enterprise password: \n";
	cin >> password;
	
	cout << "Confirm your password: \n";
	cin >> confirmation;
	
	/** PROCESSING  AND OUTPUT **/
	// Determine equivalency of the given passwords
	if (password == confirmation)
	{
		cout << "\nPasswords match.\n\n";
	}
	else
	{
		cout << "\nPasswords do not match.\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	// Evaluate each character of the password to determine if the password contains
	// an uppercase symbol, lowercase symbol, or one of the miscellanous symbols: !@#$%^&*()
	for (int i = 0; i < password.size(); i ++)
	{
		c = password[i];
		
		// Check if uppercase based on range of uppercase letters in ASCII table
		if (! hasUpperCase && (c >= 65 && c <= 90))
			hasUpperCase = true;
			
		// Check if lowercase "
		if (! hasLowerCase && (c >= 97 && c <= 122))
			hasLowerCase = true;
			
		// Check if character is a digit "
		if (! hasDigit && (c >= 48 && c <= 57))
			hasDigit = true;
		
		// Check if character is any of the following symbols: !@#$%^&*()
		if (! hasSymbol	&& (c == 33 || c == 64 || c == 35 || c == 36 || c == 37 || c == 94 || c == 38 || c == 42 || c == 40 || c == 41))
			hasSymbol = true;
			
	}
	
	// Determine if password is at least 8 characters in length
	if (password.size() < 8)
	{
		cout << "Password should be a minimum of 8 characters in length.\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	// Determine if password fits at least three of the four criteria
	if (hasUpperCase + hasLowerCase + hasDigit + hasSymbol < 3)
	{	
		cout << "The \"" << password << "\" password does not meet the minimum requirements of NIST.\n"
			<< "Please add 1 or more of the following criteria: \n";
			
		if (! hasUpperCase)
			cout << "At least one uppercase letter\n";
		if (! hasLowerCase)
			cout << "At least one lowercase letter\n";
		if (! hasDigit)
			cout << "At least one digit\n";
		if (! hasSymbol)
			cout << "At least one symbol\n";
			
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	cout << "The enterprise password has successfully been set.\n";
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
