#include "PC.h"

const char* PC::type = "PC";
const char* PC::perifer = "Mouse, Keyboard, Microphone";

const char* PC::getType() const
{
	return type;
}

const char* PC::getPerifer() const
{
	return perifer;
}