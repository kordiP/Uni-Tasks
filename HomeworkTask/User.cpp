#include "User.h"

void User::sendMessage(User* recipient, const MyString& description)
{
    Message mess(this->email, description);
    recipient->receiveMessage(mess);
}

void User::receiveMessage(const Message& mess)
{
    inbox.pushBack(mess);
}

void User::showInbox() const
{
    inbox.print();
}

void User::deleteMessage(int index)
{
    inbox.removeAt(index);
}

User::User(const MyString& fName, const MyString& lName, const MyString& mail, const MyString& pass, int id)
{
    name = fName;
    surname = lName;
    email = mail;
    setPassword(pass);
    this->id = id;
}

int User::getId() const
{
    return id;
}

const MyString& User::getName() const
{
    return name;
}

const MyString& User::getEmail() const
{
    return email;
}

const User& User::setPassword(const MyString& newPass)
{
    password = newPass;
    return *this;
}

bool User::checkPassword(const MyString& input) const
{
    if (input == password)
    {
        return true;
    }
    return false;
}
