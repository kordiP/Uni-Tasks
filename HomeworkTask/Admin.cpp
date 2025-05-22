#include "Admin.h"

Admin& Admin::getInstance()
{
    Admin admin;
    return admin;
}

void Admin::viewInboxOf(const User& user) const
{
    user.showInbox();
}

Admin::Admin() : User("admin", "", "", "0000", 0)
{
}

const MyString& Admin::getRole() const
{
    return "Admin";
}
