#pragma once

class Computer
{
private:
	double cpuPower;
	char* gpuModel;
	int psuPower;
	int ramSize;

	void freeMem();
	void copyFrom(const Computer& other);
public:
	Computer(double cpuPow, const char* gpuMod, int psu, int ram);
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	~Computer();

	int getRAM() const;
	int getPSU() const;
	const char* getGPUModel() const;
	double getCPUPower() const;

	void setRAM(int ram);
	void setPSU(int psu);
	void setGPUModel(const char* gpu);
	void setCPUPower(double cpuPow);

	// having pure virtual makes the class abstract -> cannot have objects of this type
	virtual const char* getType() const = 0; // pure virtual, does not need implementation for base class
	virtual const char* getPerifer() const = 0;
};
