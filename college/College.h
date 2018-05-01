#ifndef COLLEGE_H
#define COLLEGE_H
#include "Department.h"
#include <fstream>

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


void read_init()
{
	ifstream inputFile("init.txt");
	char buffer[1024];
	College newCollege;
	string newCollegeName;

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			inputFile.getline(buffer, 1024, ':');
			if (buffer[0] == '#')
			{
				inputFile.getline(buffer, 1024, '\n');
				continue;
			}
			inputFile.getline(buffer, 1024, '\n');
			strcpy(&newCollegeName[0], buffer);
		

		}
	}

	inputFile.close();
	cout << "Reading from file is complete!" << endl << endl;
}
#endif