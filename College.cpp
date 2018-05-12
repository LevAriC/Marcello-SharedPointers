#include "College.h"


College::College()
{
	collegeName = "\0";
}

//ostream& operator<<(ostream& out, College& college)
//{
//	// TODO: insert return statement here
//}

College& initCollegeFromFile(int argc, const char* argv[])
{
	char buffer[1024];
	char *token;
	College newCollege;

	ifstream initFile;
	initFile.open(argv[1]);
	if (!initFile.is_open()) throw NULL;

	while (!initFile.eof()) {
		initFile.getline(buffer, 1024);
		if (*buffer == '#') continue;
		
		token = strtok(buffer, ":");
		
		if (!strcmp(token, "College")) {
			token = strtok(NULL, "\n");
			token[strlen(token) + 1] = '\0';
			newCollege.collegeName = token;
		}

		if (!strcmp(token, "Departments")) {
			token = strtok(NULL, ",");
			token[strlen(token) + 1] = '\0';
			while (token){
				newCollege.listOfDepartments.push_front(SmartPtr<Department>(new Department(token)));
				token = strtok(NULL, ",");
				if (!token) token[strlen(token) + 1] = '\0';
			}
		}

		if (!strcmp(token, "UniversityCoursesList")) {
			token = strtok(NULL, ",");
			token[strlen(token) + 1] = '\0';
			while (!token){
				newCollege.listOfCourses.push_front(SmartPtr<Course>(new Course(token)));
				token = strtok(NULL, ",");
				if (!token) token[strlen(token) + 1] = '\0';
			}
		}

		if (!strcmp(token, "CourseDetails")) {
			token = strtok(NULL, ",");
			token[strlen(token) + 1] = '\0';
			while (!token) {
				for (list<SmartPtr<Department>>::iterator i = newCollege.listOfDepartments.begin(); i != newCollege.listOfDepartments.end(); i++)
				{
					if ((i->GetPtr())->getDepartmentName() == token)
					{
						token = strtok(NULL, ",");
						token[strlen(token) + 1] = '\0';
						for (list<SmartPtr<Course>>::iterator j = newCollege.listOfCourses.begin(); j != newCollege.listOfCourses.end(); j++)
						{
							if ((j->GetPtr())->getCourseID() == token)
							{
								(i->GetPtr())->getListOfCourses().push_front(SmartPtr<Course>(*j));
								token = strtok(NULL, ",");
								token[strlen(token) + 1] = '\0';
								(j->GetPtr())->setMeritPoints(stoi(token));
								token = strtok(NULL, ",");
								token[strlen(token) + 1] = '\0';
								(j->GetPtr())->setCourseName(token);
							}
						}
					}
				}

				token = strtok(NULL, ",");
				if(!token) token[strlen(token) + 1] = '\0';
			}
		}
	}

	initFile.close();
}

void readSimulation(const char *argv[], College& college)
{
	Student newStudent;
	list<SmartPtr<Department>>::iterator i;/********/
	list<SmartPtr<Student>>::iterator j;
	list<SmartPtr<Course>>::iterator k;
	char buffer[1024];
	bool isSigned = false;
	char* token;
	ifstream simulationFile;
	simulationFile.open(argv[2]);
	if (!simulationFile.is_open()) throw NULL;

	while (!simulationFile.eof()){
		simulationFile.getline(buffer, 1024);
		if (*buffer == '#') continue;

		switch (*buffer)
		{
		case 1:
			token = strtok(buffer, ",");
			token = strtok(NULL, ",");
			newStudent.setFirstName(token);
			token = strtok(NULL, ",");
			newStudent.setLastName(token);
			token = strtok(NULL, ",");
			newStudent.setID(token);
			token = strtok(NULL, ",");
			newStudent.setAddress(token);
			token = strtok(NULL, ",");
			newStudent.setJoinYear(token);
			token = strtok(NULL, ",");
			token[strlen(token) + 1] = '\0';

			for (i = college.listOfDepartments.begin(); i != college.listOfDepartments.end(); i++)
			{
				if ((i->GetPtr())->getDepartmentName() == token)
					i->GetPtr()->getListOfStudents().push_front(SmartPtr<Student>(new Student(newStudent)));
			}
		break;

		case 2:
			token = strtok(buffer, ",");
			token = strtok(NULL, ",");
			for (i = college.listOfDepartments.begin(); i != college.listOfDepartments.end(); i++)
			{
				for (j = (i->GetPtr())->getListOfStudents().begin(); j != (i->GetPtr())->getListOfStudents().end(); j++)
				{
					if ((j->GetPtr())->getID() == token){
						isSigned = true;
						break;
					}
				}
			}
			if (!isSigned)
			{
				cout << "Student Not Found" << endl;
				return;
			}
			token = strtok(NULL, ",");
			token[strlen(token) + 1] = '\0';
			for (k = ((i->GetPtr())->getListOfCourses()).begin(); k != ((i->GetPtr())->getListOfCourses()).end(); k++)
			{
				if ((k->GetPtr())->getCourseID() == token)
					k->GetPtr()->getListOfStudents().push_front(*j);
			}
		break;

		case 3:
			char *tokenID;
			tokenID = strtok(buffer, ",");
			tokenID = strtok(NULL, ",");
			token = strtok(NULL, ",");
			token[strcspn(token, "\r\n")] = 0;
			for (list<SmartPtr<Course>>::iterator k = college.listOfCourses.begin(); k != college.listOfCourses.end(); k++)
			{
				if ((k->GetPtr())->getCourseID() == token)
				{
					for (list<SmartPtr<Student>>::iterator i = ((k->GetPtr())->getListOfStudents()).begin(); i != ((k->GetPtr())->getListOfStudents()).end(); i++)
					{
						if ((i->GetPtr())->getID() == tokenID)
						{
							i->GetPtr()->addMeritPoints(k->GetPtr()->getMeritPoints());
							k->GetPtr()->getListOfStudents().remove(*i);
							
							if (i->GetPtr()->getTotalMeritPoints() >= 40)
							{
								for (list<SmartPtr<Department>>::iterator k = college.listOfDepartments.begin(); k != college.listOfDepartments.end(); k++)
								{
									for (list<SmartPtr<Student>>::iterator i = ((k->GetPtr())->getListOfStudents()).begin(); i != ((k->GetPtr())->getListOfStudents()).end(); ++i)
									{
										if (i->GetPtr()->getID() == tokenID)
										{
											k->GetPtr()->getListOfStudents().remove(*i);
											break;
										}
									}
								}
							}
							break;
						}
					}
				}
			}
			break;

		case 4:
			token = strtok(buffer, ",");
			token = strtok(NULL, ",");
			for (list<SmartPtr<Course>>::iterator z = college.listOfCourses.begin(); z != college.listOfCourses.end(); ++z)
			{
				for (list<SmartPtr<Student>>::iterator i = z->GetPtr()->getListOfStudents().begin(); i != z->GetPtr()->getListOfStudents().end(); ++i)
				{
					if (i->GetPtr()->getID() == token)
					{
						z->GetPtr()->getListOfStudents().remove(*i);
						break;
					}
				}

			}
			for (list<SmartPtr<Department>>::iterator z = college.listOfDepartments.begin(); z != college.listOfDepartments.end(); ++z)
			{
				for (list<SmartPtr<Student>>::iterator i = z->GetPtr()->getListOfStudents().begin(); i != z->GetPtr()->getListOfStudents().end(); ++i)
				{
					if (i->GetPtr()->getID() == token)
					{
						z->GetPtr()->getListOfStudents().remove(*i);
						break;
					}
				}
			}
			break;

		case 5:
			ofstream outFile;
			outFile.open(argv[3]);
			if (!outFile.is_open())	throw NULL;                    


			list<SmartPtr<Department>>::iterator k;
			token = strtok(buffer, ",");
			token = strtok(NULL, ",");
			for (k = college.listOfDepartments.begin(); k != college.listOfDepartments.end(); k++)
			{
				if (k->GetPtr()->getDepartmentName() == token)
				{
					outFile << "Department: " << k->GetPtr()->getDepartmentName() << endl;
					break;
				}
			}

			token = strtok(NULL, ",");
			token[strcspn(token, "\r\n")] = 0;
			outFile << "student year: " << token << endl;
			outFile << "student in this department" << endl;
			for (list<SmartPtr<Student>>::iterator i = k->GetPtr()->getListOfStudents().begin(); i != k->GetPtr()->getListOfStudents().end(); ++i)
			{
				if (i->GetPtr()->getJoinYear() == token)
				{
					outFile << *(i->GetPtr()) << endl;
				}
			}

			for (list<SmartPtr<Course>>::iterator i = k->GetPtr()->getListOfCourses().begin(); i != k->GetPtr()->getListOfCourses().end(); ++i)
			{
				outFile << i->GetPtr()->getCourseID() << "," << i->GetPtr()->getMeritPoints() << "," << i->GetPtr()->getCourseName() << endl;
				outFile << "student in this course: " << endl;
				for (list<SmartPtr<Student>>::iterator j = i->GetPtr()->getListOfStudents().begin(); j != i->GetPtr()->getListOfStudents().end(); ++j)
				{
					if (j->GetPtr()->getJoinYear() == token)
					{
						outFile << *(j->GetPtr());
					}
				}

			}
			outFile.close();
		break;
		}
	}
		simulationFile.close();
}
