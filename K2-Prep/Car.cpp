#include "Object.cpp"
#include <iostream>

class Car : public Object
{
private:
	char* brand;
	char* model;
	size_t prodYear;
	double fuel;
	double fuelCap;
	double averageConsumption;

	void setStr(const char* src, char* &dest)
	{
		delete[] dest;
		size_t size = strlen(src);
		dest = new char[size + 1];
		strcpy_s(dest, strlen(src) + 1, src);
		dest[size] = '\0';
	}
	void freeMem()
	{
		delete[] brand;
		delete[] model;
		brand = nullptr;
		model = nullptr;
	}
	void copyFrom(const Car& other)
	{
		prodYear = other.prodYear;
		fuelCap = other.fuelCap;
		fuel = other.fuel;
		averageConsumption = other.averageConsumption;

		setStr(other.brand, brand);
		setStr(other.model, model);
	}
public:
	Car(double lat, double lon, const char* brand, const char* model, size_t prodYear, double fuel, double cap, double avgCon) : Object(lat, lon)
	{
		setStr(brand, this->brand);
		setStr(model, this->model);
		this->prodYear = prodYear;
		this->fuel = fuel;
		fuelCap = cap;
		averageConsumption = avgCon;
	}
	Car(const Car& other) : Object(other)
	{
		copyFrom(other);
	}
	Car& operator=(const Car& other)
	{
		if (this != &other)
		{
			freeMem();
			copyFrom(other);
		}

		return *this;
	}
	~Car()
	{
		freeMem();
	}

	const char* getBrand() const
	{
		return brand;
	}
	const char* getModel() const
	{
		return model;
	}
	size_t getProdYear() const
	{
		return prodYear;
	}
	double getFuel() const
	{
		return fuel;
	}
	double getFuelCap() const
	{
		return fuelCap;
	}
	double getAvgCons() const
	{
		return averageConsumption;
	}

	void setBrand(const char* str)
	{
		if (str == nullptr)
		{
			throw std::invalid_argument("Nullstr");
		}

		setStr(str, brand);
	}
	void setModel(const char* str)
	{
		if (str == nullptr)
		{
			throw std::invalid_argument("Nullstr");
		}

		setStr(str, model);
	}
	void setYear(size_t year)
	{
		if (year > 2025 || year < 1800)
		{
			throw std::invalid_argument("Year.");
		}

		prodYear = year;
	}
	void setFuelCap(double cap)
	{
		if (cap < 0)
		{
			throw std::invalid_argument("Capacity.");
		}

		fuelCap = cap;
	}
	void setAvgCon(double con)
	{
		if (con < 0)
		{
			throw std::invalid_argument("Consumption.");
		}

		averageConsumption = con;
	}

	void refuel(double litres)
	{
		if (litres > fuelCap)
		{
			throw std::invalid_argument("Too much fuel.");
		}
		fuel += litres;
	}

	void drive(double km)
	{
		double litersToBeConsumed = km * (averageConsumption / 100);
		if (litersToBeConsumed > fuel)
		{
			// izminali sme (fuel / km) * 100
			fuel = 0;
		}
		else
		{
			fuel -= litersToBeConsumed;
		}
	}
	void drive(const Object& other)
	{
		if (fuel == 0) return;

		double lat1 = getLatitude();
		double lon1 = getLongitude();
		double lat2 = other.getLatitude();
		double lon2 = other.getLongitude();
		double distance = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1)) * 6371;

		fuel -= (distance / 100) * averageConsumption;

		if (fuel < 0) {
			fuel = 0;
		}
		else {
			setLatitude(other.getLatitude());
			setLongitude(other.getLongitude());
		}
	}
};