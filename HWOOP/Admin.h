#pragma once
#include "MyString.h"
#include "User.h"

class Admin : public User
{
private:
	static Admin* instance;
	Admin();
public:
	Admin(const Admin&) = delete;
	Admin& operator=(const Admin&) = delete;

	static Admin* getInstance();
	const MyString& getRole() const override;

	~Admin();
};