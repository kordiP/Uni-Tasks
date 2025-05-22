#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Assignment.h"

class Course
{
private:
	int id;
	MyString name;
	MyString enrollPass;
	MyVector<Assignment> assignments;
public:

};