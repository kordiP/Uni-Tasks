#pragma once
#include "User.h"

class Student : public User
{
private:
	MyVector<MyString> courses;
public:
	void addToCourse(const MyString& courseName);
	const MyVector<MyString> getCourses() const;

	Student() = default;
	Student(const MyString& fName, const MyString& lName, const MyString& pass);

	bool operator==(const Student&) const;

	const MyString getRole() const override;
};