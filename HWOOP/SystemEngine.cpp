#include "SystemEngine.h"
#include "User.h"
#include <iostream>

SystemEngine::SystemEngine() : admin(Admin::getInstance())
{
	currentUser = nullptr;
}

SystemEngine& SystemEngine::getInstance() 
{
	static SystemEngine se;
	return se;
}

void SystemEngine::run()
{
	MyString command;
	getline(std::cin, command);
}
