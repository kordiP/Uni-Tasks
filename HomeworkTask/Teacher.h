#pragma once
#include "User.h"
#include "MyVector.hpp"
#include "MyString.h"

class Course;
class Student;

class Teacher : public User
{
public:
	Teacher();
	Teacher(const MyString& fName, const MyString& lName, const MyString& mail, const MyString& pass, int id);

	const MyString& getRole() const override;
	void sendMessage(User* recipient, const MyString& description) override;
};