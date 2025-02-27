#include <iostream>
#include <fstream>

// Task 1
struct Treasure
{
	char name[20];
	int x;
	int y;
};
void writeTreasure(const char* filePath)
{
	std::ofstream file(filePath, std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "Could not open file.";
		return;
	}

	Treasure treasures[] =
	{
		{ "GOLDGOLDGOLD", 1, 5 },
		{ "Diamon", 10, 3 },
		{ "Bronzey", 7, 4 },
	};

	for (int i = 0; i < 3; i++)
	{
		file.write((const char*)& treasures[i], sizeof(Treasure)); // const char* can be replaced by: reinterpret_cast<const char*>
	}

	file.close();
	
	std::cout << "Treasures saved.\n";
}
void readTreasure(const char* filePath)
{
	std::ifstream file(filePath, std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "Could not open file.";
		return;
	}

	Treasure resultT;

	while (file.read((char*)&resultT, sizeof(Treasure)))
	{
		std::cout << "Name: " << resultT.name << " coords: (" << resultT.x << ", " << resultT.y << ").\n";
	}

	file.close();
}

// Task 2
void readScroll(const char* filePath, const char* outPath)
{
	std::ifstream file(filePath);

	if (!file.is_open())
	{
		std::cerr << "Can not open.";
		return;
	}

	char line[256];
	char password[21];
	int passId = 0;

	while (file.getline(line, sizeof(line)))
	{
		std::cout << line << std::endl;

		for (int i = 0; line[i] != '\0'; i++)
		{
			if (line[i] >= '0' && line[i] <= '9' && passId <= 20)
			{
				password[passId++] = line[i];
			}
		}
	}

	file.close();

	password[passId] = '\0';

	std::ofstream binFile(outPath, std::ios::binary);

	if (!binFile.is_open())
	{
		std::cerr << "Can not open.";
		return;
	}

	binFile.write((const char*)password, sizeof(password));

	binFile.close();
}
void readPass(const char* filePath)
{
	std::ifstream file(filePath);

	if (!file.is_open())
	{
		std::cerr << "Can not open.";
		return;
	}

	char password[21];

	file.read((char*)password, sizeof(password));

	file.close();

	std::cout << "password: " << password;
}

int main()
{
	/*const char* filePath = "treasure.dat";
	writeTreasure(filePath);
	readTreasure(filePath);*/

	const char* inputPath = "scroll.txt";
	const char* outputPath = "password.txt";
	readScroll(inputPath, outputPath);
	readPass(outputPath);
}

