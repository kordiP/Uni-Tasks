#include "Spaceship.h"
#include <iostream>
#include <fstream>

#pragma	warning(disable:4996)

void Spaceship::copy(const Spaceship& other)
{
	setName(other.name);
	setSpeed(other.speed);
	setFuelCapacity(other.fuelCapacity);
}

void Spaceship::remove()
{
	delete[] name;
	name = nullptr;
	speed = -1;
	fuelCapacity = -1;
}

void Spaceship::setName(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	int size = strlen(name) + 1;

	this->name = new char[size];

	strcpy(this->name, name);
	this->name[size] = '\0';
}

Spaceship::Spaceship(const char* name)
{
	setName(name);
	setSpeed(0);
	setFuelCapacity(0);
}

Spaceship::Spaceship(const char* name, int speed, double fuelCapacity)
{
	setName(name);
	setSpeed(speed);
	setFuelCapacity(fuelCapacity);
}

Spaceship::Spaceship(const Spaceship& other)
{
	copy(other);
}

Spaceship& Spaceship::operator=(const Spaceship& other)
{
	if (this != &other)
	{
		remove();
		copy(other);
	}

	return *this;
}

Spaceship::~Spaceship()
{
	remove();
}

void Spaceship::setSpeed(int speed)
{
	if (speed < 0)
	{
		return;
	}

	this->speed = speed;
}

void Spaceship::setFuelCapacity(double fuelCapacity)
{
	if (fuelCapacity < 0)
	{
		return;
	}

	this->fuelCapacity = fuelCapacity;
}

const char* Spaceship::getName() const
{
	return nullptr;
}

int Spaceship::getSpeed() const
{
	return 0;
}

double Spaceship::getFuelCapacity() const
{
	return 0.0;
}

void Spaceship::writeToFile()
{
	std::fstream file("file.bin", std::ios::in | std::ios::out | std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "Cannot open.";
		return;
	}

	int _nameSize = 0;
	char* _name;
	int _speed;
	double _fuelCapacity;
	bool found = false;

	while (!file.eof())
	{
		file.read(reinterpret_cast<char*> (&_nameSize), sizeof(int));

		_name = new char[_nameSize + 1];
		file.read(reinterpret_cast<char*> (&_name), _nameSize);

		if (strcmp(this->name, _name) == 0)
		{
			file.flush();
			file.write(reinterpret_cast<char*> (&this->speed), sizeof(int));
			file.write(reinterpret_cast<char*> (&this->fuelCapacity), sizeof(double));
			found = true;
		}

		file.read(reinterpret_cast<char*> (&_speed), sizeof(int));
		file.read(reinterpret_cast<char*> (&_fuelCapacity), sizeof(double));
	}


	if (!found)
	{
		file.clear();
		int size = strlen(this->name);
		file.flush();
		file.write(reinterpret_cast<char*> (&size), sizeof(int));
		file.write(reinterpret_cast<char*> (name), size);
		file.write(reinterpret_cast<char*> (&speed), sizeof(int));
		file.write(reinterpret_cast<char*> (&fuelCapacity), sizeof(double));
	}
}

void Spaceship::readFromFile()
{

}
