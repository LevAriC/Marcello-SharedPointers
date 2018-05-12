#ifndef COLLEGE_H
#define COLLEGE_H
#include "Department.h"
#include "SmartPtr.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;
using namespace idllib;

class College
{
	string collegeName;
	list<SmartPtr<Department>> listOfDepartments;
	list<SmartPtr<Course>> listOfCourses;
	
public:
	College();
//	friend ostream& operator<<(ostream&, College&);
	friend College& initCollegeFromFile(int, const char* argv[]);
	void friend readSimulation(const char *argv[], College&);

};

College& initCollegeFromFile(int, const char* argv[]);
void readSimulation(const char *argv[], College&);


#endif