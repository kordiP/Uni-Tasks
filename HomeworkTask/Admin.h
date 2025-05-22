#pragma once
#include "Message.h"
#include "User.h"
#include "MyString.h"
#include "Student.h"
#include "Teacher.h"
#include "SystemEngine.h"

class Admin : public User
{
private:
	Admin();
public:
	static Admin& getInstance();
	void viewInboxOf(const User& user) const;

	const MyString& getRole() const override;
};