#pragma once
#include "Admin.h"
#include "Assignment.h"
#include "Course.h"
#include "Lecturer.h"
#include "Message.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Student.h"
#include "User.h"
#include <exception>
#include <iostream>
#include <stdexcept>

class SystemEngine
{
private:
	static SystemEngine* instance;
	SystemEngine();

	User* currentUser;
	Admin* admin;
	MyVector<Student> students;
	MyVector<Lecturer> lecturers;
	MyVector<Course> courses;

	// for engine
	bool userHasAccess(const MyString& expectedRole) const;
	User* getUser(int userId);
	Student& getStudent(int userId);
	Lecturer& getLecturer(int userId);
	Course& getCourse(const MyString& courseName);
	// any user
	void sendMessage(int recepientId, const MyString& descr);
	void changePassword(const MyString& oldPass, const MyString& newPass);
	void printMailbox() const;
	void clearInbox();
	void printLoginInfo() const;
	// student only
	void submitStudentSolution(const MyString& courseName, const MyString& assignmentName, const MyString& sol);
	void printGrades();
	// lecturers only
	void createCourse(const MyString& courseName, const MyString& pass);
	void createAssignment(const MyString& title, const MyString& courseName);
	void gradeAssignment(const MyString& courseName, const MyString& assignmentName, int studentId, double grade, const MyString& comment);
	void showAssignmentResponses(const MyString& courseName, const MyString& assignmentName);
	void enrollStudent(int studentId, const MyString& courseName);
	void messageStudentsInCourse(const MyString& courseName, const MyString& mess);
	// lecturers+students only
	void enrollSelf(const MyString& attempt, const MyString& courseName);
	// admin only
	void registerStudent(const MyString& fName, const MyString& lName, const MyString& pass);
	void registerLecturer(const MyString& fName, const MyString& lName, const MyString& pass);
	void deleteUser(int userId);
	void sendGlobalMessage(const MyString& descr);
	void openUserMail(int userId);
	// current user commands
	void login(int idAtt, const MyString& passAtt);
	void logout();
public:
	SystemEngine(const SystemEngine&) = delete;
	SystemEngine& operator=(const SystemEngine&) = delete;
	~SystemEngine();

	static SystemEngine* getInstance();
	void run();
};