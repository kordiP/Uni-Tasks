#include <iostream>

int calculateNumberOfDigits(int number) {
	int counter = 1;

	while (number / 10 != 0)
	{
		counter++;
		number /= 10;
	}

	return counter;
}

int reverseNumber(int number)
{
	int result = 0;
	int digitCount = calculateNumberOfDigits(number);

	while (digitCount > 0)
	{
		result += (number % 10) * pow(10, digitCount - 1);
		digitCount--;
		number /= 10;
	}

	return result;
}

char isSufix(int numberPart, int numberFull)
{
	int numberOfDigitsInSmaller = calculateNumberOfDigits(numberPart);

	if (numberFull % (int)pow(10, numberOfDigitsInSmaller) == numberPart)
	{
		return 't';
	}

	return 'f';
}

char isPrefix(int numberPart, int numberFull)
{
	int numberOfDigitsInSmaller = calculateNumberOfDigits(numberPart);
	int numberOfDigitsInBigger = calculateNumberOfDigits(numberFull);

	if (numberFull / (int)pow(10, numberOfDigitsInBigger - numberOfDigitsInSmaller) == numberPart)
	{
		return 't';
	}

	return 'f';
}

char isInfix(int numberPart, int numberFull) // 12345, 12
{
	int digitCountPart = calculateNumberOfDigits(numberPart);
	while (numberFull >= 10) {
		int lastNDigits = numberFull % (int)pow(10, digitCountPart);

		if (lastNDigits == numberPart) {
			return 't';
		}

		numberFull /= 10;
	}
	return 'f';
}

char isPrime(int number) 
{
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return 'f';
		}
	}

	return 't';
}

int powerOfIntegers(int number, int power) 
{
	int result = 1;

	for (int i = 0; i < power; i++)
	{
		result *= number;
	}
	
	return result;
}

int logOfIntsFloored(int base, int number)
{
	int result = 0;

	while (number > 1)
	{
		number /= base;
		result++;
	}

	return result;	
}

char areTwoPointsInTheCircle(int pointAX, int pointAY, int pointBX, int pointBY)
{
	int radiusASquared = pointAX * pointAX + pointAY * pointAY;
	int radiusBSquared = pointBX * pointBX + pointBY * pointBY;

	if (radiusASquared == radiusBSquared)
	{
		return 't';
	}

	return 'f';
}

int main()
{
	
}


/* 1>

    int number;
    std::cin >> number;

	for (int i = number; i >= 1; i--)
	{
		bool oneIsNonPrime = false;

		int firstResult = 6 * i - 1;
		int secondResult = 6 * i + 1;

		for (int j = 2; j <= firstResult - 1; j++) // iznasqme for-a na funkciq za proverka na prime
		{
			if (firstResult % j == 0)
			{
				oneIsNonPrime = true;
			}
		}

		for (int j = 2; j <= secondResult - 1; j++)
		{
			if (secondResult % j == 0)
			{
				oneIsNonPrime = true;
			}
		}

		if (!oneIsNonPrime)
		{
			std::cout << firstResult << " " << secondResult << std::endl;
		}
	}

*/

// 2)
	/*int inputNum;
	std::cin >> inputNum;

	int reversedNum = reverseNumber(inputNum);

	std::cout << reversedNum;*/

	// 3)
	/*int inputNum;
	std::cin >> inputNum;

	int reversedNum = reverseNumber(inputNum);

	if (reversedNum == inputNum)
	{
		std::cout << "Das ist sehr true.";
	}
	else
	{
		std::cout << "Das ist ee false.";
	}*/
