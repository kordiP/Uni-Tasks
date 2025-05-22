#pragma once
#include <iostream>
#include <cassert>

class MyString
{
private:
	char* arr;
	int size;
	int capacity;

	void freeMem();
	void copyFrom(const MyString& other);
	void setStr(const char* str);
	void resize();
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	char& operator[](int index);
	const char& operator[](int index) const;
	MyString& operator+=(const MyString& other);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyString& other);
	friend std::istream& operator>>(std::istream& is, MyString& other);

	const char* c_str() const;
};

bool operator==(const MyString& ohs, const MyString& rhs);
bool operator!=(const MyString& ohs, const MyString& rhs);

bool operator<(const MyString& ohs, const MyString& rhs);
bool operator<=(const MyString& ohs, const MyString& rhs);
bool operator>(const MyString& ohs, const MyString& rhs);
bool operator>=(const MyString& ohs, const MyString& rhs);

