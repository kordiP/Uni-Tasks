#pragma once
#include "MyString.h"
#include <ctime>
#include <iostream>

class Message
{
private:
	MyString description;
	MyString senderEmail;
	time_t timeSent;
public:
	Message();
	Message(const MyString& senderMail, MyString desc);
	friend std::ostream& operator<<(std::ostream& os, const Message& mess);
};