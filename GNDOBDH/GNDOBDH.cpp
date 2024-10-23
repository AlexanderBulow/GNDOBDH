// GNDOBDH.cpp : Defines the entry point for the application.
//

#include "GNDOBDH.h"
#include "SendCOmmand.h"
#include "GetCommand.h"
using namespace std;

int main()
{
	while (true) {

		//char command[64] = "something";
		//SendCom(command, 1);

		char* receiving = GetCommand(1);
		cout << receiving << endl;
		
	}
	return 0;
}
