/*
	Atanas Kordov, 5MI0600508
*/
#include "SystemEngine.h"

SystemEngine* SystemEngine::instance = nullptr;

SystemEngine::SystemEngine() : admin(Admin::getInstance())
{
	currentUser = nullptr;

	commands.pushBack("login");
	commands.pushBack("add_teacher");
	commands.pushBack("add_student");
	commands.pushBack("message_all");
	commands.pushBack("logout");
	commands.pushBack("change_password");
	commands.pushBack("create_course");
	commands.pushBack("add_to_course");
	commands.pushBack("mailbox");
	commands.pushBack("enroll");
	commands.pushBack("assign_homework");
	commands.pushBack("message_students");
	commands.pushBack("submit_assignment");
	commands.pushBack("view_assignment_submissions");
	commands.pushBack("grade_assignment");
	commands.pushBack("clear_mailbox");
	commands.pushBack("grades");
}

bool SystemEngine::userHasAccess(const MyString& expectedRole)
{
	if (currentUser->getRole() != expectedRole)
	{
		return false;
	}

	return true;
}

User* SystemEngine::getUser(int userId)
{
	if (userId == 0)
	{
		return admin;
	}
	for (int i = 0; i < students.getSize(); i++)
	{
		if (students[i].getId() == userId)
			return &students[i];
	}
	for (int i = 0; i < lecturers.getSize(); i++)
	{
		if (lecturers[i].getId() == userId)
			return &lecturers[i];
	}

	return nullptr;
}

Student& SystemEngine::getStudent(int userId)
{
	for (size_t i = 0; i < students.getSize(); i++)
	{
		if (students[i].getId() == userId)
			return students[i];
	}

	throw std::invalid_argument("No student with this id found in system.");
}

Lecturer& SystemEngine::getLecturer(int userId)
{
	for (size_t i = 0; i < lecturers.getSize(); i++)
	{
		if (lecturers[i].getId() == userId)	
			return lecturers[i];
	}

	throw std::invalid_argument("No lecturer with this id found in system.");
}

Course& SystemEngine::getCourse(const MyString& courseName)
{
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if (courses[i].getName() == courseName)
			return courses[i];
	}

	throw std::invalid_argument("No course with this name found in system.");
}

void SystemEngine::sendMessage(int recepientId, const MyString& descr)
{
	Message mess(currentUser->getId(), descr, currentUser->getName());
	User* recepient = getUser(recepientId);
	recepient->receiveMessage(mess);
}

void SystemEngine::submitStudentSolution(const MyString& courseName, const MyString& assignmentName, const MyString& sol)
{
	Course& course = getCourse(courseName);

	if (!userHasAccess("Student"))
	{
		throw std::logic_error("Student only action.");
	}
	if (!course.getAssignmentsNames().contains(assignmentName))
	{
		throw std::invalid_argument("Assignment not found.");
	}

	course.addSolutionToAssignment(assignmentName, currentUser->getId(), currentUser->getName(), currentUser->getSurname(), sol);
}

void SystemEngine::getGrades()
{
	if (!userHasAccess("Student"))
	{
		throw std::logic_error("Student only action.");
	}

	Student& student = getStudent(currentUser->getId());
	const MyVector<MyString>& studentCourses = student.getCourses();

	for (size_t i = 0; i < studentCourses.getSize(); i++)
	{
		Course& curCourse = getCourse(studentCourses[i]);
		const MyVector<Assignment>& assignments = curCourse.getAssignments();


		for (size_t i = 0; i < assignments.getSize(); i++)
		{
			assignments[i].getStudentGrade(student.getId());
		}
	}
}

void SystemEngine::createCourse(const MyString& courseName, const MyString& pass)
{
	if (!userHasAccess("Lecturer"))
	{
		throw std::logic_error("Only lecturers can create courses.");
	}

	Course course(courseName, pass);
	courses.pushBack(course);

	Lecturer& l = getLecturer(currentUser->getId());

	l.addCourse(course.getName());
}

void SystemEngine::createAssignment(const MyString& title, const MyString& courseName)
{
	if (!userHasAccess("Lecturer"))
	{
		throw std::logic_error("Only lecturers can create assignments.");
	}

	Assignment assignment(title);
	Course& course = getCourse(courseName);
	course.addAssignment(assignment);
}

void SystemEngine::gradeAssignment(const MyString& courseName, const MyString& assignmentName, int studentId, double grade, const MyString& comment)
{
	if (!userHasAccess("Lecturer"))
	{
		throw std::logic_error("Only lecturers can grade assignments.");
	}

	Lecturer& l = getLecturer(currentUser->getId());

	if (!l.getCourses().contains(courseName))
	{
		throw std::invalid_argument("Course id not found in Your courses.");
	}

	Course& c = getCourse(courseName);
	c.gradeAssignment(courseName, studentId, grade, comment);
}

void SystemEngine::showAssignmentResponses(const MyString& courseName, const MyString& assignmentName)
{
	if (!userHasAccess("Lecturer"))
	{
		throw std::logic_error("Only lecturers can grade assignments.");
	}

	Lecturer& l = getLecturer(currentUser->getId());

	if (!l.getCourses().contains(courseName))
	{
		throw std::invalid_argument("Course id not found in Your courses.");
	}

	Course& c = getCourse(courseName);
	c.printAssignmentResponses(assignmentName);
}

void SystemEngine::enrollStudent(int studentId, const MyString& courseName)
{
	if (!userHasAccess("Lecturer"))
	{
		throw std::logic_error("Only lecturers can grade assignments.");
	}

	Lecturer& l = getLecturer(currentUser->getId());

	if (!l.getCourses().contains(courseName))
	{
		throw std::invalid_argument("Course id not found in Your courses.");
	}

	Student& s = getStudent(studentId);
	s.addToCourse(courseName);
}

void SystemEngine::messageStudentsInCourse(const MyString& courseName, const MyString& mess)
{
	if (!userHasAccess("Lecturer"))
	{
		throw std::logic_error("Lecturer only action.");
	}

	for (size_t i = 0; i < students.getSize(); i++)
	{
		if (students[i].getCourses().contains(courseName))
		{
			sendMessage(students[i].getId(), mess);
		}
	}
}

void SystemEngine::enrollSelf(const MyString& attempt, const MyString& courseName)
{
	Course& c = getCourse(courseName);
	if (!c.isPasswordCorrect(attempt))
	{
		throw std::invalid_argument("Password does not match course's.");
	}

	if (userHasAccess("Lecturer"))
	{
		Lecturer& l = getLecturer(currentUser->getId());
		l.addCourse(courseName);
	}
	else if (userHasAccess("Student"))
	{
		Student& s = getStudent(currentUser->getId());
		s.addToCourse(courseName);
	}
	else
	{
		throw std::logic_error("Can't enroll in course.");
	}
}

void SystemEngine::registerStudent(const MyString& fName, const MyString& lName, const MyString& pass)
{
	Student s(fName, lName, pass);
	students.pushBack(s);
}

void SystemEngine::registerLecturer(const MyString& fName, const MyString& lName, const MyString& pass)
{
	Lecturer l(fName, lName, pass);
	lecturers.pushBack(l);
}

void SystemEngine::deleteUser(int userId)
{
	if (userId == 0)
	{
		throw std::invalid_argument("Admin is not deletable.");
	}

	User* u = getUser(userId);

	if (u == nullptr)
	{
		throw std::invalid_argument("User with this id doesn't exist.");
	}

	if (u->getRole() == "Student")
	{
		Student& s = getStudent(userId);
		students.remove(s);
	}
	else if (u->getRole() == "Lecturer")
	{
		Lecturer& l = getLecturer(userId);
		lecturers.remove(l);
	}
}

void SystemEngine::sendGlobalMessage(const MyString& descr)
{
	if (!userHasAccess("Admin"))
	{
		throw std::logic_error("Admin only action.");
	}

	Message mess(currentUser->getId(), descr, currentUser->getName());

	for (size_t i = 0; i < lecturers.getSize(); i++)
	{
		lecturers[i].receiveMessage(mess);
	}
	for (size_t i = 0; i < students.getSize(); i++)
	{
		students[i].receiveMessage(mess);
	}
}

void SystemEngine::openUserMail(int userId)
{
	if (!userHasAccess("Admin"))
	{
		throw std::logic_error("Admin only action.");
	}

	User* u = getUser(userId);
	u->showInbox();
	u = nullptr;
}

void SystemEngine::login(int idAtt, const MyString& passAtt)
{
	User* u = getUser(idAtt);

	if (!u->checkPassword(passAtt))
	{
		throw std::invalid_argument("Wrong password for account.");
	}

	currentUser = u;
	u = nullptr;
}

void SystemEngine::logout()
{
	if (currentUser == nullptr)
	{
		throw std::logic_error("No logged user.");
	}
	currentUser = nullptr;
}

SystemEngine* SystemEngine::getInstance()
{
	if (instance == nullptr)
	{
		instance = new SystemEngine();
	}
	return instance;
}

SystemEngine::~SystemEngine()
{
	delete instance;
	instance = nullptr;
}

void SystemEngine::run()
{
	const MyString exitCom("exit");
	MyString command;
	getline(std::cin, command);

	while (command != exitCom)
	{
		if (true)
		{

		}
		else if (true)
		{

		}

		getline(std::cin, command);
	}
}
