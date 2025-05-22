#include "SystemEngine.h"

SystemEngine& SystemEngine::getInstance()
{
    SystemEngine se;
    return se;
}

SystemEngine::SystemEngine()
{
}

void SystemEngine::deleteUser(int id)
{
}

void SystemEngine::createStudent()
{
}

void SystemEngine::createTeacher()
{
}

void SystemEngine::sendGlobalMessage()
{
}

void SystemEngine::createCourse()
{
}

void SystemEngine::createAssignment()
{
}

void SystemEngine::run()
{
	try
	{
		// load from files
		MyString command;
		std::cin >> command;
		while (true)
		{
			if (command == "")
			{

			}
			else if (command == "a")
			{

			}
		}
	}
	catch (const std::exception&)
	{

	}
}
