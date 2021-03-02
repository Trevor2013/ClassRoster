#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

; using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student
{
public:
	const static int daysArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int studentAge;
	int days[daysArraySize];
	DegreeProgram degreeprogram;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string email, int studentAge, int days[], DegreeProgram degreeprogram);
	~Student();


	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getStudentAge();
	int* getDays();
	DegreeProgram getDegreeProgram();


	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setStudentAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeprogram);

	static void printHeader();

	void print();

};
