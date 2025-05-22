#include "SingleFile.h"

SingleFile::SingleFile(Directory* parentDir, const char* name, int size) : FileSystemEntity(parentDir, name)
{
	
}

SingleFile::SingleFile(const char* name, const char* size) : FileSystemEntity(getName(), name)
{

}

int SingleFile::getSize() const
{
	return size;
}

FileSystemEntity* SingleFile::find(const char* path) const
{
	return nullptr;
}