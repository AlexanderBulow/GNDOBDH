#include "Telecommand.h"
using namespace std;
char charActionArray[64] = { 0 }; // Action char array
char* Telecommand()
{
	string TC;
	// Creating a character array for the action and time to execute action
	charActionArray[64] = { 0 }; // Action char array
	//checking if there is something to read in the command prompt
	struct timeval timeout;
	fd_set read_fds;
	FD_ZERO(&read_fds);
	FD_SET(STDIN_FILENO, &read_fds);

	timeout.tv_sec = 0;
	timeout.tv_usec = 0;

	if (select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout) == 1) {
		cin >> TC;
	}

	// Copying and converting the telecommand and time string into a C-style string (character array?)
	strcpy(charActionArray, TC.c_str()); // Telecommand string into char array
	return charActionArray;
}