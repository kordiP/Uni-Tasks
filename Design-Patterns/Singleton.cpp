#include <iostream>

class DataBase
{
private:
	int data;
public:
	int getData() const
	{
		return data;
	}

	void setData(int dat)
	{
		if (data < 0)
		{
			return;
		}
		this->data = dat;
	}
};

class Singleton
{
	Singleton() = default;
	Singleton(const Singleton& other) = delete;

public:
	static DataBase& getDBInstance()
	{
		static DataBase db;
		return db;
	}
};

int main()
{
	DataBase db = Singleton::getDBInstance();
	db.setData(5);

	DataBase db2 = Singleton::getDBInstance();
	db.setData(2);
}