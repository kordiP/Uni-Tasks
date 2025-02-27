#include <iostream>

using namespace std;

void strconcat(char* str, char* str2)
{

}

void sequence(char* result, int numWanted)
{
	if (result == nullptr)
	{
		return;
	}

	int strIndex = 0;

	for (int i = 0; i < numWanted; i++)
	{
		const int curConvSize = 3;
		char curRes[curConvSize];

		if (result[strIndex] == '0')
		{
			curRes[0] = '0';
			curRes[1] = '1';
			curRes[2] = '\0';
		}
		else
		{
			curRes[0] = '1';
			curRes[1] = '0';
			curRes[2] = '\0';
		}

		while (strIndex < curConvSize)
		{
			result[strIndex];
		}

		
	}
}

int main()
{
	int input;
	cin >> input;

	if (input > 7)
	{
		return 0;
	}

	int size = pow(2, input) + 1;

	char* result = new char[size];
	result[0] = '0';

	sequence(result, input);

	for (int i = 0; i < size; i++)
	{
		cout << result[i];
	}
}