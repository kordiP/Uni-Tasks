#include "Message.h"

Message::Message()
{
    senderId = -1;
    description = "";
    timeSent = NULL;
}

Message::Message(int senderId, const MyString& desc, const MyString& sendName)
{
    this->senderId = senderId;
    this->senderName = sendName;
    description = desc;
    timeSent = time(0);
}

std::ostream& operator<<(std::ostream& os, const Message& mess)
{
    os << mess.timeSent << ", sent by " << mess.senderName << ": " << mess.description << std::endl;
    return os;
}
