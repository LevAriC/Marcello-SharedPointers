#include "Student.h"

Student::Student(string firstName, string lastName, string address, int ID)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
	this->ID = ID;
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

int Student::getID() const
{
	return ID;
}
