#pragma once
#include "Computer.h"

class Laptop : public Computer
{
private:
	static const char* type;
	static const char* perifer;
public:
	const char* getType() const override;
	const char* getPerifer() const override;
};
// for .cpp
const char* Laptop::type = "Laptop";