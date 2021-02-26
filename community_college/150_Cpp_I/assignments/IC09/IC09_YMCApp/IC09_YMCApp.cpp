/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #09
* LAST MODIFIED:	09/25/18
*
* YMCA App ********************************************************************
*
* PROGRAM DESCRIPTION: 
* This program will calculate and display the total charge for a user's membership registration
* to the local YMCA. The charge is determined through one of the six monthly membership types the 
* organization provides in addition to a joiner fee if the user is a new member:
*
* Teen/Young Adult (Ages 13-25)   $32/mo, $25 joiner fee
* Adult (Ages 24-64)              $47/mo, $50 joiner fee
* Dual Adult (Ages 24-64)         $73/mo, $50 joiner fee
* Family 1 (one adult/children)   $68/mo, $50 joiner fee
* Family 2 (two adults/children)  $88/mo, $50 joiner fee
* Senior (Ages 65 and up)         $43/mo, $50 joiner fee
* 
* ALGORITHM:
* 1. PRINT Membership Menu
* 2. PROMPT "Select from the following 6 membership types ..." as an integer 1-6
* 3. READ membership type
* 4. SWITCH (membership type)
*      CASE 1:
*        monthly charge += $32/mo
*        joiner fee += $25
*      CASE 2:
*        monthly charge += $47/mo
*        joiner fee += $50
*      CASE 3:
*        monthly charge += $73/mo
*        joiner fee += $50
*      CASE 4:
*        monthly charge += $68/mo
*        joiner fee += $50
*      CASE 5:
*        monthly charge += $88/mo
*        joiner fee += $50
*      CASE 6:
*        monthly charge += $43/mo
*        joiner fee += $50
*      DEFAULT:
*        PRINT "Invalid membership type ..."
*        CLOSE program
*    END SWITCH
* 5. PROMPT "How many months would you like to join?"
* 6. READ number of months
* 7. PROMPT "Are you a new member (Y/N)?"
* 8. READ new member
* 9. CALCULATE total charge = monthly charge * number of months
* 10. IF (new member == 'Y')
*       total charge += joiner fee
*     ELSE
*       total charge += $0
* 11. PRINT "The total charges are ... " + total charge
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
* iomanip - enables manipulation of I/O
* cctype - enables functions to classify and manipulate characters
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main(int argc, char** argv) 
{
	/** CONSTANTS **/
	const int COLUMN_WIDTH = 35;
	
	/** DECLARATIONS **/
	int membershipType, months;
	char newMember;
	double monthlyCharge, joinerFee, totalCharge;
	
	/** INTRO **/
	cout << "**********************************************************************\n"
		<< "**                                                                  **\n"	
		<< "**                Joe and Mary Mottino YMCA Oceanside               **\n"
		<< "**                          Membership Menu                         **\n"
		<< "**                                                                  **\n"
		<< "**********************************************************************\n"
		<< "Select from the following 6 membership types: \n\n"
		<< left
		<< setw(COLUMN_WIDTH) << "1. Teen/Young Adult (Ages 13-25) " << "$32/month, $25 joiner fee\n"
		<< setw(COLUMN_WIDTH) << "2. Adult (Ages 24-64) " << "$47/month, $50 joiner fee\n"
		<< setw(COLUMN_WIDTH) << "3. Dual Adult (Ages 24-64) " << "$73/month, $50 joiner fee\n"
		<< setw(COLUMN_WIDTH) << "4. Family 1 (one adult/children) " << "$68/month, $50 joiner fee\n"
		<< setw(COLUMN_WIDTH) << "5. Family 2 (two adults/children) " << "$88/month, $50 joiner fee\n"
		<< setw(COLUMN_WIDTH) << "6. Senior (Ages 65 and up) " << "$43/month, $50 joiner fee\n"
		<< "**********************************************************************\n";
		
	/** INPUT **/
	cin >> membershipType;
	
	switch (membershipType)
	{
		case 1:
			monthlyCharge = 32.0;
			joinerFee = 25.0;
			break;
		case 2:
			monthlyCharge = 47.0;
			joinerFee = 50.0;
			break;
		case 3:
			monthlyCharge = 73.0;
			joinerFee = 50.0;
			break;
		case 4:
			monthlyCharge = 68.0;
			joinerFee = 50.0;
			break;
		case 5:
			monthlyCharge = 88.0;
			joinerFee = 50.0;
			break;
		case 6:
			monthlyCharge = 43.0;
			joinerFee = 50.0;
			break;
		default:
			cout << "Invalid membership type. Please select from the options above.\n";
			system("PAUSE");
			return EXIT_FAILURE;
	}
		
	cout << "How many months would you like to join? ";
	cin >> months;
	
	cout << "Are you a new member (Y/N)? ";
	cin >> newMember;
		
	/** PROCESSING **/
	// ternary operator (?:): if user selects 'Y' for new member, add joiner fee
	totalCharge = (monthlyCharge * months) + ((toupper(newMember) == 'Y') ? joinerFee : 0);
	
	/** OUTPUT **/
	cout << fixed << setprecision(2)
		<< "The total charges are $" << totalCharge << "\n\n";
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
