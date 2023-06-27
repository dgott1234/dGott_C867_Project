// Roster.cpp File

#include <iostream>
#include <sstream>
#include <iomanip>
#include "roster.h"

#ifndef _ROSTER_CPP_
#define _ROSTER_CPP_

using namespace std;

//Destructor
Roster::~Roster() {



}

// E2&3 -- Function definitions 
void Roster::add(string studentID, string firstName, string lastName, string email,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degree) {

    int daysInCourse[] = { daysInCourse1,daysInCourse2,daysInCourse3 };
    classRosterArray[++index] = new Student(studentID, firstName, lastName, email, age,
        daysInCourse, degree);



}
// E3c -- Print tab-seperated list of student data
void Roster::printAll() {
    for (int i = 0; i < NUMBER_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->Student::print();
        }
    }
    cout << endl;
}

// E2a&b -- Parse for all columns on table
void Roster::parse(string studentData) {
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = studentData.stoi(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = studentData.stoi(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = studentData.stoi(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = studentData.stoi(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degreeType = studentData.substr(lhs, rhs - lhs);

    DegreeProgram degree;

    if (degreeType == "SECURITY") {
        degree = DegreeProgram::SECURITY;
    }
    if (degreeType == "NETWORK") {
        degree = DegreeProgram::NETWORK;
    }
    if (degreeType == "SOFTWARE") {
        degree = DegreeProgram::SOFTWARE;
    }

    Roster::add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);

}
//E3e -- Check for Invalid emails (valid emails should have an '@' and a '.' and should not have a ' '
void Roster::printInvalidEmails() {
    for (int i = 0; i < NUMBER_STUDENTS; i++) {
        string email = classRosterArray[i]->getEmail();
        if ((email.find(' ') != string::npos) || (email.find('.') == string::npos) || ((email.find('@')) == string::npos)) {
            cout << email << " is invalid." << endl;
            }
            cout << endl;
    }
}

void printAverageDaysInCourse(string studentID) {
    float averageDaysInCourse = 0;
    int max = 3;

    for (int i = 0; i < NUMBER_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* daysInCourse = classRosterArray[i]->getDaysInCourse();
            for (int j = 0; j < max; j++) {
                averageDaysInCourse += daysInCourse[j];
            }
        cout << "Student ID" << classRosterArray[i]->getStudentID() << "has an average of " << (averageDaysInCourse / max) << "days to complete the courses." << endl;
        }
    }
}

void printByDegreeProgram(DegreeProgram degree) {
    for (int i = 0; i < NUMBER_STUDENTS; i++) {
        if (classRosterArray[i]->Student::getDegree() == degree) {
            classRosterArray[i]->print();
        }
    }
}

void remove(string studentID) {
    bool removeTest = false;
    for (int i = 0; i < NUMBER_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr && (*classRosterArray[i]).getStudentID() == 2) {
            classRosterArray = nullptr;
            removeTest = true;
            break;
        }
        if (removeTest == false) {
            cout << "ERROR IDENTIFIED: The student was not found." << endl;
        }
    }
}
#endif
  