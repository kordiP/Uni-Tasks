#pragma once
#include "MyString.h"
#include "User.h"

class Admin : public User
{
public:
	Admin();
	static Admin& getInstance();
	const MyString& getRole() const override;
};