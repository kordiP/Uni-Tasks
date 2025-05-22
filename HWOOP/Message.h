#pragma once
#include "MyString.h"
#include <ctime>

class Message
{
private:
	int senderId;
	MyString senderName;
	MyString description;
	time_t timeSent;
public:
	Message();
	Message(int senderId, const MyString& desc, const MyString& sendName);
	friend std::ostream& operator<<(std::ostream& os, const Message& mess);
};