#include "Teacher.h"

Teacher::Teacher(const MyString& fName, const MyString& lName, const MyString& mail, const MyString& pass, int id) : User(fName, lName, mail, pass, id)
{
}

void Teacher::createCourse(const MyString& courseName, const MyString& pass)
{
}

void Teacher::createAssignment(const MyString& title, const Course& course)
{
}

void Teacher::gradeAssignment(Assignment& assign, int studentId)
{
}

void Teacher::enrollStudent(const Student& stud, const Course& course)
{
}

const MyString& Teacher::getRole() const
{
    return "Teacher";
}

void Teacher::sendMessage(User* recipient, const MyString& description)
{
}

