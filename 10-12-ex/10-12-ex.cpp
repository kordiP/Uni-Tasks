#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int calculateNumberOfDigits(long number) {
	int counter = 1;

	while (number / 10 != 0)
	{
		counter++;
		number /= 10;
	}

	return counter;
}

int stringLength(char* source)
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

bool analyzeArr(int arr[], int length)
{
	int fixedElementsCount = 0;

	if (arr == nullptr || length <= 0)
	{
		cout << "Nullptr";
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == i)
		{
			fixedElementsCount++;
		}
	}

	if (fixedElementsCount >= 2)
	{
		return true;
	}

	return false;
}

int checkStr(char stringInput[])
{
	const int strLength = stringLength(stringInput);

	if (stringInput == nullptr || strLength < 2)
	{
		return -1;
	}

	int oddNumberOfAppearencesCounter = 0;

	for (int i = 0; i < strLength; i++)
	{
		int currSymbolAppearanceCounter = 0;
		char currSymbol = stringInput[i];

		for (int j = 0; j < strLength; j++)
		{
			if (stringInput[j] == currSymbol)
			{
				currSymbolAppearanceCounter++;
			}
		}

		if (currSymbolAppearanceCounter % 2 != 0)
		{
			oddNumberOfAppearencesCounter++;
		}
	}
	

	if (oddNumberOfAppearencesCounter > 1)
	{
		return 0;
	}

	return 1;
}

void convertNum(long &number)
{
	if (number >= -9 && number <= 9)
	{
		return;
	}

	int result = 0;
	int digitCount = calculateNumberOfDigits(number);

	while (digitCount > 0)
	{
		result += (number % 10) * pow(10, digitCount - 1);
		digitCount--;
		number /= 10;
	}

	number = result;
}

int checkTimeStr(char* time)
{
	const int correctTimeLength = 8;
	int timeLength = stringLength(time);

	const int size = 3;
	int numbers[size] = {};

	if (time == nullptr || timeLength != correctTimeLength)
	{
		return -1;
	}

	int counter = 0;

	while (*(time+1) != '\0') 
	{
		if (*time == '-')
		{
			return 0;
		}

		if (*time != ':' && *(time+1) != ':')
		{
			numbers[counter] = (*time - '0') * 10 + (*(time + 1) - '0');
		}
		else
		{
			counter++;
			time++;
		}

		time++;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (numbers[i] < 0)
		{
			return 0;
		}

		else if (numbers[i] >= 60)
		{
			return 0;
		}

		else if (i == 0 && numbers[i] >= 24)
		{
			return 0;
		}
	}

	return 1;
}

int numCalc(long num, int k, int l)
{
	int numLength = calculateNumberOfDigits(num);

	if (k < 0 || l < 0 || k >= numLength || l >= numLength)
	{
		return -1;
	}

	int result = 0;

	result += (int)(num / pow(10, numLength - k - 1)) % 10; // 6050 / 1000 = 6 % 10 = 6
	result += (int)(num / pow(10, numLength - l - 1)) % 10; // 6050 / 10 = 605 % 10 = 5

	return result;
}

bool doExist(char* symbols, char* word)
{
	int wordLength = stringLength(word);
	bool foundWord = false;

	while (*symbols != '\0')
	{
		if (*symbols == word[wordLength - 1])
		{
			int symbolsIndex = 0;
			for (int i = wordLength - 2; i >= 0; i--)
			{
				symbolsIndex++;

				if (word[i] == symbols[symbolsIndex])
				{
					foundWord = true;
				}
				else
				{
					foundWord = false;
					break;
				}
			}
		}

		symbols++;
	}

	return foundWord;
}

int main()
{
	char symbols[] = "frenigeword";
	char word[] = "drowe";
	cout << doExist(symbols, word);
}
