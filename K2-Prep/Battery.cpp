#include "Object.cpp"
#include <iostream>

class Battery : public Object
{
private:
	const double capacity;
	double chargePercent;
public:
	Battery(double lat, double lon, double cap) : Object(lat, lon), capacity(cap)
	{
		chargePercent = 100;
	}

	double getCapacity()
	{
		return capacity;
	}
	double getCharge()
	{
		return chargePercent;
	}

	bool setCharge(double perc)
	{
		if (perc > 100 || perc < 0)
		{
			throw std::out_of_range("Percentage is between 0 and 100.");
		}

		chargePercent = perc;
	}
};