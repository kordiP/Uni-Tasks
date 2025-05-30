#pragma once
#include "User.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Course.h"

class Lecturer : public User
{
private:
	MyVector<MyString> courses;
public:
	void addCourse(const MyString& courseName);
	const MyVector<MyString> getCourses() const;

	Lecturer() = default;
	Lecturer(const MyString& fName, const MyString& lName, const MyString& pass);

	const MyString& getRole() const override;
};