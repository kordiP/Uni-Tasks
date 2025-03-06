#include "Person.h"
#include <cstring>
#include <iostream>
#include <fstream>

const char* Person::getName() const
{
	return name;
}

const char* Person::getEGN() const
{
	return EGN;
}

const char* Person::getPassword() const
{
	return password;
}

void Person::setName(const char* _name)
{
	if (_name == nullptr)
	{
		return;
	}

	int size = strlen(_name);

	if (size <= 20)
	{
		return;
	}

	strcpy_s(name, size, _name);
	name[size] = '\0';
}

void Person::setEGN(const char* _EGN)
{
	if (_EGN == nullptr)
	{
		return;
	}

	int size = strlen(_EGN);

	if (size <= 20)
	{
		return;
	}

	strcpy_s(EGN, size, _EGN);
	EGN[size] = '\0';
}

void Person::setPassword(const char* _password)
{
	if (_password == nullptr)
	{
		return;
	}

	int size = strlen(_password);

	if (size <= 20)
	{
		return;
	}

	strcpy_s(password, size, _password);
	password[size] = '\0';
}

bool Person::signUp(const char* _name, const char* _EGN, const char* _password)
{
	int personsCount = countPersont();

	if (personsCount < 0 || personsCount >= 3)
	{
		std::cerr << "no.";
		return false;
	}

	std::ifstream ifs("persons.dat", std::ios::binary | std::ios::app);
	Person tmp;
	while (ifs.read((char*) &tmp, sizeof(Person)))
	{
		if (strcmp(tmp.getEGN(), _EGN) == 0)
		{
			std::cerr << "exist";
			return false;
		}
	}

	ifs.close();

	std::ofstream ofs("persons.dat", std::ios::binary);
	Person p;
	p.setEGN(_EGN);
	p.setName(_name);
	p.setPassword(_password);
	ofs.write((const char*) this, sizeof(Person));

	ofs.close();
	return true;
}

bool Person::login(const char* _EGN, const char* password) const
{
	return false;
}

void Person::displayPerson() const
{
}

int Person::countPersont() const
{
	std::ifstream file("persons.dat", std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "no.";
		return -1;
	}

	file.seekg(0, std::ios::end);
	int size = file.tellg();

	file.close();

	return size / sizeof(Person);
}
