#include <iostream>
#include <fstream>
#include <sstream>

int** createEmptyMatrix(int rows, int cols)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
}

void deleteMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

int fileSize(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		std::cerr << "Can't open file.";
		return -1;
	}

	int size = 0;
	ifs.seekg(std::ios::end);

	size = ifs.tellg();
	ifs.seekg(std::ios::beg);

	return size;
}

int** readMatrixFromFile(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		std::cerr << "open't";
		return nullptr;
	}

	const int lineSize = 1024;
	char* s;
	char buff[lineSize];

	while (!ifs.eof())
	{

	}
}

int main()
{
	std::ifstream ifs("fst.txt");
}