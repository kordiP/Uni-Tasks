#include <iostream>

class Document
{
private:
	char* title;
	char* content;
	int id;

	void copy(const Document& other)
	{
		int length = strlen(other.content);
		this->content = new char[length + 1];
		strcpy_s(this->content, length, other.content);
		this->content[length] = '\0';

		int lengthC = strlen(other.title);
		this->title = new char[lengthC + 1];
		strcpy_s(this->title, lengthC, other.title);
		this->title[lengthC] = '\0';

		this->id = other.id;
	}
	void remove()
	{
		delete[] content;
		content = nullptr;

		delete[] title;
		title = nullptr;
	}
public:
	Document(const char* title, const char* content, int id)
	{
		// qsno
	}

	Document(const Document& other)
	{
		copy(other);
	}

	Document& operator=(const Document& other)
	{
		if (&other != this)
		{
			remove();
			copy(other);
		}

		return *this;
	}

	~Document()
	{

	}


};