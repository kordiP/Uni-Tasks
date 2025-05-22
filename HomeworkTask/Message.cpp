#include "Message.h"

Message::Message()
{
	senderEmail = "";
	description = "";
	timeSent = NULL;
}

Message::Message(const MyString& senderMail, MyString desc)
{
	this->senderEmail = senderMail;
	this->description = desc;
	this->timeSent = time(0);
}

std::ostream& operator<<(std::ostream& os, const Message& mess)
{
	os << "Sent by: " << mess.senderEmail << " at " << mess.timeSent << "." << std::endl << mess.description << std::endl;
	return os;
}
