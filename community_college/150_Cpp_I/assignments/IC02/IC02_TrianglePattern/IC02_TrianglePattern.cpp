/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #02
* LAST MODIFIED:	08/28/18
*
* Triangle Pattern ************************************************************
*
* PROGRAM DESCRIPTION:
* Using only one cout statement, this program will write a small triangle pattern to the console.
* 
* ALGORITHM:
* 1. PRINT a small triangle graphic to the console in one cout statement
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
	cout << "   *\n"
		<< "  ***\n"
		<< " *****\n"
		<< "*******";
		
	return 0;
}
