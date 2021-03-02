#include "roster.h"
#include "degree.h"
#include "student.h"

void Roster::parse(string row) {

	DegreeProgram degreeProgram;

	size_t sec = row.find("SECURITY");
	size_t net = row.find("NETWORK");
	size_t soft = row.find("SOFTWARE");
	
	if (sec != std::string::npos)  //Assign degree program based on results of find
		degreeProgram = SECURITY;
	else if (net != std::string::npos)
		degreeProgram = NETWORK;
	else if (soft != std::string::npos)
		degreeProgram = SOFTWARE;
	else
		degreeProgram = EMPTY;

	//Parse the rest of the data

	int R = row.find(",");
	string studentID = row.substr(0, R);

	int L = R + 1;
	R = row.find(",", L);
	string firstName = row.substr(L, R - L);

	L = R + 1;
	R = row.find(",", L);
	string lastName = row.substr(L, R - L);

	L = R + 1;
	R = row.find(",", L);
	string email = row.substr(L, R - L);

	L = R + 1;
	R = row.find(",", L);
	string tempAge = row.substr(L, R - L);
	int age = stoi(tempAge);

	L = R + 1;
	R = row.find(",", L);
	int daysInCourse1 = stoi(row.substr(L, R - L));

	L = R + 1;
	R = row.find(",", L);
	int daysInCourse2 = stoi(row.substr(L, R - L));

	L = R + 1;
	R = row.find(",", L);
	int daysInCourse3 = stoi(row.substr(L, R - L));

	L = R + 1;
	R = row.find(",", L);

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);  //Add data

}

void Roster::add(string studentID, string firstName, string lastName, string email, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int darr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	students[++prevIndex] = new Student(studentID, firstName, lastName, email, studentAge, darr, degreeprogram);
}


void Roster::printAll()
{
	for (int i = 0; i <= Roster::prevIndex; i++) Roster::students[i]->print();
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	for (int i = 0; i <= Roster::prevIndex; i++) {
		if (Roster::students[i]->getDegreeProgram() == degreeprogram) students[i]->print();
		}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		string sEmail = students[i]->getEmail();
		if ((sEmail.find("@") == string::npos || sEmail.find(".") == string::npos) || (sEmail.find(" ") != string::npos)) {
			cout << sEmail << endl;
		}
	}
}

bool Roster::remove(string studentID) {

	bool found = false;
	for (int i = 0; i < prevIndex; ++i) {
		if (students[i]->getStudentID() == studentID) {
			found = true;
			delete this->students[i];
			cout << "Student with ID " << studentID << " has been successfully removed." << endl;
			students[i] = students[prevIndex];
			prevIndex--;
		}
	}
	if (!found) {
		cout << "Student with ID " << studentID << " was not found!" << endl;
	}
	return found;
}


Student* Roster::getStudentAt(int index) {
	return students[index];
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::prevIndex; i++)
	{
		if (students[i]->getStudentID() == studentID)
		{
			cout << "Average Days for Student " << studentID << ":";
			cout << (static_cast<long long>(students[i]->getDays()[0]) + static_cast<long long>(students[i]->getDays()[1]) + static_cast<long long>(students[i]->getDays()[2])) / 3 << endl;
		}
	}
};

Roster::~Roster() {

}

