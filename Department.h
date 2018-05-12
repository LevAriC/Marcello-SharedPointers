#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <list>
#include <iostream>
#include "Course.h"
#include "SmartPtr.h"

using namespace std;
using namespace idllib;

class Department
{
	string departmentName;
	list<SmartPtr<Course>> listOfCourses;
	list<SmartPtr<Student>> listOfStudents;

public:
	Department(string);
	string getDepartmentName() const;
	list<SmartPtr<Course>>& getListOfCourses();
	list<SmartPtr<Student>>& getListOfStudents();
};

#endif