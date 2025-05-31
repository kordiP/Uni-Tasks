#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Message.h"

class User
{
private:
	static int counter;
	int id;
	MyString name;
	MyString surname;
	MyString password;
	MyVector<Message> inbox;
public:
	User() = default;
	User(const MyString& fName, const MyString& lName, const MyString& pass);
	int getId() const;
	const MyString& getName() const;
	const MyString& getSurname() const;
	const User& setPassword(const MyString& newPass);
	bool checkPassword(const MyString& input) const;

	virtual User& receiveMessage(const Message& mess);
	void showInbox() const;
	User& clearInbox();

	virtual const MyString getRole() const = 0;

	virtual ~User() = default;
};