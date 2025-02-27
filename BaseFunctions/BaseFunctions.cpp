#include <iostream>

using namespace std;

#pragma region NumberFunctions
// Returns the number of digits in number.
int calculateNumberOfDigits(int number)
{
	if (number == 0)
	{
		return 1;
	}

	number = abs(number); 

	int digitCounter = 0;

	while (number > 0)
	{
		digitCounter++;
		number /= 10;
	}

	return digitCounter;
}

// Returns digit at index.
int getNumberAt(int fromNumber, int indexNumber)
{
	int bigNumberLength = calculateNumberOfDigits(fromNumber);
	int differenceForCalc = bigNumberLength - indexNumber;

	fromNumber /= powerOfIntegers(10, differenceForCalc);

	return fromNumber % 10;
}

// Returns reversed number.
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

// Returns true if the first number is a sufix of the second.
bool isSufix(int numberPart, int numberFull)
{
	int numberOfDigitsInSmaller = calculateNumberOfDigits(numberPart);

	if (numberFull % (int)pow(10, numberOfDigitsInSmaller) == numberPart)
	{
		return true;
	}

	return false;
}

// Returns true if the first number is a prefix of the second.
bool isPrefix(int numberPart, int numberFull)
{
	int numberOfDigitsInSmaller = calculateNumberOfDigits(numberPart);
	int numberOfDigitsInBigger = calculateNumberOfDigits(numberFull);

	if (numberFull / (int)pow(10, numberOfDigitsInBigger - numberOfDigitsInSmaller) == numberPart)
	{
		return true;
	}

	return false;
}

// Returns true if the first number is in the second.
bool isInfix(int numberPart, int numberFull)
{
	int digitCountPart = calculateNumberOfDigits(numberPart);
	while (numberFull >= 10) {
		int lastNDigits = numberFull % (int)pow(10, digitCountPart);

		if (lastNDigits == numberPart) {
			return true;
		}

		numberFull /= 10;
	}
	return false;
}

// Returns true if number is prime.
bool isPrime(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

// Returns the first number powered to the second.
int powerOfIntegers(int number, int power)
{
	int result = 1;

	for (int i = 0; i < power; i++)
	{
		result *= number;
	}

	return result;
}

// Returns the log of ints, floored.
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

#pragma endregion

#pragma region ArrayFunctions
// Input array.
void inputArray(int array[], int size)
{
	if (array == nullptr || size <= 0)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		std::cin >> array[i];
	}
}

// Outputs array.
void printArray(int array[], int size)
{
	if (array == nullptr || size <= 0)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
}

// Returns index of searched value in array (linear search).
int linearSearchArray(int array[], int size, int targetVal)
{
	if (array == nullptr || size <= 0)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] == targetVal)
		{
			return i;
		}
	}

	return -1;
}

// Reverses given array.
void reverseArray(int array[], int size)
{
	if (array == nullptr || size <= 0)
	{
		return;
	}

	for (int i = 0; i < size / 2; i++)
	{
		int tmp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = tmp;
	}
}

// Sorts array using bubble method.
void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

// Returns index of searched value in array (binary search).
int binarySearch(int array[], int size, int targetVal)
{
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2; 
		int currElement = array[mid];

		if (currElement == targetVal) 
		{
			return mid; 
		}
		else if (currElement < targetVal) 
		{
			low = mid + 1; 
		}
		else 
		{
			high = mid - 1; 
		}
	}

	return -1;
}

// Returns minimal value in array.
int minInArray(int array[], int size)
{
	int smallestNumber = array[0];

	for (int i = 1; i < size; i++)
	{
		if (array[i] < smallestNumber)
		{
			smallestNumber = array[i];
		}
	}

	return smallestNumber;
}

#pragma endregion

#pragma region MatrixFunctions
// Returns the minimal value of the matrix.
int smallestElement(int** matrix, int matrixSizeRows, int matrixSizeCols)
{
	if (matrix == nullptr || matrixSizeCols <= 0 || matrixSizeRows <= 0)
	{
		return -1;
	}

	int smallest = matrix[0][0];

	for (int i = 0; i < matrixSizeRows; i++)
	{
		for (int j = 0; j < matrixSizeCols; j++)
		{
			if (smallest > matrix[i][j]) smallest = matrix[i][j];
		}
	}

	return smallest;
}

// Outputs given matrix.
void printMatrix(int** matrix, int matrixSizeRows, int matrixSizeCols)
{
	if (matrix == nullptr || matrixSizeCols <= 0 || matrixSizeRows <= 0)
	{
		return;
	}

	for (int i = 0; i < matrixSizeRows; i++)
	{
		for (int j = 0; j < matrixSizeCols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

// Input matrix.
void inputMatrix(int** matrix, int matrixSizeRows, int matrixSizeCols)
{
	for (int i = 0; i < matrixSizeRows; i++)
	{
		for (int j = 0; j < matrixSizeCols; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
#pragma endregion

#pragma region BoolOperations

bool isEven(int number)
{
	return (number & 1) == 0;
}

int powerOfTwo(int power) 
{
	return 1 << power;
}

int clearBit(int number, int position) 
{
	int mask = ~(1 << (position - 1));  
	return number & mask;
}

int returnBitVaue(int number, int position) 
{
	int mask = 1 << (position - 1);  
	return (number & mask) >> (position - 1); 
}

int giveBitValue(int number, int newValue, int position) 
{
	int mask = 1 << (position - 1); 
	return (number | mask);
}

bool isPartOfNumber(int number, int part)
{
	do
	{
		if ((number & part) == part)
		{
			return true;
		}
		number >>= 1;

	} while (number != 0);

	return false;
}

int numberOfOnes(int number)
{
	int counter = 0;
	int mask = 1;

	while (number > 0)
	{
		if ((number & mask) != 0)
		{
			counter++;
		}

		number >>= 1;
	}

	return counter;
}

int flipLastOne(int number)
{
	int mask = 1;
	int position = 0;

	if (number == 0)
	{
		return 0;
	}

	while (true)
	{
		position++;

		if ((number & mask) != 0)
		{
			clearBit(number, position);
			break;
		}

		mask <<= 1;
	}
}

// Returns the lone element in array with all pairs except 1 nnumber.
int findNonDuplicate(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		array[i + 1] ^= array[i];
	}

	return array[size - 1];
}

#pragma endregion

#pragma region StringFunctions

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

	while (source1[counter] == source2[counter] && source2[counter] == source3[counter])
	{
		longestPrefixReturn[counter] = *source1;
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

#pragma endregion


int main()
{

}

