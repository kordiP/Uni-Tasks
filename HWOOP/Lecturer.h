#pragma once
#include "User.h"
#include "MyString.h"
#include "MyVector.hpp"

class Lecturer : public User
{
private:
	MyVector<int> courses;
public:
	const MyVector<int>& getCoursesIds() const;
	MyVector<int>& getCoursesIds();
	Lecturer() = default;
	Lecturer(const MyString& fName, const MyString& lName, const MyString& pass);

	const MyString& getRole() const override;
};