#include "Student.h"

void Student::addToCourse(const MyString& courseName)
{
	courses.pushBack(courseName);
}

const MyVector<MyString> Student::getCourses() const
{
	return courses;
}

Student::Student(const MyString& fName, const MyString& lName, const MyString& pass) : User(fName, lName, pass)
{
}

bool Student::operator==(const Student& other) const
{
	return this->getId() == other.getId();
}

const MyString Student::getRole() const
{
	return "Student";
}
