#include "Admin.h"

Admin::Admin() : User("admin", "", "0000")
{
}

Admin& Admin::getInstance()
{
	static Admin ad;
	return ad;
}

const MyString& Admin::getRole() const
{
	return "Admin";
}
