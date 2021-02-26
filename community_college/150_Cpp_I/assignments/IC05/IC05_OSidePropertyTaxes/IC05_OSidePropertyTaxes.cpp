/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	IC #05
* LAST MODIFIED:	09/11/18
*
* Oceanside Property Taxes ****************************************************
*
* PROGRAM DESCRIPTION: 
* With an assessed value of a home received from the console, this program will calculate and display 
* each component of the Oceanside property tax based on their corresponding rates:
*
* AGENCY				 RATE
* ------------------------------
* 1% Tax On Net Value:	 1.00000
* Voter Approved Bond:
* San Diego County:		 0.00680
* Unified School:		 0.09575
* Community College:	 0.01786
* Metro Water District:	 0.00610
* Metro Water Authority: 0.00075
* Total On Net Value:	 1.12726
* 
* ALGORITHM:
* 1. PROMPT entry for assessed home value
* 2. CALCULATE each of the above components, based on the form (assessed home value * (rate / 100))
* 3. CALCULATE the amount of each installment, (total on net value / 2) for two installments per year
* 4. PRINT formatted list of each component and first installment due
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
	/** CONSTANTS **/
	const int WIDTH_1 = 32, WIDTH_2 = 7; // Column widths for agencies and taxes respectively
	
	/** DECLARATIONS **/
	double assessedValue, onePercent, county, school, communityCollege, 
		metroWaterDist, countyWaterAuth, totalDue, firstInstallment;
	
	/** INPUT **/
	// Step 1: Read assessed value of home
	cout << "Enter assessed value of property: $";
	cin >> assessedValue;
	
	/** PROCESSING **/
	// Step 2: Calculate property taxes based on given agencies and corresponding rates
	onePercent = assessedValue * 0.01;
	county = assessedValue * (0.00680 / 100);
	school = assessedValue * (0.09575 / 100);
	communityCollege = assessedValue * (0.01786 / 100);
	metroWaterDist = assessedValue * (0.00610 / 100);
	countyWaterAuth = assessedValue * (0.00075 / 100);
	totalDue = assessedValue * (1.12726 / 100);
	
	// Step 3: Calculate first installment due, two installments per year
	firstInstallment = totalDue / 2;
	
	/** OUTPUT **/
	// Step 4: Print formatted list of each component and first installment due
	cout << left << fixed << setprecision(2)
		<< "\nYour 2017-2018 estimated property taxes are:\n\n"
		<< setw(WIDTH_1) << "1% TAX ON NET VALUE " << "$ " << setw(WIDTH_2) << right << onePercent << endl << left
		<< "VOTER APPROVED BONDS: \n" 
		<< setw(WIDTH_1) << "SAN DIEGO COUNTY " << "$ " << setw(WIDTH_2) << right << county << "\n" << left
		<< setw(WIDTH_1) << "UNIFIED SCHOOL " << "$ " << setw(WIDTH_2) << right << school << "\n" << left
		<< setw(WIDTH_1) << "COMMUNITY COLLEGE" << "$ " << setw(WIDTH_2) << right << communityCollege << "\n" << left
		<< setw(WIDTH_1) << "METRO WATER DISTRICT " << "$ " << setw(WIDTH_2) << right << metroWaterDist << "\n" << left
		<< setw(WIDTH_1) << "COUNTY WTR AUTHORITY " << "$ " << setw(WIDTH_2) << right << countyWaterAuth << "\n\n" << left
		<< setw(WIDTH_1) << "TOTAL PROPETY TAXES DUE: " << "$ " << setw(WIDTH_2) << right << totalDue << "\n" << left
		<< setw(WIDTH_1) << "FIRST INSTALLMENT DUE 11/01/18: " << "$ " << setw(WIDTH_2) << right << firstInstallment << endl << left;
	
	return 0;
}
