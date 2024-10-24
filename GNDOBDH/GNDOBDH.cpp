// GNDOBDH.cpp : Defines the entry point for the application.
//

#include "GNDOBDH.h"
#include "SendCOmmand.h"
#include "GetCommand.h"
#include "printTM_and_log.h"
using namespace std;

int main()
{
	ofstream fout;
	fout.open("TM_log.txt", ios::trunc);
	fout.close();

	while (true) {

		//char command[64] = "something";
		//SendCom(command, 1);

		char* receiving = GetCommand(1);
		cout << receiving << endl;
		
		printTM_and_log(receiving);
		
	}
	return 0;
}
