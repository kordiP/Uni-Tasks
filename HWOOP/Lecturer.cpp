#include "Lecturer.h"
#include "Student.h"

void Lecturer::addCourse(const MyString& courseName)
{
    courses.pushBack(courseName);
}

const MyVector<MyString> Lecturer::getCourses() const
{
    return courses;
}

Lecturer::Lecturer(const MyString& fName, const MyString& lName, const MyString& pass) : User(fName, lName, pass)
{
}

bool Lecturer::operator==(const Lecturer& other) const
{
    return this->getId() == other.getId();
}

const MyString Lecturer::getRole() const
{
    return "Lecturer";
}
