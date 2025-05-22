#include <iostream>
#include "Computer.h"

void Computer::freeMem()
{
	delete[] gpuModel;
	gpuModel = nullptr;
}

void Computer::copyFrom(const Computer& other)
{
	setCPUPower(other.cpuPower);
	setGPUModel(other.gpuModel);
	setPSU(other.psuPower);
	setRAM(other.ramSize);
}

Computer::Computer(double cpuPow, const char* gpuMod, int psu, int ram)
{
	setCPUPower(cpuPow);
	setGPUModel(gpuMod);
	setPSU(psu);
	setRAM(ram);
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		freeMem();
		copyFrom(other);
	}
	return *this;
}

Computer::~Computer()
{
	freeMem();
}

int Computer::getRAM() const
{
	return 0;
}

int Computer::getPSU() const
{
	return 0;
}

const char* Computer::getGPUModel() const
{
	return nullptr;
}

double Computer::getCPUPower() const
{
	return 0.0;
}

void Computer::setRAM(int ram)
{
}

void Computer::setPSU(int psu)
{
}

void Computer::setGPUModel(const char* gpu)
{
}

void Computer::setCPUPower(double cpuPow)
{
}


