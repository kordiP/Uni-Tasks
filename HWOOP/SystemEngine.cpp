/*
	Atanas Kordov, 5MI0600508
*/
#include "SystemEngine.h"

SystemEngine* SystemEngine::instance = nullptr;

SystemEngine::SystemEngine() : admin(Admin::getInstance())
{
	currentUser = nullptr;
}

bool SystemEngine::userHasAccess(const MyString& expectedRole) const
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

	throw std::invalid_argument("Id not found.");
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

void SystemEngine::changePassword(const MyString& oldPass, const MyString& newPass)
{
	if (!currentUser->checkPassword(oldPass))
	{
		throw std::invalid_argument("Incorrect password.");
	}
	
	currentUser->setPassword(newPass);
}

void SystemEngine::printMailbox() const
{
	currentUser->showInbox();
}

void SystemEngine::clearInbox()
{
	currentUser->clearInbox();
}

void SystemEngine::printLoginInfo() const
{
	if (currentUser->getRole() == "Admin")
	{
		return;
	}

	std::cout << currentUser->getName() << " " << currentUser->getSurname() << " | ";
	std::cout << currentUser->getRole() << " | ";
	std::cout << currentUser->getId() << std::endl;
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

void SystemEngine::printGrades()
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
			std::cout << curCourse.getName() << " | ";
			std::cout << assignments[i].getTitle() << " | ";
			std::cout << assignments[i].getStudentGrade(student.getId()) << " | ";
			std::cout << assignments[i].getSolution(student.getId()).getLecturerResponse() << std::endl;
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

	if (currentUser != nullptr)
	{
		throw std::logic_error("Already logged in an account.");
	}

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
	MyString commandLine;
	std::cout << "> ";
	getline(std::cin, commandLine);

	while (commandLine != exitCom)
	{
		size_t splitPos = commandLine.find(' ');
		MyString action = commandLine.substring(0, splitPos);

		try
		{
			if (action == "login")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString readId = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				int userId = readId.asciiToInt();
				MyString passAttempt = commandLine.substring(splitEnd + 1);
				
				login(userId, passAttempt);
				std::cout << "Login succesful!" << std::endl;
				printLoginInfo();
			}
			else if (action == "add_teacher")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString fName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				size_t splitEnd2 = commandLine.find(' ', 2);
				MyString lName = commandLine.substring(splitEnd + 1, splitEnd2 - splitEnd - 1);
				MyString pass = commandLine.substring(splitEnd2 + 1);

				registerLecturer(fName, lName, pass);
				std::cout << "Added lecturer " << fName << " " << lName << " with ID " << lecturers[lecturers.getSize() - 1].getId() << std::endl;
			}
			else if (action == "add_student")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString fName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				size_t splitEnd2 = commandLine.find(' ', 2);
				MyString lName = commandLine.substring(splitEnd + 1, splitEnd2 - splitEnd - 1);
				MyString pass = commandLine.substring(splitEnd2 + 1);

				registerStudent(fName, lName, pass);
				std::cout << "Added student " << fName << " " << lName << " with ID " << students[students.getSize() - 1].getId() << std::endl;
			}
			else if (action == "message_all")
			{
				MyString description = commandLine.substring(splitPos + 1);

				sendGlobalMessage(description);
			}
			else if (action == "logout")
			{
				logout();
				std::cout << std::endl;
			}
			else if (action == "change_password")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString oldPass = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				MyString newPass = commandLine.substring(splitEnd + 1);

				changePassword(oldPass, newPass);
				std::cout << "Password changed successfully!" << std::endl;
			}
			else if (action == "create_course")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString courseName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				MyString pass = commandLine.substring(splitEnd + 1);

				createCourse(courseName, pass);
			}
			else if (action == "add_to_course")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString readId = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				int userId = readId.asciiToInt();
				MyString courseName = commandLine.substring(splitEnd + 1);

				enrollStudent(userId, courseName);
			}
			else if (action == "mailbox")
			{
				printMailbox();
			}
			else if (action == "enroll")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString courseName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				MyString passAttempt = commandLine.substring(splitEnd + 1);

				enrollSelf(passAttempt, courseName);
				std::cout << "Successfully enrolled in " << courseName << "!" << std::endl;
			}
			else if (action == "assign_homework")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString courseName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				MyString title = commandLine.substring(splitEnd + 1);

				createAssignment(title, courseName);
				std::cout << "Successfully created a new assignment!" << std::endl;
			}
			else if (action == "message_students")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString courseName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				MyString mess = commandLine.substring(splitEnd + 1);

				messageStudentsInCourse(courseName, mess);
			}
			else if (action == "submit_assignment")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString courseName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				size_t splitEnd2 = commandLine.find(' ', 2);
				MyString assignmentName = commandLine.substring(splitEnd + 1, splitEnd2 - splitEnd - 1);
				MyString sol = commandLine.substring(splitEnd2 + 1);

				submitStudentSolution(courseName, assignmentName, sol);
			}
			else if (action == "message")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString readId = commandLine.substring(splitPos, splitEnd);
				int userId = readId.asciiToInt();
				MyString mess = commandLine.substring(splitEnd);

				sendMessage(userId, mess);
			}
			else if (action == "view_assignment_submissions")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString courseName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				MyString assignmentName = commandLine.substring(splitEnd + 1);

				showAssignmentResponses(courseName, assignmentName);
			}
			else if (action == "grade_assignment")
			{
				size_t splitEnd = commandLine.find(' ', 1);
				MyString courseName = commandLine.substring(splitPos + 1, splitEnd - splitPos - 1);
				size_t splitEnd2 = commandLine.find(' ', 2);
				MyString assignmentName = commandLine.substring(splitEnd + 1, splitEnd2 - splitEnd - 1);
				size_t splitEnd3 = commandLine.find(' ', 3);
				MyString readId = commandLine.substring(splitEnd2 + 1, splitEnd3 - splitEnd2 - 1);
				int studentId = readId.asciiToInt();
				size_t splitEnd4 = commandLine.find(' ', 4);
				MyString readGrade = commandLine.substring(splitEnd3 + 1, splitEnd4 - splitEnd3 - 1);
				double grade = readGrade.asciiToDouble();
				MyString comment = commandLine.substring(splitEnd4 + 1);

				gradeAssignment(courseName, assignmentName, studentId, grade, comment);
			}
			else if (action == "clear_mailbox")
			{
				clearInbox();
			}
			else if (action == "grades")
			{
				printGrades();
			}
		}
		catch (const std::invalid_argument& ia)
		{
			std::cout << ia.what() << std::endl;
		}
		catch (const std::logic_error& le)
		{
			std::cout << le.what() << std::endl;
		}

		commandLine = "";
		std::cout << "> ";
		getline(std::cin, commandLine);
	}
}
