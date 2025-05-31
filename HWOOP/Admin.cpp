#include "Admin.h"
Admin* Admin::instance = nullptr;

Admin::Admin() : User("admin", "", "0000")
{
}

Admin* Admin::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Admin();
	}
	return instance;
}

const MyString Admin::getRole() const
{
	return "Admin";
}

Admin::~Admin()
{
	delete instance;
	instance = nullptr;
}
