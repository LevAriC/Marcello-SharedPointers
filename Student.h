#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

using namespace std;

//-----------------------------------------------------------------------------------
// Program By Students: (Makmel Michael = 203447834) && (Cohen Lev Ari = 304829807)
//-----------------------------------------------------------------------------------

class Student
{
	string firstName;
	string lastName;
	string address;
	string joinYear;
	string ID;
	int totalMeritPoints;

public:
	Student();
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getJoinYear() const;
	string getID() const;
	int getTotalMeritPoints() const;
	void setFirstName(const string);
	void setLastName(const string);
	void setAddress(const string);
	void setJoinYear(const string);
	void setID(const string);
	void addMeritPoints(int);
	friend ostream& operator<<(ostream&, const Student&);
};

#endif