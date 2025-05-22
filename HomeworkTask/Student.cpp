#include "Student.h"

Student::Student(const MyString& fName, const MyString& lName, const MyString& mail, const MyString& pass, int id) : User(fName, lName, mail, pass, id)
{
}

void Student::enrollInCourse(const MyString& pass, const Course& course)
{
}

void Student::sendSolution(const Assignment& assign, MyString& solution)
{
}

void Student::viewGrades() const
{
}

const MyString& Student::getRole() const
{
    return "Student";
}
