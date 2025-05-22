#include "MyString.h"

void MyString::freeMem()
{
	delete[] str;
	str = nullptr;
}
void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	str = new char[size + 1];
	strcpy_s(str, size, other.str);
}
MyString::MyString()
{
	size = 1;
	str = new char[size + 1];
	str[0] = '\0';
}
MyString::MyString(const char* strn)
{
	if (strn == nullptr)
	{
		throw std::invalid_argument("Nullptr for input.");
	}

	size = strlen(strn) + 1;
	str = new char[size];
	strcpy_s(str, size, strn);
	str[size - 1] = '\0';
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

// !
const char& MyString::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::invalid_argument("Index out of range.");
	}

	return str[index];
}

MyString& MyString::operator+=(const MyString& mstr)
{
	int finalSize = size + mstr.size;
	char* finalStr = new char[finalSize + 1];

	strcpy_s(finalStr, finalSize, str);
	strcat_s(finalStr, finalSize, mstr.str);
	finalStr[finalSize] = '\0';

	freeMem();
	size = finalSize;
	str = finalStr;

	finalStr = nullptr;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& mstr)
{
	os << mstr.str;
	return os;
}

//!
std::istream& operator>>(std::istream& is, MyString& mstr)
{
	char buffer[1024];
	is >> buffer;

	delete[] mstr.str;

	mstr.size = strlen(buffer);
	mstr.str = new char[mstr.size + 1];
	strcpy_s(mstr.str, mstr.size + 1, buffer);

	return is;
}

bool MyString::operator==(const MyString& mstr) const
{
	if (this->size != mstr.size || strcmp(this->str, mstr.str) != 0)
	{
		return false;
	}
	return true;
}

bool MyString::operator!=(const MyString& mstr) const
{
	return !(*this == mstr);
}

bool MyString::operator<(const MyString& mstr) const
{
	if (strcmp(this->str, mstr.str) < 0)
	{
		return true;
	}
	return false;
}

bool MyString::operator>(const MyString& mstr) const
{
	return mstr < *this;
}

bool MyString::operator>=(const MyString& mstr) const
{
	return !(*this < mstr);
}

bool MyString::operator<=(const MyString& mstr) const
{
	return !(*this > mstr);
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}