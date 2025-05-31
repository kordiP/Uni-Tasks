#include "Assignment.h"

Assignment::SolutionPair::SolutionPair(int stId, const MyString& fName, const MyString& lName, const MyString& solution)
{
    studentId = stId;
    studentFirstName = fName;
    studentLastName = lName;
    this->solution = solution;
}

void Assignment::SolutionPair::printSolution() const
{
    switch (graded)
    {
    case true:
        std::cout << "Graded with (" << grade << ") : " << studentFirstName << " " << studentLastName << ", " << studentId << " " << solution;
        break;
    default:
        std::cout << studentFirstName << " " << studentLastName << ", " << studentId << " " << solution;
        break;
    }
}

void Assignment::SolutionPair::addResponse(const MyString& response, double grade)
{
    lecturerResponse = response;
    this->grade = grade;
    graded = true;
}

int Assignment::SolutionPair::getStudentId() const
{
    return studentId;
}

bool Assignment::SolutionPair::isGraded() const
{
    return graded;
}

double Assignment::SolutionPair::getGrade() const
{
    return grade;
}

const MyString& Assignment::SolutionPair::getLecturerResponse() const
{
    return lecturerResponse;
}

void Assignment::submitSolution(int studentId, const MyString& fName, const MyString& lName, const MyString& solution)
{
    SolutionPair sp(studentId, fName, lName, solution);
    solutions.pushBack(sp);
}

void Assignment::gradeAssignment(double grade, const MyString& response, int studentId)
{
    if (grade < 2 || grade > 6)
    {
        throw std::invalid_argument("Invalid grade.");
    }
    
    SolutionPair& sol = getSolution(studentId);
    sol.addResponse(response, grade);
}

const MyString& Assignment::getStudentGrade(int studentId) const
{
    const SolutionPair& sol = getSolution(studentId);
    MyString grade(" | " + title + " | " + sol.getGrade() + sol.getLecturerResponse());

    return grade;
}

Assignment::Assignment(const MyString& title) : title(title)
{
}

const MyString& Assignment::getTitle() const
{
    return title;
}

Assignment::SolutionPair& Assignment::getSolution(int studentId)
{
    for (size_t i = 0; i < solutions.getSize(); i++)
    {
        if (solutions[i].getStudentId() == studentId)
        {
            return solutions[i];
        }

        throw std::invalid_argument("Student has no submission to this assignment.");
    }
}

const Assignment::SolutionPair& Assignment::getSolution(int studentId) const
{
    for (size_t i = 0; i < solutions.getSize(); i++)
    {
        if (solutions[i].getStudentId() == studentId)
        {
            return solutions[i];
        }

        throw std::invalid_argument("Student has no submission to this assignment.");
    }
}

void Assignment::printSubmissions() const
{
    for (size_t i = 0; i < solutions.getSize(); i++)
    {
        solutions[i].printSolution();
    }
}
