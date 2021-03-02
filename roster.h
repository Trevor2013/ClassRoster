#pragma once
#include "student.h"

class Roster
{
public:
	int prevIndex = -1;
	const static int classRosterArray = 5;
	Student* students[classRosterArray];
	
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	Student* getStudentAt(int index);
	bool remove(string studentID);
	~Roster();
};
