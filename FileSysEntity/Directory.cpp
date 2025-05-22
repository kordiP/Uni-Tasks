#include "Directory.h"

Directory::Directory(Directory* parentDir, const char* name) : FileSystemEntity(getName(), name)
{
	
}

Directory::Directory(const char* name) : FileSystemEntity(getName(), name)
{
	
}

void Directory::addEntity(const FileSystemEntity* entity)
{
	
}

void Directory::removeEntity(const FileSystemEntity* entity)
{
}
