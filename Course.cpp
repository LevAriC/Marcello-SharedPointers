#include "Course.h"

Course::Course(string name)
{
	courseName = name;
}

string Course::getCourseName() const
{
	return courseName;
}

int Course::getMeritPoints() const
{
	return meritPoints;
}

void Course::setCourseName(string name)
{
	courseName = name;
}

string Course::getCourseID() const
{
	return courseID;
}

list<SmartPtr<Student>>& Course::getListOfStudents()
{
	return listOfStudents;
}

void Course::setMeritPoints(int points)
{
	meritPoints = points;
}


