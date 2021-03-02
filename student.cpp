#include "student.h"
#include <iostream>
#include <string>

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->studentAge = 0;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
	this->degreeprogram = DegreeProgram::EMPTY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int studentAge, int days[], DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->studentAge = studentAge;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
	this->degreeprogram = degreeprogram;
}

Student::~Student() {}
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getStudentAge() { return this->studentAge; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeprogram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) {this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setStudentAge(int studentAge) { this->studentAge = studentAge; }
void Student::setDays(int days[])
{
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeprogram = degreeprogram; }

void Student::print() {
	string lastNameSpace;
	if (size(getLastName()) >= 8) lastNameSpace = ""; else lastNameSpace = "\t";  //These lines allos tabs to be added as required to even things up
	string emailSpace;
	if (size(getEmail()) <= 15) emailSpace = "\t"; else emailSpace = "";
	std::cout << getStudentID() << "\t" << getFirstName() << "\t" << getLastName() << lastNameSpace << "\t" << getEmail() << emailSpace << /*emailSpace << emailSpace <<*/ "\t" << "\t" << "\t" << getStudentAge() << "\t";
	int* days = getDays();
	cout << days[0] << "\t" << days[1] << "\t" << days[2] << "\t";
	cout << degreeProgramStrings[(int)getDegreeProgram()] << endl;
}


