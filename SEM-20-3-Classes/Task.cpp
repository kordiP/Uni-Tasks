#include "Task.h"

void Task::setDescription(const char* description)
{
	if (description == nullptr)
	{
		return;
	}

	// ppc len bez +1
	int len = strlen(description) + 1;
	this->description = new char[len];
	strcpy_s(this->description, len, description);
	this->description[len - 1] = '\0';
}

void Task::copyFrom(const Task& other)
{
	int len = strlen(other.description) + 1;
	this->description = new char[len];
	strcpy_s(this->description, len, other.description);
	this->description[len - 1] = '\0';

	this->priority = other.priority;
	this->duration = other.duration;
	this->status = other.status;
}

void Task::remove()
{
	delete[] description;
	description = nullptr;
}

// inicializirasht list, izpulnqva se predi tqloto
Task::Task() : priority(0), duration(0), status(false)
{
	description = new char[1];
	description[0] = '\0';
}

Task::Task(const char* description, int priority, int duration)
{
	setDescription(description);
	setPriority(priority);
	this->status = false;
	setDuration(duration);
}

Task::Task(const Task& other)
{
	copyFrom(other);
}

Task& Task::operator=(const Task& other)
{
	copyFrom(other);
	return *this;
}

Task::~Task()
{
	remove();
}

const char* Task::getDescription() const
{
	return description;
}

int Task::getPriority() const
{
	return priority;
}

bool Task::getStatus() const
{
	return status;
}

int Task::getDuration() const
{
	return duration;
}

void Task::setPriority(int priority)
{
	if (priority > 0 && priority <= MAX_PRIORITY)
	{
		this->priority = priority;
	}
}

void Task::markAsComplete()
{
	status = true;
}

void Task::setDuration(int duration)
{
	if (duration > 0)
	{
		this->duration = duration;
	}
}

const Task& Task::compare(const Task& other) const
{
	if (this->priority > other.priority)
	{
		return *this;
	}

	if (this->priority == other.priority)
	{
		if (this->duration <= other.duration)
		{
			return *this;
		}
		else
		{
			return other;
		}
	}

	return other;
}

bool Task::writeToFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		return false;
	}

	int descrLen = strlen(description);
	ofs.write((const char*) &descrLen, sizeof(descrLen));
	ofs.write((const char*) description, descrLen);
	ofs.write((const char*) &priority, sizeof(priority));
	ofs.write((const char*) &status, sizeof(status));
	ofs.write((const char*) &duration, sizeof(duration));

	return true;
}

bool Task::readFromFile(std::ifstream& ifs)
{
	if (!ifs.is_open() || ifs.peek() == EOF)
	{
		return false;
	}

	remove();

	int descrLen = 0;;
	ifs.read((char*) &descrLen, sizeof(descrLen));

	ifs.read((char*) description, descrLen);
	description[descrLen] = '\0';

	ifs.read((char*) &priority, sizeof(priority));
	ifs.read((char*) &status, sizeof(status));
	ifs.read((char*) &duration, sizeof(duration));

	return true;
}
