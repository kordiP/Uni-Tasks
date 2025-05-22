#include "Student.h"

const MyVector<int>& Student::getCoursesIds() const
{
	return courses;
}

MyVector<int>& Student::getCoursesIds()
{
	return courses;
}

Student::Student(const MyString& fName, const MyString& lName, const MyString& pass) : User(fName, lName, pass)
{
}

const MyString& Student::getRole() const
{
	return "Student";
}
