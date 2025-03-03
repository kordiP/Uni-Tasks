// File streams

#include <iostream>
#include <fstream>

using namespace std; // not the best practice, but anyways allowed

int getFileSize(const char* fileName)
{
	if (fileName == nullptr)
	{
		return -1;
	}

	ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		return -2;
	}

	int originalPos = ifs.tellg();
	ifs.seekg(0, ios::end);

	int fileSize = ifs.tellg();

	ifs.seekg(originalPos);
	ifs.close();

	return fileSize;
}

// !!!!! //
int getFileSize(ifstream& ifs) // never skip &, because a copy of the stream will make 2 and they break
{
	if (!ifs.is_open())
	{
		return -1;
	}

	int originalPos = ifs.tellg();
	ifs.seekg(0, ios::end); // goes to the end of the file AFTER the last symbol

	int fileSize = ifs.tellg();

	ifs.seekg(originalPos); // if we skip this line, we changed the stream to point to the last byte. WE DO NOT WANT THAT. we leave the stream unchanged with this line
	return fileSize; // return the file size, because we positioned the pointer at the byte after the last one in the file.
}

