#pragma once
#include <fstream>

class Task 
{
private:
	char* description;
	int priority;
	bool status;
	int duration;

	// Static shared this with all objects, like counter in all objects
	static const int MAX_PRIORITY = 10;

	void setDescription(const char* description);

	void copyFrom(const Task& other);
	void remove();
public:
	Task();
	Task(const char* description, int priority, int duration);

	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();

	const char* getDescription() const;
	int getPriority() const;
	bool getStatus() const;
	int getDuration() const;

	void setPriority(int priority);
	void markAsComplete();
	void setDuration(int duration);

	const Task& compare(const Task& other) const;
	bool writeToFile(std::ofstream& ofs) const;
	bool readFromFile(std::ifstream& ifs);
};