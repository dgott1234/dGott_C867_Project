#pragma once

#include <string>
#include "student.h"
#include "degree.h"

const int NUMBER_STUDENTS = 5;

class Roster {
private:
	//Array initialization to null values
	Student* classRosterArray[NUMBER_STUDENTS] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	int index = -1;

public:
	//Constructor
	Roster();

	//Destructor
	~Roster();

	//Functions
	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string email,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
		DegreeProgram degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);


};
