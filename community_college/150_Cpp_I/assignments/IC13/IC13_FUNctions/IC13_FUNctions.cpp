/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #13
* LAST MODIFIED:	10/09/18
*
* FUNctions *******************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will use functions to calculate and display the number of capital letters,
* lowercase letters, vowels, and consonants in a string receivied from the console.
* 
* ALGORITHM:
* 1.  PROMPT "Enter a string"
* 2.  READ string
* 3.  CALCULATE the number of uppercase letters in the given string
* 4.    FOR each letter in the given string
* 5.      IF current character is within the range 'A'-'Z'
* 6.        INCREMENT uppercase letters
* 7.    END FOR
* 8.  CALCULATE the number of lowercase letter characters
* 9.    FOR each letter in the given string
* 10.     IF current character is within the range 'a'-'z'
* 11.       INCREMENT lowercase letters
* 12.   END FOR
* 13. CALCULATE the number of vowels
* 14.   FOR each letter in the given string
* 15.     IF current character is 'a', 'e', 'i', 'o', or 'u'
* 16.       INCREMENT vowels
* 17.   END FOR
* 18. CALCULATE the number of consonants
* 19.   FOR each letter in the given string
* 20.     IF current character is NOT 'a', 'e', 'i', 'o', or 'u'
* 21.       INCREMENT consonants
* 22.   END FOR
* 23. PRINT number of capital letters, lowercase letters, vowels, and consonants
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

/** FUNCTION PROTOTYPES **/
int countCapitals(string word);
int countLowercaseLetters(string word);
int countVowels(string word);
int countConsonants(string word);

int main(int argc, char** argv) 
{
	/** DECLARATIONS **/
	string input;
	
	/** INPUT **/
	cout << "Enter a string: ";
	getline(cin, input); // Read whole line
	
	/** PROCESSING AND OUTPUT **/
	cout << "\nThe string \"" << input << "\" has: \n\n"
		<< left << setw(3) << countCapitals(input) << " capital letter(s)\n"
		<< left << setw(3) << countLowercaseLetters(input) << " lowercase letter(s)\n"
		<< left << setw(3) << countVowels(input) << " vowel(s)\n"
		<< left << setw(3) << countConsonants(input) << " consonant(s)\n" << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
	
} // End of main function

/** FUNCTION IMPLEMENTATIONS **/
/**
 * Returns the number of uppercase letter characters in the given input string.
 *
 * @param word any string
 * @return the number of uppercase letters contained in the string
 */
int countCapitals(string word) {
	int numCapitals = 0;
	char temp;
	
	for (int i = 0; i < word.length(); i ++) {
		temp = word[i];
		// If current character is >= 'A' and <= 'Z', increment count
		if (temp >= 65 && temp <= 90) {
			numCapitals ++;
		}
	}
	
	return numCapitals;
}

/**
 * Returns the number of lowercase letter characters in the given input string.
 *
 * @param word any string
 * @return the number of lowercase letters contained in the string
 */
int countLowercaseLetters(string word) {
	int numLowercase = 0;
	char temp;
	
	for (int i = 0; i < word.length(); i ++) {
		temp = word[i];
		// If current character is >= 'a' and <= 'z', increment count
		if (temp >= 97 && temp <= 122) {
			numLowercase ++;
		}
	}
	
	return numLowercase;
}

/**
 * Returns the number of vowel occurences ('a', 'e', 'i', 'o', and 'u') in the given input string.
 *
 * @param word any string
 * @return the number of vowels contained in the string
 */
int countVowels(string word) {
	int numVowels = 0;
	char temp;
	
	for (int i = 0; i < word.length(); i ++) {
		temp = tolower(word[i]); // Convert current character to lowercase
		
		// If current character is 'a', 'e', 'i' 'o', or 'u', increment count
		switch (temp) {
			case 97:  // 'a'
			case 101: // 'e'
			case 105: // 'i'
			case 111: // 'o'
			case 117: // 'u'
				numVowels ++;
				break;
			default:
				break;
		}
	}
	
	return numVowels;
}

/**
 * Returns the number of consonant occurences in the given input string.
 *
 * @param word any string
 * @return the number of consonants contained in the string
 */
int countConsonants(string word) {
	int numConsonants = 0;
	char temp;
	
	for (int i = 0; i < word.length(); i ++) {
		temp = tolower(word[i]); // Convert current character to lowercase
		
		// If current character is a letter character,
		// excluding 'a', 'e', 'i' 'o', or 'u', increment count
		if (temp >= 97 && temp <= 122) {
			switch (temp) {
				case 97:  // 'a'
				case 101: // 'e'
				case 105: // 'i'
				case 111: // 'o'
				case 117: // 'u'
					break;
				default:
					numConsonants ++;
					break;
			}
		}
	}
	
	return numConsonants;
}
