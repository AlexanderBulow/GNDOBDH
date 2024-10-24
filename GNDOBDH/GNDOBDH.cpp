// GNDOBDH.cpp : Defines the entry point for the application.
//

#include "GNDOBDH.h"
#include "SendCOmmand.h"
#include "GetCommand.h"
#include "printTM_and_log.h"
#include "check_command.h"
using namespace std;

int main()
{
	ofstream fout;
	fout.open("TM_log.txt", ios::trunc);
	fout.close();
	char arr[] = "somethingg";

	while (true) {

		//char command[64] = "something";
		//SendCom(command, 1);

		char* receiving = GetCommand(1);
		//cout << receiving << endl;
		// PATH TO FIND LOG FILE: \\wsl.localhost\Ubuntu\home\alihel1\.vs\GNDOBDH\out\build\linux-debug\GNDOBDH
		printTM_and_log(receiving);
		check_command(receiving,arr);
		
		
	}
	return 0;
}
