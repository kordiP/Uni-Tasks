#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Message.h"

class User
{
private:
	int id;
	MyString name;
	MyString surname;
	MyString email;
	MyString password;
	MyVector<Message> inbox;
public:
	User(const MyString& fName, const MyString& lName, const MyString& mail, const MyString& pass, int id);
	int getId() const;
	const MyString& getName() const;
	const MyString& getEmail() const;
	const User& setPassword(const MyString& newPass);
	bool checkPassword(const MyString& input) const;

	virtual void sendMessage(User* recipient, const MyString& description);
	virtual void receiveMessage(const Message& mess);
	void showInbox() const;
	void deleteMessage(int index);

	virtual const MyString& getRole() const = 0;
};