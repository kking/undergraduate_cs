/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #20
* LAST MODIFIED:	11/05/18
*
* Soccer Players **************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will create a database for an 11-person soccer team.
* 
* ALGORITHM:
* 1.  PRINT app header, "PLAYER ENTRY..."
* 2.  FOR i = 0 through 11 players
* 3.    PRINT "For Player #" + i+1
* 4.    PROMPT "Enter Player's Name: "
* 5.    READ current player's name
* 6.    PROMPT "Enter Jersey Number: "
* 7.    READ current player's jersey number as an integer >= 0
* 8.    PROMPT "Enter Goals Scored: "
* 9.    READ current player's number of goals scored as an integer >= 0
* 10.   total goals += current player's number of goals scored
* 11.   IF player's goals > most goals
* 12.     most goals = player's goals
* 13.     player name = player's name
* 14.   END IF
* 15. PRINT output header, "STARTING LINEUP..."
* 16. FOR i = 0 through 11 players
* 17.   PRINT player's jersey number, name, and goals scored
* 18. END FOR
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - manipulation of I/O
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Structure for a soccer player
struct SoccerPlayer {
	string name;
	int jerseyNumber, goalsScored;
};

/** FUNCTION PROTOTYPES **/
void printAppHeader();
void printOutputHeader();
double getValidInput(string message, string error, double min, double max);

/** CONSTNANTS **/
const int NUM_PLAYERS = 11;

int main(int argc, char** argv) {
	// Instantiate an array to be comprised of 11 SoccerPlayers
	SoccerPlayer team[NUM_PLAYERS];
	int totalGoals = 0, mostGoals = -1;
	string mostGoalsPlayer;
	
	// Print app header, "PLAYER ENTRY..."
	printAppHeader();
	
	for (int i = 0; i < NUM_PLAYERS; i ++) {
		cout << "~~~For Player #" << ((i+1 < 10) ? "0" : "") << i+1 << "~~~\n";
		
		// Read current SoccerPlayer's data
		cout << "Enter Player's Name: ";
		getline(cin, team[i].name);
		team[i].jerseyNumber = getValidInput("Enter Jersey Number: ", "Error: ", 0, INT_MAX);
		team[i].goalsScored = getValidInput("Enter Goals Scored : ", "Error: ", 0, INT_MAX);
		
		// Add current SoccerPlayer's number of goals scored to team total
		totalGoals += team[i].goalsScored;
		
		// Determine if current SoccerPlayer's number of goals scored is the team's highest
		if (team[i].goalsScored > mostGoals) {
			mostGoals = team[i].goalsScored;
			mostGoalsPlayer = team[i].name;
		}
		
		cout << endl;
	}
	
	// Print output header, "STARTING LINEUP..."
	printOutputHeader();
	
	// Print each SoccerPlayer's data to the console
	for (int i = 0; i < NUM_PLAYERS; i++) {
		cout << left << setw(15) << team[i].jerseyNumber
			<< setw(30) << team[i].name
			<< team[i].goalsScored << endl;
	}
	
	// Print the total goals, and the player who scored the most goals and the associated number
	cout << "\nThe total goals scored by the team is " << totalGoals << endl
		<< "The player with the most goals is " << mostGoalsPlayer
		<< " with " << mostGoals << " goals.\n";
	
	system("pause");
	return EXIT_SUCCESS;
}

/** FUNCTION IMPLEMENTATIONS **/

// Print the app's header to the console
void printAppHeader() {
	cout << "******************************************************\n"
		<< "                     PLAYER ENTRY                     \n"
		<< "                  LOS ANGELES GALAXY                  \n"
		<< "******************************************************\n";
}

// Prints the Starting Lineup header to the console
void printOutputHeader() {
	cout 
		<< "******************************************************\n"
		<< "                    STARTING LINEUP                   \n"
		<< "******************************************************\n"
		<< "JERSEY #       PLAYER NAME                   GOALS\n"
		<< "******************************************************\n"; 
}

// Function handling input validation
double getValidInput(string message, string error, double min, double max) {
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

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	return input;
}
