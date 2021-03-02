#include "roster.h"
#include <iostream>

int main()
{
    const string studentData[] =   //Input student information

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Trevor,Ross,tros114@wgu.edu,29,30,40,50,SOFTWARE"
    };


    cout << "Class Roster Application in C++, C867 - Scripting and Programming Applications" << endl;   //Print out required information
    cout << "Written by Trevor Ross (tros114)" << endl << endl;

    const int classRosterArray = 5;
    Roster classRoster;   //Create instance of Roster class

    for (int i = 0; i < classRosterArray; i++) classRoster.parse(studentData[i]);  //Parse data and add students to classRoster

    cout << "Roster:" << endl;
    classRoster.printAll();            //Print roster

    cout << endl;

    cout << "The following invalid email addresses were found:" << endl;
    classRoster.printInvalidEmails();  //Print invalid email addresses

    cout << endl;

    cout << "Average Days in Course:" << endl;   //Print average days in course for each student
    for (int i = 0; i < classRosterArray; i++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudentAt(i)->getStudentID());
    }

    cout << endl;

    cout << "Software Degree Students: " << endl;    //Print students in Software degree program
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    cout << endl;

    classRoster.remove("A3");  // Remove student having ID A3

    cout << endl;

    classRoster.printAll();  //Print new roster

    cout << endl;

    classRoster.remove("A3");  //Try to find previously removed student A3

    cout << endl;

    system("pause");
    
    return 0;
};
