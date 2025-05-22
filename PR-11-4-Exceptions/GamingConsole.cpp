#include "GamingConsole.h"

const char* GamingConsole::type = "Gaming Console";
const char* GamingConsole::perifer = "Joystick, Monitor";

const char* GamingConsole::getType() const
{
	return type;
}

const char* GamingConsole::getPerifer() const
{
	return perifer;
}