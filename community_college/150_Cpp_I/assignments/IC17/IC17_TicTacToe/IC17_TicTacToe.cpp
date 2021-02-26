/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #17
* LAST MODIFIED:	10/25/18
*
* Tic-Tac-Toe *****************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will use multi-dimensional arrays to simulate a tic-tac-toe game.
* 
* ALGORITHM:
* 1.  CALL resetBoard with a 2D array representing board
* 2.    FOR i = 0 through 3 rows
* 3.      FOR j = 0 through 3 columns
* 4.        board[i][j] = '*'
* 5.      END FOR
* 6.    END FOR
* 7.  END resetBoard
* 8.  DO, WHILE moves < 9 and won == false
* 9.    CALL printBoard with the board 
* 10.     PRINT top of board, "----- ..."
* 11.     FOR i = 0 through 3 rows
* 12.       FOR j = 0 through 3 columns
* 13.         PRINT "| " + board[i][j] + " "
* 14.       END FOR
* 15.       PRINT "|" and row divider, "--- ..."
* 16.     END FOR
* 17.   END printBoard
* 18.   PRINT "Please enter row: "
* 19.   READ row as an integer 1-3
* 20.   PRINT "Please enter column: "
* 21.   READ column as an integer 1-3
* 22.   IF moves is even, player is 'X'
* 23.   ELSE, player is 'O'
* 24.   IF board at selected coordinates is not '*'
* 25.     PRINT "This space is taken ..."
* 26.   ELSE
* 27.     set board at selected coordinates to player symbol
* 29.     moves ++
* 30.     CALL win to validate if a game has been won
* 31.       RETURN true if the board has a winning tic-tac-toe configuration, false otherwise
* 32.     END win
* 33. END DO, WHILE moves < 9 and won == false
* 34. CALL printBoard (steps 9 through 17)
* 35. IF game has been won, PRINT winner
* 36. ELSE, PRINT "The game is a draw!"
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

/** CONSTANTS **/
const int ROWS = 3, COLUMNS = 3;

/** FUNCTION PROTOTYPES **/
void resetBoard(char board[][COLUMNS], int ROWS);
void printBoard(char board[][COLUMNS], int ROWS);
bool win(char board[][COLUMNS], int ROWS);
double getValidInput(string message, string error, double min, double max);

int main(int argc, char** argv) {
	/** A 2D array representing a tic-tac-toe board. */
	char board[ROWS][COLUMNS];
	
	int row, column, numMoves = 0;
	char player;
	bool gameWon = false;
	
	// Creates a new board
	resetBoard(board, ROWS);
	
	do {
		// Display current board to console
		printBoard(board, ROWS);
		
		// Obtain coordinates for current player's move
		row = getValidInput("Please enter row: ", "Error: Input must be in range [1. 3].", 1, 3);
		column = getValidInput("Please enter column: ", "Error: Input must be in range [1, 3].", 1, 3);
		
		// Current player is 'X' if the current move is even 'Y' if odd
		player = ((numMoves % 2 == 0) ? 'X' : 'O');
		
		// Validate that the given space is available
		if (board[row - 1][column - 1] != '*') {
			cout << "This space is taken! Try again.\n";
		}
		else {
			// Mark board with current player's character at the given coordinates
			board[row - 1][column - 1] = player;
			
			// Increment number of moves taken
			numMoves ++;
			
			// Sets true if game has been won
			gameWon = win(board, ROWS);
		}
		
	} while ((numMoves < 9) && (! gameWon));
	
	// Print final board
	printBoard(board, ROWS);
	
	// Declare the winner of the game has been won. Otherwise state that it is a draw
	if (gameWon) {
		cout << "Player \'" << player << "\' wins!\n";
	}
	else {
		cout << "This game ends in a draw!\n";
	}

	system("pause");
	return EXIT_SUCCESS;
	
} // End of main

/** FUNCTION IMPLEMENTATIONS */
/**
 * Prints a 3x3 board for the current tic-tac-toe game.
 *
 * @param board a 3x3 multi-dimensional array representing a tic-tac-toe board
 * @param ROWS the number of rows which define the first dimension of board
 */
void resetBoard(char board[][COLUMNS], int ROWS) {
	// Populate board with initial symbol
	for (int i = 0; i < ROWS; i ++) {
		for (int j = 0; j < COLUMNS; j ++) {
			board[i][j] = '*';
		}
	}
}

/**
 * Prints a 3x3 board for the current tic-tac-toe game.
 *
 * @param board a 3x3 multi-dimensional array representing a tic-tac-toe board
 * @param ROWS the number of rows which define the first dimension of board
 */
void printBoard(char board[][COLUMNS], int ROWS) {
	// Print all values of board
	cout << "-------------\n";
	
	for (int i = 0; i < ROWS; i ++) {
		for (int j = 0; j < COLUMNS; j ++) {
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << "\n-------------\n";
	}	
}

/**
 * Determines if a winning board has been set by either player in a 3x3 two-dimensional array representing a tic-tac-toe game.
 *
 * @param board a 3x3 multi-dimensional array representing a tic-tac-toe board
 * @param ROWS the number of rows which define the first dimension of board
 * @return true if either player populates three in a row horizontally, vertically, or diagonally- false otherwise
 */
bool win(char board[][COLUMNS], int ROWS) {
	
	return ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && (board[0][0] != '*')) || // Horizontal row 0
		((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && (board[1][0] != '*')) || // Horizontal row 1
		((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && (board[2][0] != '*')) || // Horizontal row 2
		
		((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && (board[0][0] != '*')) || // Vertical col 0
		((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && (board[0][1] != '*')) || // Vertical col 1
		((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && (board[0][2] != '*')) || // Vertical col 2
		
		((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != '*')) || // Diagonal
		((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[2][0] != '*'));   // Diagonal
}

/**
 * Function handling input validation.
 *
 * @param message a custom message prompting for user input
 * @param error an error message to be presented in the case of erroneous input
 * @param min the minimum numerical value for user input
 * @param max the maximum numerical value for user input
 * @return a valid number entered by the user
 */
double getValidInput(string message, string error, double min, double max) 
{
	bool inputFail;
	double input;
	
	do {
		cout << message;
		cin >> input;
		
		// Input validation;
		// fails if wrong data type is read, or input > max or < min
		inputFail = cin.fail() || (input < min) || (input > max);
		
		if (inputFail) {
			cout << error << endl;
			cin.clear();               // Clears error flag
			cin.ignore(INT_MAX, '\n'); // Ignores characters up to new line character
		}
		
	} while (inputFail);
	
	return input;
}
