#include "User.h"
#include "Course.h"
int User::counter = 0;

User::User(const MyString& fName, const MyString& lName, const MyString& pass)
{
    id = counter++;
    name = fName;
    surname = lName;
    password = pass;
}

int User::getId() const
{
    return id;
}

const MyString& User::getName() const
{
    return name;
}

const MyString& User::getSurname() const
{
    return surname;
}

const User& User::setPassword(const MyString& newPass)
{
    password = newPass;
    return *this;
}

bool User::checkPassword(const MyString& input) const
{
    return input == password;
}

User& User::receiveMessage(const Message& mess)
{
    inbox.pushBack(mess);

    return *this;
}

void User::showInbox() const
{
    if (inbox.getSize() == 0)
    {
        std::cout << "No messages to show." << std::endl;
        return;
    }

    inbox.print();
}

User& User::clearInbox()
{
    inbox.clear();

    return *this;
}
