#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Assignment.h"

class Course
{
private:
	MyString name;
	MyString enrollPass;
	MyVector<Assignment> assignments;
public:
	Course() = default;
	Course(const MyString& name, const MyString& pass);

	const MyString& getName() const;

	const MyVector<MyString>& getAssignmentsNames() const;
	const MyVector<Assignment>& getAssignments() const;
	void addAssignment(const Assignment& assign);
	Assignment& getAssignment(const MyString& assign);
	const Assignment& getAssignment(const MyString& assign) const;

	void addSolutionToAssignment(const MyString& assign, int stId, const MyString& fName, const MyString& lName, const MyString& solution);
	void gradeAssignment(const MyString& assign, int studentId, double grade, const MyString& comment);
	void printAssignmentResponses(const MyString& assign);
	bool isPasswordCorrect(const MyString& attempt) const;
};