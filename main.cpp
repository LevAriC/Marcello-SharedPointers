//-----------------------------------------------------------------------------------
// Program By Students: (Makmel Michael = 203447834) && (Cohen Lev Ari = 304829807)
//-----------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "College.h"

int main(int argc, const char * argv[]) {
	cout << argv[1] << " " << argv[2] << " " << argv[3] << "\n\n";
	if (argc != 4)
		return -1;

	try {
		College newCollege = initCollegeFromFile(argc, argv);
		readSimulation(argv, newCollege);
	}
	catch (exception &ex) {
		cout << ex.what() << "!\n";
	}
}