#include "MyString.h"


void MyString::freeMem()
{
	delete[] arr;
	arr = nullptr;
	capacity = 8;
	size = 0;
}

void MyString::resize()
{
	capacity *= 2;
	char* temp = new char[capacity];
	strcpy(temp, arr);
	temp[size] = '\0';

	delete[] arr;
	arr = temp;
}

void MyString::copyFrom(const MyString& other)
{
	capacity = other.capacity;
	size = other.size;
	setStr(other.arr);
}

void MyString::setStr(const char* str)
{
	if (str == nullptr)
	{
		std::cerr << "String can't be nullptr.\n";
		return;
	}

	capacity = 8;
	int len = strlen(str);
	if (capacity < len)
	{
		resize();
	}

	arr = new char[capacity];
	strcpy(arr, str);
	arr[len] = '\0';
}

MyString::MyString()
{
	capacity = 8;
	arr = new char[capacity];
	size = 0;
	arr[0] = '\0';
}

MyString::MyString(const char* str)
{
	setStr(str);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		freeMem();
		copyFrom(other);
	}

	return *this;
}

MyString::~MyString()
{
	freeMem();
}

char& MyString::operator[](int index)
{
	assert(index < size);
	assert(index >= 0);
	return arr[index];
}

const char& MyString::operator[](int index) const
{
	assert(index < size);
	assert(index >= 0);
	return arr[index];
}

MyString& MyString::operator+=(const MyString& other)
{
	if (capacity < size + other.size)
	{
		resize();
	}

	strcat(arr, other.arr);
}

const char* MyString::c_str() const
{
	return arr;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString temp(lhs);
	temp += rhs;

	return temp;
	// NE SE vrushta prazen obekt shtoto vrushtame MyString demek vikame copyctor i toi prai deep copy
}

std::ostream& operator<<(std::ostream& os, const MyString& other)
{
	os << other.c_str(); // == other.arr
	return os;
}

std::istream& operator>>(std::istream& is, MyString& other)
{
	const int BUFF_SIZE = 1024;
	char temp[BUFF_SIZE];

	is.getline(temp, BUFF_SIZE);

	if (other.size < is.gcount())
	{
		other.resize();
	}
	strcpy(other.arr, temp);

	return is;
}

bool operator==(const MyString& ohs, const MyString& rhs)
{
	return strcmp(ohs.c_str(), rhs.c_str());
}

bool operator!=(const MyString& ohs, const MyString& rhs)
{
	return !(ohs == rhs);
}

bool operator<(const MyString& ohs, const MyString& rhs)
{
	return (strcmp(ohs.c_str(), rhs.c_str()) < 0);
}

bool operator<=(const MyString& ohs, const MyString& rhs)
{
	return !(ohs > rhs);
}

bool operator>(const MyString& ohs, const MyString& rhs)
{
	return rhs < ohs;
}

bool operator>=(const MyString& ohs, const MyString& rhs)
{
	return !(ohs < rhs);
}
