#include <fstream>
#include <iostream>

int main()
{
	// Open file, write something, then read that
	// Особености -> при бинарни: за ifs.read -> аргумент 1 е char*, 2 дължината
	// подаваме аргумент 1 с & когато не е масив или указател, защото искаме паметта за промяна
	// ofs.write иска const char* за аргумент 1
	// при fstream, ако четем и искаме да пишем, първо flush за да запазим промените от буфера
	//  
#pragma region Method 1 - ifs/ofs

	std::ofstream ofs("file.txt", std::ios::binary | std::ios::app);

	const int len = 6;
	char str[len] = "Hello";

	if (!ofs.is_open())
	{
		std::cerr << "coultndopenfile";
		return 0;
	}

	ofs.write(reinterpret_cast<const char*>(&len), sizeof(len));
	ofs.write((const char*) str, len);

	ofs.close();

	std::ifstream ifs("file.txt", std::ios::binary);

	if (!ifs.is_open())
	{
		std::cerr << "coultndopenfile";
		return 0;
	}

	int len = 0;
	ifs.read((char*)&len, sizeof(len));

	char* str = new char[len + 1];
	ifs.read((char*)str, len);
	str[len] = '\0';



	ifs.close();

#pragma endregion
#pragma region Method 2 - fstream

	std::fstream fs("file.txt", std::ios::binary | std::ios::app | std::ios::in | std::ios::out);
	
	
#pragma endregion

}