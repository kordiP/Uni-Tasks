#include "Course.h"

Course::Course(const MyString& name, const MyString& pass)
{
	this->name = name;
	this->enrollPass = pass;
}

const MyString& Course::getName() const
{
	return name;
}

const MyVector<MyString>& Course::getAssignmentsNames() const
{
	MyVector<MyString> res;

	for (size_t i = 0; i < assignments.getSize(); i++)
	{
		res.pushBack(assignments[i].getTitle());
	}

	return res;
}

const MyVector<Assignment>& Course::getAssignments() const
{
	return assignments;
}

void Course::addAssignment(const Assignment& assign)
{
	assignments.pushBack(assign);
}

Assignment& Course::getAssignment(const MyString& assign)
{
	for (size_t i = 0; i < assignments.getSize(); i++)
	{
		if (assignments[i].getTitle() == assign)		
			return assignments[i];		
	}

	throw std::invalid_argument("Assignment not found.");
}

const Assignment& Course::getAssignment(const MyString& assign) const
{
	for (size_t i = 0; i < assignments.getSize(); i++)
	{
		if (assignments[i].getTitle() == assign)
			return assignments[i];
	}

	throw std::invalid_argument("Assignment not found.");
}

void Course::gradeAssignment(const MyString& assign, int studentId, double grade, const MyString& comment)
{
	Assignment& assignment = getAssignment(assign);
	assignment.gradeAssignment(grade, comment, studentId);
}

void Course::printAssignmentResponses(const MyString& assign)
{
	Assignment& assignment = getAssignment(assign);
	assignment.printSubmissions();
}

bool Course::isPasswordCorrect(const MyString& attempt) const
{
	return enrollPass == attempt;
}