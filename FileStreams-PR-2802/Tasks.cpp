#include <iostream>
#include <fstream>

using namespace std;

// saves sum and multiplication of numbers in file
void saveToFile(int num1, int num2, int num3, const char* fileName)
{
	ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		cerr << "Failed opening file.\n";
		return;
	}

	int sum = num1 + num2 + num3;
	int mult = num1 * num2 * num3;
}

void readFromFile(ifstream& ifs)
{

}

int main()
{
	const char* fileName = "result.txt";
	// ifstream ifs(fileName);

	saveToFile(4, 5, 6, fileName);
}