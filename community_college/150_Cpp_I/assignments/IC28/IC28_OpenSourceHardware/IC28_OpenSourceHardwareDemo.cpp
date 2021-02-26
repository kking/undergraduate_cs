/******************************************************************************
* AUTHOR:			King
* COURSE:			CS 150: C++ Programming 1
* SECTION:			Tu/Th 11:00a - 12:50p
* IC (PROJECT)#:	28
* LAST MODIFIED:	12/05/18
*
* Open Source Hardware ********************************************************
*
* PROGRAM DESCRIPTION: 
* Using the base class OpenSourceHardware and two derived classes (Arduino and
* RaspberryPi), this program will create two instances of each derived class and
* display its data to the console.
* 
* ALGORITHM:
* 1. Create an array for two Arduino objects, and an array for two RaspberryPi objects
* 2. Instantiate each element in the Arduino list with data for its model, power, price, and microcontroller
* 3. Instantiate each element in the RaspberryPi list with data for its model, power, price, and OS
* 4. Print "List of Arduinos"
* 5. For each element in the Arduino list, print its data to the console
* 6. Print "List of Raspberry Pis"
& 7. For each element in the RaspberryPi list, prints its data to the console
*
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* cstdlib - C standard library
* iostream - input/output stream within the console
******************************************************************************/

#include "Arduino.h"
#include "RaspberryPi.h"

#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 2;

int main(int argv, char* argc[])
{
	Arduino arduinoList[SIZE];
	RaspberryPi piList[SIZE];

	arduinoList[0] = Arduino("UNO Rev 3", 6, 22, "ATmega328P");
	arduinoList[1] = Arduino("MKR Vidor 4000", 3.3, 60, "Arm Cortex-M0");
	
	piList[0] = RaspberryPi("3 Model B+", 5, 34.99, "Raspbian");
	piList[1] = RaspberryPi("3 Model A", 5, 22.99, "Moebius");

	cout << "~~~List of Arduinos~~~\n" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arduinoList[i] << endl;

	cout << "\n~~~List of Raspberry Pis~~~\n" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << piList[i] << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}

