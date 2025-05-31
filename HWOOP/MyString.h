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

	MyString& doubleToString(double num) const;
	int asciiToInt() const;
	double asciiToDouble() const;
	size_t find(char symbol, size_t skipVals = 0) const;
	MyString substring(size_t start, size_t length = 0) const;

	friend MyString operator+(const MyString& lhs, char sym);
	friend MyString operator+(char sym, const MyString& lhs);
};

MyString operator+(const MyString& lhs, const MyString& rhs);