#pragma once

class Spaceship {
private:
	char* name;
	int speed;
	double fuelCapacity;

	void copy(const Spaceship& other);
	void remove();
	void setName(const char* name);
public:
	Spaceship() = delete;
	Spaceship(const char* name);
	Spaceship(const char* name, int speed, double fuelCapacity);

	Spaceship(const Spaceship& other);
	Spaceship& operator=(const Spaceship& other);
	~Spaceship();

	void setSpeed(int speed);
	void setFuelCapacity(double fuelCapacity);

	const char* getName() const;
	int getSpeed() const;
	double getFuelCapacity() const;

	void writeToFile();
	void readFromFile();
};