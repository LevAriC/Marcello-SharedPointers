#ifndef COLLEGE_H
#define COLLEGE_H
#include "Department.h"

class College
{
	string collegeName;
	Department* listOfDepartments;
	Course* listOfCourses;

public:
	College(string collegeName, Department* listOfDepartments, Course* listOfCourses);
	string getDepartmentName() const;
	Course* getListOfCourses() const;
	Student* getListOfStudents() const;
};

#endif