#pragma once
#include "Directory.h"
#include "FileSystemEntity.h"

class SingleFile : public FileSystemEntity
{	
private:
	int size;
public:
	SingleFile(Directory* parentDir, const char* name, int size);
	SingleFile(const char* name, const char* size);
	int getSize() const override;
	FileSystemEntity* find(const char* path) const override;
};