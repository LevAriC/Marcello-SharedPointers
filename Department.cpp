#include "Department.h"

Department::Department(string name)
{
	departmentName = name;
}

string Department::getDepartmentName() const
{
	return departmentName;
}

list<SmartPtr<Course>>& Department::getListOfCourses()
{
	return listOfCourses;
}

list<SmartPtr<Student>>& Department::getListOfStudents()
{
	return listOfStudents;
}
