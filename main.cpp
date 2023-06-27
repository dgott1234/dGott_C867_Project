// Main file for project
// Name: Daniel Gott
// Date: 6-26-2023
// Compiler: Visual Basic Community

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {

	// F1 Print out student info
	cout << "Course: Scripting and Programming - Applications - C867" << endl;
	cout << "Language Used: C++" << endl;
	cout << "Student ID: 000572854" << endl;
	cout <<	"Name: Daniel Gott" << endl;

	// Add studentData[] to main
	const string studentData[] =

	{   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Daniel,Gott,dgott@wgu.edu,34,60,51,19,SOFTWARE"

	};
    cout << endl;

	// F2 Roster Instantiation
    Roster classRoster;

    // All Student Printout
    cout << "All students:" << endl;
    for (int i = 0; i < NUMBER_STUDENTS; ++i) {
        classRoster.parse(studentData[i]);
    }
    classRoster.printAll();

    // Invalid Email Printout
    cout << "Invalid emails:" << endl;
    classRoster.printInvalidEmails();

    //Average Days in Course Printout
    cout << "Average Days in Course:" << endl;
    for (int i = 0; i < NUMBER_STUDENTS; i++) {
        classRoster.printAverageDaysInCourse(classRosterArray.classRosterArray[i]->Student::getStudentID());
    }
    cout << endl;

    //Print students in Software Degree Program
    cout << "Degree program: SOFTWARE";
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);


    //Remove A3 Student
    cout << "Remove:";
    classRoster.remove("A3");

    classRoster.printAll();

    //Check removal of student
    cout << "Remove again" << endl;
    classRoster.remove("A3");

}