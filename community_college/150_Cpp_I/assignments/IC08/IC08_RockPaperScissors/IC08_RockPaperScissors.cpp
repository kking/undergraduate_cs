/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #08
* LAST MODIFIED:	09/20/18
*
* Rock Paper Scissors *********************************************************
*
* PROGRAM DESCRIPTION: 
* This program will simulate a rock-paper-scissors game. Two users are to enter 'P', 
* 'R', or 'S' to represent their selected hands, and will be presented with the announcement 
* of the winner and his or her means of winning (rock breaks scissors, paper covers rock, 
* scissors cut paper).
* 
* ALGORITHM:
* 1. PROMPT "Player One - Enter R... P... or S..."
* 2. READ player one
* 3. PROMPT "Player Two - Enter R... P... or S..."
* 4. READ player two
* 5. SWITCH (lowercase player 1) - (uppercase player 2)
* 6.   CASE 31; 'r' - 'S'
* 7.     PRINT "Player 1 wins! Rock breaks scissors."
* 8.   CASE 30; 'p' - 'R'
* 9.     PRINT "Player 1 wins! Rock breaks scissors."
* 10.  CASE 35; 's' - 'P'
* 11.    PRINT "Player 1 wins! Rock breaks scissors."
* 12.  CASE 34; 'r' - 'P'
* 13.    PRINT "Player 1 wins! Rock breaks scissors."
* 14.  CASE 29; 'p' - 'S'
* 15.    PRINT "Player 2 wins! Scissors cut paper."
* 16.  CASE 33; 's' - 'R'
* 17.    PRINT "Player 2 wins! Rock breaks scissors."
* 18.  CASE 32; draw
* 19.    PRINT "It's a draw!"
* 20.    IF player 1 == 'R'
* 21.      PRINT "Rock befriends rock."
* 22.    ELSE IF player 1 == 'P'
* 23.      PRINT "Paper favors paper."
* 24.    ELSE
* 25.      PRINT "Scissors become sisters."
* 26.  DEFAULT;
* 27.    PRINT "You have entered an invalid choice..."
* 28.    CLOSE program
* 29. END SWITCH
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* cctype - provides set of functions to classify and manipulate characters
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main(int argc, char** argv) 
{	
	/** DECLARATIONS **/
	char handOne, handTwo;
	
	/** INPUT **/
	cout << "Player One - Enter R for Rock, P for Paper, or S for Scissors: ";
	cin >> handOne;
	
	cout << "Player Two - Enter R for Rock, P for Paper, or S for Scissors: ";
	cin >> handTwo;
	
	cout << endl;
	
	/** PROCESSING AND OUTPUT **/
	switch (tolower(handOne) - toupper(handTwo))
	{
		case 31: // Rock p1 beats scissors p2; 'r' - 'S', or 114 - 83
			cout << "Player 1 wins! Rock breaks scissors.";
			break;
		case 30: // Paper p1 beats rock p2; 'p' - 'R', or 112 - 82
			cout << "Player 1 wins! Paper covers up rock.";
			break;
		case 35: // Scissors p1 beats paper p2; 's - 'P', or 115 - 80
			cout << "Player 1 wins! Scissors cut paper.";
			break;
		case 34: // Rock p1 loses to paper p2; 'r' - 'P', or 114 - 80
			cout << "Player 2 wins! Paper covers up rock.";
			break;
		case 29: // Paper p1 loses to scissors p2; 'p' - 'S', or 112 - 83
			cout << "Player 2 wins! Scissors cut paper.";
			break;
		case 33: // Scissors p1 loses to rock p2; 's' - 'R', or 115 - 82
			cout << "Player 2 wins! Rock breaks scissors.";
			break;
		case 32: // Draw
			cout << "It's a draw! ";
			if (toupper(handOne) == 'R')
				cout << "Rock befriends rock.";
			if (toupper(handOne) == 'P')
				cout << "Paper favors paper.";
			else
				cout << "Scissors become sisters.";
			break;
		default:
			cout << "You have entered an invalid choice. Please enter R, P or S only. Goodbye!\n";
			system("PAUSE");
			return EXIT_FAILURE;
	}
	
	cout << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
