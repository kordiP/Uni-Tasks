#pragma once
#include <iostream>

class MyString
{
private:
	char* str;
	int size;

	void freeMem();
	void copyFrom(const MyString& other);
public:
	MyString();
	MyString(const char* strn);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	const char& operator[](int index) const;

	MyString& operator+=(const MyString& mstr);

	bool operator==(const MyString& mstr) const;
	bool operator!=(const MyString& mstr) const;

	friend bool operator<(const MyString& lhs, const MyString& rhs);
	friend bool operator>(const MyString& lhs, const MyString& rhs);
	friend bool operator<=(const MyString& lhs, const MyString& rhs);
	friend bool operator>=(const MyString& lhs, const MyString& rhs);

	friend std::ostream& operator<<(std::ostream& os, const MyString& mstr);
	friend std::istream& operator>>(std::istream& is, MyString& mstr);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};