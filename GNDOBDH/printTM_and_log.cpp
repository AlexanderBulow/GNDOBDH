#include "printTM_and_log.h"

void printTM_and_log(char PFtoGRD[]) {
	// Print to console
	//cout << PFtoGRD << endl;

	// Save to the log file
	ofstream fout;
	fout.open("TM_log.txt", ios::app);  // Open the file
	if (fout.is_open()) {
		fout << PFtoGRD << endl;  // Write the output to the file
		fout.close();
	}
	else {
		cout << "Error opening the log file!" << endl;
	}

}