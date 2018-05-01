#include "Course.h"

Course::Course(string courseName, int awardPoints, int courseID, Student* listOfStudents)
{
	this->courseName = courseName;
	this->awardPoints = awardPoints;
	this->courseID = courseID;
	this->listOfStudents = listOfStudents;
}

string Course::getCourseName() const
{
	return courseName;
}

int Course::getAwardPoints() const
{
	return awardPoints;
}

int Course::getCourseID() const
{
	return courseID;
}

Student* Course::getListOfStudents() const
{
	return listOfStudents;
}
