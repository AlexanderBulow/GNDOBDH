// GNDOBDH.cpp : Defines the entry point for the application.
//

#include "GNDOBDH.h"
#include "SendCOmmand.h"
#include "GetCommand.h"
using namespace std;

int main()
{
	while (true) {
		char command[64] = "something";
		SendCom(command, "GNDtoPF");

		char receiving[32];
		GetCommand(receiving, "GNDtoPF");
	}
	return 0;
}
