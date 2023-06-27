#pragma once

#include "degree.h"
#include <string>

using namespace std;

//Student class definition
class Student{

	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int* daysInCourse;
		DegreeProgram degree; //enum defined in degree.h
		const int DAYS_SIZE = 3;

	public:
		//Default "No-Args" Constructor
		Student();

		//Parameterized constructor
		Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degree);

		//Destructor
		~Student();

		//Setters
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string email);
		void setAge(int age);
		void setDaysInCourse(int daysInCourse[]);
		void setDegree(DegreeProgram degree);

		//Getters
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		int getAge() const;
		int *getDaysInCourse() const;
		DegreeProgram getDegree();


		//Print function(s)
		void print();





};

