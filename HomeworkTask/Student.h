#pragma once
#include "MyString.h"
#include "Course.h"
#include "Assignment.h"
#include "User.h"

class Course;

class Student : public User
{
private:
	Course** courses;
public:
	Student();
	Student(const MyString& fName, const MyString& lName, const MyString& mail, const MyString& pass, int id);
	void enrollInCourse(const MyString& pass, const Course& course);
	void sendSolution(const Assignment& assign, MyString& solution);
	void viewGrades() const;

	const MyString& getRole() const override;
};