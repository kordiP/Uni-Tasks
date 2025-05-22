#include "Laptop.h"

const char* Laptop::type = "Laptop";
const char* Laptop::perifer = "Speakers, Headset";

const char* Laptop::getType() const
{
	return type;
}

const char* Laptop::getPerifer() const
{
	return perifer;
}