#include <iostream>

using namespace std;

const int MAX_LEN = 100;

int countNonCapital(const char* str)
{
    if (str == nullptr) return -1;

    int i = 0;
    int count = 0;

    while (str[i++] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z') count++;
    }

    return count;
}

int countCapital(const char* str)
{
    if (str == nullptr) return -1;

    int i = 0;
    int count = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z') count++;
    }

    return count;
}

char* nonCapitalStr(const char* str)
{
    if (str == nullptr) return nullptr;

    int size = countNonCapital(str);
    char* nonCapital = new char[size + 1] {};
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            nonCapital[index] = str[i];
            index++;
        }
    }

    return nonCapital;
}

int main()
{
    char input[MAX_LEN];

    cin.getline(input, MAX_LEN, '\n');

    char* nonCapital = nonCapitalStr(input);

    delete[] nonCapital;
}