#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include <iostream>

class Assignment
{
private:
	struct SolutionPair
	{
	private:
		int studentId = -1;
		MyString studentFirstName;
		MyString studentLastName;
		MyString solution;
		MyString lecturerResponse;
		double grade = 0;
		bool graded = false;
	public:
		SolutionPair() = default;
		SolutionPair(int studentId, const MyString& fName, const MyString& lName, const MyString& solution);

		int getStudentId() const;
		bool isGraded() const;
		double getGrade() const;
		const MyString& getLecturerResponse() const;

		void printSolution() const;
		void addResponse(const MyString& response, double grade);
	};
	MyString title;
	MyVector<SolutionPair> solutions;
	
public: 
	Assignment() = default;
	Assignment(const MyString& title);

	const MyString& getTitle() const;
	SolutionPair& getSolution(int studentId);
	const SolutionPair& getSolution(int studentId) const;

	void submitSolution(int stId, const MyString& fName, const MyString& lName, const MyString& solution);
	void gradeAssignment(double grade, const MyString& response, int studentId);
	const MyString& getStudentGrade(int studentId) const;
	void printSubmissions() const;
};