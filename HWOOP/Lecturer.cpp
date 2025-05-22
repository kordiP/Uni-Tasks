#include "Lecturer.h"

const MyVector<int>& Lecturer::getCoursesIds() const
{
    return courses;
}

MyVector<int>& Lecturer::getCoursesIds()
{
    return courses;
}

Lecturer::Lecturer(const MyString& fName, const MyString& lName, const MyString& pass) : User(fName, lName, pass)
{
}

const MyString& Lecturer::getRole() const
{
    return "Lecturer";
}
