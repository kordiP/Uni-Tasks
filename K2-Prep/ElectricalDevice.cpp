//#include "Object.cpp"
//#include "Battery.cpp"
//#include <iostream>
//
//class ElectricalDevice : public Object
//{
//private:
//	double inputPower;
//	double consumation;
//	Battery* battery; // may or maynot exist
//
//	void freeMem()
//	{
//		delete battery;
//		battery = nullptr;
//	}
//	void copyFrom(const ElectricalDevice& other)
//	{
//		inputPower = other.inputPower;
//		consumation = other.consumation;
//		battery = new Battery(*other.battery); //!!!
//	}
//public:
//	ElectricalDevice(double lat, double lon, double in, double cons) : Object(lat, lon)
//	{
//		inputPower = in;
//		consumation = cons;
//	}
//	ElectricalDevice(double lat, double lon, double in, double cons, const Battery& other) : Object(lat, lon)
//	{
//		inputPower = in;
//		consumation = cons;
//		this->battery = new Battery(other);
//	}
//	ElectricalDevice(const ElectricalDevice& other) : Object(other) {
//		copyFrom(other);
//	}
//	ElectricalDevice& operator=(const ElectricalDevice& other) {
//		if (this != &other) {
//			freeMem();
//			copyFrom(other);
//		}
//
//		return *this;
//	}
//	~ElectricalDevice() {
//		freeMem();
//	}
//
//	double getInput() const
//	{
//		return inputPower;
//	}
//	double getConsumtion() const
//	{
//		return consumation;
//	}
//	Battery& getBattery() const
//	{
//		return *battery; // if it's nullptr it will return nullptr
//	}
//
//	ElectricalDevice& setInput(double inp)
//	{
//		if (inp <= 0)
//		{
//			throw std::invalid_argument("Input power cannot be negative or 0.");
//		}
//
//		inputPower = inp;
//
//		return *this;
//	}
//	ElectricalDevice& setConsumation(double cons)
//	{
//		if (cons <= 0)
//		{
//			throw std::invalid_argument("Consumation cannot be negative or 0.");
//		}
//
//		consumation = cons;
//
//		return *this;
//	}
//	
//	void changeBattery(const Battery& battery) {
//		delete this->battery;
//		this->battery = new Battery(battery);
//	}
//
//	void chargeBattery(double Wh) {
//		if (battery) {
//			battery->setCharge(battery->getCharge() + Wh / battery->getCapacity());
//
//			if (battery->getCharge() > 1) {
//				battery->setCharge(1);
//			}
//		}
//	}
//
//	void dischargeBattery(double Wh) {
//		if (battery) {
//			battery->setCharge(battery->getCharge() - Wh / battery->getCapacity());
//
//			if (battery->getCharge() < 0) {
//				battery->setCharge(0);
//			}
//		}
//	}
//};