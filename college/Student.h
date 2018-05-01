#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------
// Program By Students: (Makmel Michael = 203447834) && (Cohen Lev Ari = 304829807)
//-----------------------------------------------------------------------------------

class Student
{
	string firstName;
	string lastName;
	string address;
	int ID;

public:
	Student(string firstName, string lastName, string address, int ID);
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	int getID() const;
};

#endif