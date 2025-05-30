#include <iostream>

class Factory
{
	static Person* createPerson(const char* str)
	{
		if (!strcmp(str, "Student"))
		{
			return new Student();
		}
		else if (!strcmp(str, "Teacher"))
		{
			return new Teacher();
		}
		throw std::invalid_argument("Unrecognisable string.");
	}
};

class Person
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

	virtual void talk() const = 0;
};

class Teacher : public Person
{
private:
	double a = 0;
public :
	void talk() const override
	{

	}
};

class Student : public Person
{
private:
	double b = 0;
public:
	void talk() const override
	{

	}
};