/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #02
* LAST MODIFIED:	08/28/18
*
* Hacker Challenge: Face Painting *********************************************
*
* PROGRAM DESCRIPTION:
* As an extention of IC02_TrianglePattern, this program will display the following rabbit's 
* face to the console in a single cout statement:
* (\(\
* (._.)
* c(")(")
* 
* ALGORITHM:
* 1. PRINT a rabbit to the console in one cout statement
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
******************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
	/** OUTPUT **/
	cout << "    ___ /\\        ___ /\\\n"
		<< "   /  / \\ \\      /  / \\ \\\n"
		<< "  /  /   \\ \\    /  /   \\ \\\n"
		<< " (  (     \\ \\  (  (     \\ \\\n"
		<< "  \\  \\     \\ \\  \\  \\     \\ \\\n"
		<< "   \\__\\     \\/   \\__\\     \\/\n"
		<< "    ___                 ___\n"
		<< "   /  /                 \\  \\\n"
		<< "  /  /                   \\  \\\n"
		<< " (  (                     )  )\n"
		<< "  \\  \\   /\\  ______ /\\   /  /\n"
		<< "   \\__\\  \\/ /_____/ \\/  /__/\n"
		<< "            ___ /\\/\\ ___        ___ /\\/\\ ___\n"
		<< "  ____     /  / )/)/ \\  \\      /  / )/)/ \\  \\\n"
		<< "_/ ___\\   /  /        \\  \\    /  /        \\  \\\n"
		<< "\\  \\___  (  (          )  )  (  (          )  )\n"
		<< " \\___  >  \\  \\        /  /    \\  \\        /  /\n"
		<< "     \\/    \\__\\      /__/      \\__\\      /__/\n";
		
	return 0;
}
