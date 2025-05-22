#pragma once
#include "Computer.h"

class PC : public Computer
{
private:
	static const char* type;
	static const char* perifer;
public:
	const char* getType() const override;
	const char* getPerifer() const override;
};