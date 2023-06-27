#include "student.h"
#include <iostream>


using namespace std;

Student::Student() {}



Student::Student(string studentID, string firstName, string lastName, string email, int age,
    int daysInCourse[], DegreeProgram degree) {
    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setAge(age);
    setDaysInCourse(daysInCourse);
    setDegree(degree);

    daysInCourse = new int[DAYS_SIZE];

    for (int i = 0; i < DAYS_SIZE; i++) {
        daysInCourse[i] = 0;
    }
}



Student::~Student() {

}



// Accessor function definitions
string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmail() const {
    return email;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysInCourse() const {
    return daysInCourse;
}

DegreeProgram Student::getDegree() {
    return this->degree;
}


// Mutator function definitions
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setDaysInCourse(int daysInCourse[]) {
    this->daysInCourse = new int[DAYS_SIZE];
    for (int i = 0; i < DAYS_SIZE; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegree(DegreeProgram degree) {
    this->degree = degree;
}

// Functions
void Student::print() {
    cout << getStudentID() << "  ";
    cout << getFirstName() << "  ";
    cout << getLastName() << "  ";
    cout << getAge() << "  ";
    cout << getEmail() << "   ";
    cout << "{" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << "  ";


    if (this->getDegree() == 0) {
        cout << "SECURITY";
    }
    else if (this->getDegree() == 1) {
        cout << "NETWORK";
    }
    else {
        cout << "SOFTWARE";
    }
    cout << endl;

}