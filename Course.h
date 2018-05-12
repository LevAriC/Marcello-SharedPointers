#ifndef COURSE_H
#define COURSE_H
#include "Student.h"
#include "SmartPtr.h"
#include <iostream>
#include <list>

using namespace std;
using namespace idllib;

class Course
{
	string courseName;
	string courseID;
	list<SmartPtr<Student>> listOfStudents;
	int meritPoints;

public:
	Course(string);
	string getCourseID() const;
	list<SmartPtr<Student>>& getListOfStudents();
	string getCourseName() const;
	int getMeritPoints() const;
	void setCourseName(string);
	void setMeritPoints(int);
};

#endif