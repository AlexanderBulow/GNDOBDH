#include "Telecommand.h"
using namespace std;
char charActionArray[64] = { 0 }; // Action char array
char* Telecommand()
{
	string TC;
	// Creating a character array for the action and time to execute action
	charActionArray[64] = { 0 }; // Action char array

	cin >> TC;
	// Copying and converting the telecommand and time string into a C-style string (character array?)
	strcpy(charActionArray, TC.c_str()); // Telecommand string into char array
	return charActionArray;
}