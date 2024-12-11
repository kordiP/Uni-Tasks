#include <iostream>

const int MAX_SIZE = 1024;

void stringCopy(const char* source, char* destination)
{
	if (source == nullptr || destination == nullptr)
	{
		return;
	}

	while (*source != '\0')
	{
		*destination++ = *source++;
	}

	*destination = '\0';
}

bool stringContains(const char* source, char symbol)
{
	if (source == nullptr)
	{
		std::cout << "error";
		return 0;
	}

	while (*source != '\0')
	{
		if (*source++ == symbol)
		{
			return 1;
		}
	}

	return 0;
}

int stringLength(const char* source)
{
	int counter = 0;

	if (source == nullptr)
	{
		return -1;
	}

	while (*source != '\0')
	{
		counter++;
		source++;
	}
	
	return counter;
}

int stringCompare(const char* source1, const char* source2)
{
	if (source1 == nullptr || source2 == nullptr)
	{
		std::cout << "Err";
		return -10;
	}

	while (*source1 != '\0')
	{
		if (*source1 > *source2)
		{
			return 1;
		}
		else if (*source1 < *source2)
		{
			return -1;
		}
		else
		{
			source1++;
			source2++;
		}
	}

	return 0;
}

void replace(char* source, char toChange, char onEven, char onOdd)
{
	if (source == nullptr)
	{
		std::cout << "Error";
		return;
	}

	bool placeEven = true;

	while (*source != '\0')
	{
		if (*source == toChange)
		{
			if (placeEven)
			{
				*source = onEven;				
			}
			else
			{
				*source = onOdd;
			}
			placeEven = !placeEven;
		}
		source++;
	}
}

int symbolAppearanceCount(const char* source, char symbol)
{
	int appearanceCounter = 0;

	if (source == nullptr)
	{
		std::cout << "Nullptr";
		return -1;
	}

	while (*source != '\0')
	{
		if (*source == symbol)
		{
			appearanceCounter++;
		}
		source++;
	}

	return appearanceCounter;
}

void longestPrefix(const char* source1, const char* source2, const char* source3, char* longestPrefixReturn)
{
	if (source1 == nullptr || source2 == nullptr || source3 == nullptr || longestPrefixReturn == nullptr)
	{
		std::cout << "Error";
		return;
	}

	int counter = 0;

	while (*source1 == *source2 && *source2 == *source3) // also can use source[counter] and not iterate the sources
	{
		longestPrefixReturn[counter] = *source1;
		source1++;
		source2++;
		source3++;
		counter++;
	}
}

void removeDuplicateSymbols(const char* source, char* result)
{
	int resultCounter = 0;
	if (source == nullptr)
	{
		return;
	}

	while (*source != '\0')
	{
		if (!stringContains(result, *source))
		{
			result[resultCounter] = *source;
			resultCounter++;
		}
		source++;
	}
}

int main()
{ 
	char buff[] = "cbacdcbc";
	char buff2[MAX_SIZE] = { };

	removeDuplicateSymbols(buff, buff2);

	std::cout << buff2;
}
