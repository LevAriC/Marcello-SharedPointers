#include "Department.h"

Department::Department(string departmentName, Course* listOfCourses, Student* listOfStudents)
{
	this->departmentName = departmentName;
	this->listOfCourses = listOfCourses;
	this->listOfStudents = listOfStudents;
}

string Department::getDepartmentName() const
{
	return departmentName;
}

Course* Department::getListOfCourses() const
{
	return listOfCourses;
}

Student* Department::getListOfStudents() const
{
	return listOfStudents;
}
