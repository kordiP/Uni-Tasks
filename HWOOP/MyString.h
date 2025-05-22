#pragma once
#include <iostream>

class MyString
{
private:
	char* str;
	size_t size;

	void freeMem();
	void copyFrom(const MyString& other);
public:
	MyString();
	MyString(const char* strn);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	const char& operator[](int index) const;
	char& operator[](int index);

	MyString& operator+=(const MyString& mstr);

	friend std::ostream& operator<<(std::ostream& os, const MyString& mstr);
	friend std::istream& operator>>(std::istream& is, MyString& mstr);
	friend std::istream& getline(std::istream& is, MyString& mstr);

	bool operator==(const MyString& mstr) const;
	bool operator!=(const MyString& mstr) const;

	bool operator<(const MyString& mstr) const;
	bool operator>(const MyString& mstr) const;
	bool operator>=(const MyString& mstr) const;
	bool operator<=(const MyString& mstr) const;
};

MyString operator+(const MyString& lhs, const MyString& rhs);