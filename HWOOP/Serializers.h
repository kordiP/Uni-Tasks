#pragma once
#include <fstream>

const char userFile[] = "users.bin";
const char courseFile[] = "users.bin";

class Serializers
{
private:
	void readUsers() const;
	void readCourses() const;

	void saveToCourses();
	void saveToUsers();
public:
	void readFromFile() const;
	void saveToFile();
};