#pragma once
#include "User.h"

class Student : public User
{
private:
	MyVector<int> courses;
public:
	const MyVector<int>& getCoursesIds() const;
	MyVector<int>& getCoursesIds();
	Student() = default;
	Student(const MyString& fName, const MyString& lName, const MyString& pass);

	const MyString& getRole() const override;
};