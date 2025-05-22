#pragma once
#include "Directory.h"

class Directory;
//const char* pathExample = "/home/file1.txt"
class FileSystemEntity
{
private:
	char* path;
	char* name;
	FileSystemEntity* parent; // entity because the system can have only 1 file

	void freeMem();
	void copyFrom(const FileSystemEntity& other);
public:
	FileSystemEntity(const char* path, const char* name);
	FileSystemEntity(const FileSystemEntity* parent, const char* name);
	FileSystemEntity(const FileSystemEntity* other);
	FileSystemEntity& operator=(const FileSystemEntity& other);
	~FileSystemEntity();

	//Връща размера на файла
	virtual int getSize() const = 0;
	//Връща абсолютния път на файла
	char* getName() const;
	//Връща името на папката, в която се намира
	Directory* getParent();
	//Търси файл/папка и връша nullptr ако не го намери
	virtual FileSystemEntity* find(const char* path) const = 0;
};