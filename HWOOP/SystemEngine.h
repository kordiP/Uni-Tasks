#pragma once
#include "MyString.h"
#include "Admin.h"
#include "Lecturer.h"
#include "Student.h"
#include "Course.h"

class SystemEngine
{
private:
	Admin& admin;
	MyVector<Student> students;
	MyVector<Lecturer> lecturers;
	MyVector<Course> courses;

	User* currentUser;
	
	SystemEngine();
	// for engine
	bool isValidUser(int userId);
	bool userHasAccess(int userId, const MyString& expectedRole);
	Student& getStudent(int userId);
	Lecturer& getLecturer(int userId);
	Course& getCourse(int courseId);
	// any user
	void sendMessage(int recepientId, const MyString& descr);
	// lecturers only
	void createCourse(const MyString& courseName, const MyString& pass);
	void createAssignment(const MyString& title, int courseId);
	void gradeAssignment(int assignmentId, int studentId);
	void showAssignmentResponses(int courseId, int assignmentId);
	void enrollStudent(int studentId, int courseId);
	// lecturers+students only
	void enrollSelf(const MyString& attempt);
	// admin only
	void registerStudent(const MyString& fName, const MyString& lName, const MyString& pass);
	void registerLecturer(const MyString& fName, const MyString& lName, const MyString& pass);
	void deleteUser(int userId);
	void sendGlobalMessage(const MyString& descr);
	void openUserMail(int userId);
	// current user commands
	void login(const MyString& idAtt, const MyString& passAtt);
	void logout();


	
public:
	static SystemEngine& getInstance();
	void run();
};