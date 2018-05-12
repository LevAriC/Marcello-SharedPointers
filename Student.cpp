#include "Student.h"

Student::Student()
{
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

string Student::getAddress() const
{
	return address;
}

string Student::getJoinYear() const
{
	return joinYear;
}

string Student::getID() const
{
	return ID;
}

int Student::getTotalMeritPoints() const
{
	return totalMeritPoints;
}

void Student::setFirstName(const string name)
{
	firstName = name;
}

void Student::setLastName(const string lName)
{
	lastName = lName;
}

void Student::setAddress(const string adrs)
{
	address = adrs;
}

void Student::setJoinYear(const string year)
{
	joinYear = year;
}

void Student::setID(const string id)
{
	ID = id;
}

void Student::addMeritPoints(int tmp)
{
	totalMeritPoints += tmp;
}

ostream& operator<<(ostream& out, const Student& student)
{
	out << student.firstName << "," << student.lastName << "," << student.ID << "," << student.address << "," << student.joinYear << "," << student.totalMeritPoints << endl;
	return out;
}
