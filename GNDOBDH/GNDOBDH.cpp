// GNDOBDH.cpp : Defines the entry point for the application.
//

#include "GNDOBDH.h"
#include "SendCOmmand.h"
#include "GetCommand.h"
#include "printTM_and_log.h"
#include "check_command.h"
#include "Telecommand.h"
using namespace std;

int main()
{
	ofstream fout;
	fout.open("TM_log.txt", ios::trunc);
	fout.close();

	while (true) {
		// sends telecom 
		char* TC = Telecommand();
		cout << TC << endl;
		if (TC[0] == '\0') {
			TC = "X";
			SendCom(TC, 1);
		}
		else {
			SendCom(TC, 1);
		}
		//gets acknowlegement and prints it 
		char* receiving = GetCommand(1);
		cout << receiving << endl;
		//checks the command
		string add;
		if (check_command(TC, receiving) == 1) {
			strcpy(receiving, add.c_str());
			add = add + "success";
			auto first = add.begin();
			auto last = add.end();
			// Convert the string to char array
			copy(first, last, receiving);
			printTM_and_log(receiving);	
		}
		else {
			strcpy(receiving, add.c_str());
			add = add + "fail";
			auto first = add.begin();
			auto last = add.end();
			// Convert the string to char array
			copy(first, last, receiving);
			printTM_and_log(receiving);
		}
		//housekeeping
		char* receiving = GetCommand(1);
		printTM_and_log(receiving);
	}
	return 0;
}
