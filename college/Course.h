#ifndef COURSE_H
#define COURSE_H
#include "Student.h"

class Course
{
	string courseName;
	int awardPoints;
	int courseID;
	Student* listOfStudents;

public:
	Course(string courseName, int awardPoints, int courseID, Student* listOfStudents);
	string getCourseName() const;
	int getAwardPoints() const;
	int getCourseID() const;
	Student* getListOfStudents() const;
};

#endif