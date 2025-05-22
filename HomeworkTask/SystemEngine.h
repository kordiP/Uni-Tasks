#pragma once
#include <iostream>
#include "Student.h"
#include "Admin.h"
#include "Teacher.h"
#include "Course.h"
#include "MyVector.hpp"
#include <iostream>

class SystemEngine 
{
private:
	MyVector<Student> students;
	MyVector<Teacher> teachers;
	//Admin& admin;

	MyVector<Course> courses;
	SystemEngine();
public:
	static SystemEngine& getInstance();

	void deleteUser(int id);
	void createStudent();
	void createTeacher();
	void sendGlobalMessage();

	void createCourse();
	void createAssignment();

	void run();
};