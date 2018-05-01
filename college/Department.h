#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Course.h"

class Department
{
	string departmentName;
	Course* listOfCourses;
	Student* listOfStudents;

public:
	Department(string departmentName, Course* listOfCourses, Student* listOfStudents);
	string getDepartmentName() const;
	Course* getListOfCourses() const;
	Student* getListOfStudents() const;
};

#endif