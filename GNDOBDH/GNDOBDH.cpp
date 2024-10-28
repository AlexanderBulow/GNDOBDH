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
			cout << "test";
			SendCom(TC, 1);
		}
		else {
			SendCom(TC, 1);
		}
		//gets acknowlegement and prints it 
		char* receiving = GetCommand(2);
		cout << receiving << endl;

		//random data
		char* receiving2 = GetCommand(3);
		printTM_and_log(receiving2);
		//housekeeping
		char* receiving3 = GetCommand(4);
		printTM_and_log(receiving3);
		sleep(1);
	}
	return 0;
}
