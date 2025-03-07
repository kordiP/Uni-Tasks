#include <iostream>
#include <fstream>

void replaceCharsInFile(const char* fileName, char toRep, char repWith) // only fstream
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cerr << "open't\n";
		return;
	}

	ifs.seekg(std::ios::end);

	int strSize = ifs.tellg();
	char* str = new char[strSize];

	ifs.seekg(std::ios::beg);

	char curCh = '.';
	int id = 0;
	while (!ifs.eof())
	{
		ifs >> curCh;	
		if (curCh == toRep)
		{
			str[id] = repWith;
		}
		else
		{
			str[id] = curCh; // ?
		}
		id++;
	}

	ifs.close();

	std::ofstream ofs(fileName);
	if (!ofs.is_open())
	{
		std::cerr << "open't\n";
		return;
	}

	ofs.write(str, strSize);

	ofs.close();
}

//int main()
//{
//	char toRep = 'g', repWith = '-';
//
//	replaceCharsInFile("replace.txt", toRep, repWith);
//}