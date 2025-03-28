#include "StringManipulator.h"
#include <iostream>
#include <fstream>

const int CONV_VAL = 'a' - 'A';

// free memory !!!!!
void StringManipulator::remove()
{
    delete[] str;
    str = nullptr;
}

// copy data from other object !!!!!
void StringManipulator::copy(const StringManipulator& other)
{
    setString(other.str);
    errorState = other.errorState;
}

// getter example !!!!!
const char* StringManipulator::getString() const
{
    if (errorState == true)
    {
        return nullptr;
    }

    return str;
}

bool StringManipulator::getState() const
{
    return errorState;
}

int StringManipulator::getStringLength() const
{
    if (errorState == true)
    {
        return -1;
    }

    return (int)strlen(str);
}

StringManipulator& StringManipulator::resetState()
{
    errorState = false;
    return *this;
}

// setter example + method chaining !!!!!
StringManipulator& StringManipulator::setString(const char* str)
{
    if (str == nullptr || this->errorState == true)
    {
        std::cerr << "Invalid.";

        return *this;
    }

    size_t size = strlen(str);
    this->str = new char[size + 1];
    strcpy_s(this->str, size, str);

    return *this;
}

// ~Big 4

StringManipulator::StringManipulator()
{
    setString("");
    resetState();
}

StringManipulator::StringManipulator(const char* str)
{
    setString(str);
    resetState();
}

StringManipulator::StringManipulator(const char* str, unsigned multTimes)
{
    resetState();

    if (str == nullptr)
    {
        std::cerr << "Invalid string.";
        return;
    }

    size_t size = strlen(str) * multTimes + 1;
    this->str = new char[size];

    // in documentation, strcat needs an initialized string, this is the shortest way 
    this->str[0] = '\0';

    for (size_t i = 0; i < multTimes; i++)
    {
        // strcat adds the \0 at the end
        strcat_s(this->str, size, str);
    }
}

// cpy ctor
StringManipulator::StringManipulator(const StringManipulator& other)
{
    copy(other);
}

// =
StringManipulator& StringManipulator::operator=(const StringManipulator& other)
{
    if (this != &other)
    {
        remove();
        copy(other);
    }

    return *this;
}

// destr
StringManipulator::~StringManipulator()
{
    remove();
}

// ~

const StringManipulator& StringManipulator::printString() const
{
    if (strlen(str) <= 0 || errorState == true)
    {
        std::cerr << "Error in string.";

        return *this;
    }

    std::cout << str << std::endl;

    return *this;
}

StringManipulator& StringManipulator::concatString(StringManipulator& other)
{
    if (errorState == true || other.errorState == true)
    {
        std::cerr << "Invalid string.";
        return *this;
    }

    size_t newSize = strlen(str) + strlen(other.str) + 1;
    char* newStr = new char[newSize];

    strcpy_s(newStr, newSize, str);
    delete[] str;
    strcat_s(newStr, newSize, other.str);

    str = newStr;
    str[newSize] = '\0';

    return *this;
}

StringManipulator& StringManipulator::insertString(const char* str, int position)
{
    if (errorState == true || str == nullptr)
    {
        std::cerr << "Error in string.";
        return *this;
    }

    size_t oldLen = strlen(this->str);
    size_t insertLen = strlen(str);

    // meaning no input
    if (position == -1 || position > oldLen)
    {
        // change pos to \0
        position = (int)oldLen;
    }

    size_t newSize = oldLen + insertLen + 1;
    char* newStr = new char[newSize];
    
    // copy the first part, last int is for maxsize of copy
    strncpy_s(newStr, newSize, this->str, position);

    // skip the first part we just wrote to, so we don't overwrite
    strcpy_s(newStr + position, newSize - position, str);

    // skip the first+second part and same for the SRC
    strcpy_s(newStr + position + insertLen, newSize - (position + insertLen), this->str + position);

    return *this;
}

StringManipulator& StringManipulator::replaceSymbol(char toRep, char repWith, int replaceCount)
{
    if (errorState == 1)
    {
        std::cerr << "Error in string.";
        return *this;
    }

    if (replaceCount == -1)
    {
        replaceCount = (int)strlen(str) + 1;
    }

    int id = 0;

    while (str[id] != '\0' && replaceCount > 0)
    {
        if (str[id] == toRep)
        {
            str[id] = repWith;
            replaceCount--;
        }
        id++;
    }

    return *this;
}

StringManipulator& StringManipulator::deleteStrAfterIndex(int numberOfChars, unsigned position)
{
    if (errorState == 1)
    {
        std::cerr << "Error in string.";
        return *this;
    }

    int len = (int)strlen(str);

    if (position > len || numberOfChars <= 0)
    {
        return *this;
    }

    int toRemove = std::min((int)numberOfChars, (int)(len - position));
    int pos = position;

    int newSize = len - toRemove + 1;
    char* newStr = new char[newSize];

    strncpy_s(newStr, newSize, str, pos);
    strcpy_s(newStr + pos, newSize - pos, str + pos + toRemove);

    delete[] str;
    str = newStr;

    return *this;
}

StringManipulator StringManipulator::upperCase()
{
    if (errorState == true)
    {
        return NULL;
    }

    StringManipulator strMan = *this;

    int id = 0;
    while (strMan.str[id] != '\0')
    {
        if (strMan.str[id] >= 'a' && strMan.str[id] <= 'z')
        {
            strMan.str[id] -= CONV_VAL;
        }
    }

    return *this;
}

StringManipulator StringManipulator::lowerCase()
{
    if (errorState == true)
    {
        return NULL;
    }

    StringManipulator strMan = *this;

    int id = 0;
    while (strMan.str[id] != '\0')
    {
        if (strMan.str[id] >= 'a' && strMan.str[id] <= 'z')
        {
            strMan.str[id] += CONV_VAL;
        }
    }

    return *this;
}

const StringManipulator& StringManipulator::saveToFile(const char* fileName) const
{
    // saving
    // first save the strlen, then str then it's errorstate / if error == true, do not save. app mode
    return *this;
}

StringManipulator& StringManipulator::readFromFile(const char* fileName)
{
    // reading
    // first read will be size of str, then read the str then the errorstate, then save to object
    return *this;
}
