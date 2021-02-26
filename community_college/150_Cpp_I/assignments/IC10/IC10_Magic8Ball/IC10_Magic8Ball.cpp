/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #10
* LAST MODIFIED:	09/26/18
*
* Magic 8 Ball ****************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will simulate the Magic 8 Ball game.
* 
* ALGORITHM:
* 1.  DO
* 2.    PROMPT "What question would you like to ask ... ?"
* 3.    READ question
* 4.    CALCULATE answer = random integer from 1 to 8
* 5.    PRINT "The answer is: ... "
* 6.    SWITCH (answer)
*         CASE 1: PRINT "It is certain."
*         CASE 2: PRINT "It is decidedly so."
*         CASE 3: PRINT "Most likely."
*         CASE 4: PRINT "Signs point to yes."
*         CASE 5: PRINT "Reply hazy, try again."
*         CASE 6: PRINT "Ask again later."
*         CASE 7: PRINT "Don't count on it."
*         CASE 8: PRINT "My sources say no."
* 7.    END SWITCH
* 8.    PROMPT "Would you like to ask another question (Y/N)?"
* 9.    READ repeat
* 10. END DO, WHILE repeat != "N" and repeat != "n"
* 11. PRINT "Thank you for playing the Magic 8 Ball."
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* cctype - set of functions to classify and manipulate characters
* ctime - for manipulation of date and time information
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cctype>
#include <ctime>

using namespace std;

int main(int argc, char** argv) 
{
	/** DECLARATIONS **/
	string question, repeat;
	int answer;
	
	do 
	{
	/** INPUT **/
		cout << "What question would you like to ask the Magic 8 ball? \n";
		cin >> question;
		
		getline(cin, question);
		
	/** PROCESSING **/
		// Generate random integer from 1 to 8
		srand(time(NULL));
		answer = rand() % 8 + 1;
		
		cout << "The answer is: ";
		
	/** OUTPUT **/
		switch (answer) 
		{	
			case 1:
				cout << "It is certain";
				break;
			case 2:
				cout << "It is decidedly so";
				break;
			case 3:
				cout << "Most likely";
				break;
			case 4:
				cout << "Signs point to yes";
				break;
			case 5:
				cout << "Reply hazy, try again";
				break;
			case 6:
				cout << "Ask again later";
				break;
			case 7:
				cout << "Don't count on it";
				break;
			case 8:
				cout << "My sources say no";
				break;
			default:
				break;
		}
		
		cout << "\n\nWould you like to ask another question (Y/N)? \n";
		cin >> repeat;
		
		cout << endl;

	} while (repeat != "N" && repeat != "n");
	
	cout << "Thank you for playing the Magic 8 Ball.";
	
	return 0;
}
