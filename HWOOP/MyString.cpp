#include "MyString.h"

void MyString::freeMem()
{
    delete[] str;
    str = nullptr;
}

void MyString::copyFrom(const MyString& other)
{
    size = other.size;
    str = new char[size + 1];
    strcpy_s(str, size, other.str);
    str[size] = '\0';
}

MyString::MyString() :str(nullptr), size(0) {}

MyString::MyString(const char* strn)
{
    if (strn == nullptr)
    {
        throw std::invalid_argument("Cannot create string with nullptr.");
    }

    size = strlen(strn);
    str = new char[size + 1];
    strcpy_s(str, size + 1, strn);
    str[size] = '\0';
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        freeMem();
        copyFrom(other);
    }

    return *this;
}

MyString::~MyString()
{
    freeMem();
}

const char& MyString::operator[](int index) const
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index not in range.");
    }

    return str[index];
}

char& MyString::operator[](int index)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index not in range.");
    }

    return str[index];
}

MyString& MyString::operator+=(const MyString& mstr)
{
    int finalSize = size + mstr.size;
    MyString tmp(*this);

    size = finalSize;
    str = new char[size + 1];

    strcpy_s(str, size + 1, tmp.str);
    strcat_s(str, size + 1, mstr.str);
    str[size] = '\0';

    return *this;
}

bool MyString::operator==(const MyString& mstr) const
{
    if (size != mstr.size || strcmp(str, mstr.str) != 0)
    {
        return false;
    }

    return true;
}

bool MyString::operator!=(const MyString& mstr) const
{
    return !(*this == mstr);
}

bool MyString::operator<(const MyString& mstr) const
{
    if (size > mstr.size || strcmp(str, mstr.str) > 0)
    {
        return false;
    }

    return true;
}

bool MyString::operator>(const MyString& mstr) const
{
    return mstr < *this;
}

bool MyString::operator>=(const MyString& mstr) const
{
    return !(*this > mstr);
}

bool MyString::operator<=(const MyString& mstr) const
{
    return !(*this < mstr);
}

MyString& MyString::doubleToString(double num) const
{
    MyString result;

    long long intPart = (long long)(num);
    double fracPart = num - intPart;

    if (intPart == 0) {
        result = result + '0';
    }
    else {
        MyString intStr;
        while (intPart > 0) {
            intStr = (char)('0' + (intPart % 10)) + intStr;
            intPart /= 10;
        }
        result += intStr;
    }

    result += ".";

    for (int i = 0; i < 2; ++i) {
        fracPart *= 10;
        int digit = (int)(fracPart);
        result = result + (char)('0' + digit);
        fracPart -= digit;
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& mstr)
{
    os << mstr.str;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& mstr)
{
    const int bSize = 1024;
    char buff[bSize];
    
    is >> buff;
    delete[] mstr.str;

    mstr.size = strlen(buff);
    mstr.str = new char[mstr.size + 1];
    strcpy_s(mstr.str, (mstr.size) + 1, buff);
    mstr.str[mstr.size] = '\0';

    return is;
}

std::istream& getline(std::istream& is, MyString& mstr)
{
    const int bSize = 1024;
    char buff[bSize];

    is.getline(buff, bSize);
    delete[] mstr.str;

    mstr.size = strlen(buff);
    mstr.str = new char[mstr.size + 1];
    strcpy_s(mstr.str, mstr.size + 1, buff);

    return is;
}

MyString operator+(const MyString& lhs, char sym)
{
    size_t newLen = lhs.size + 1;
    char* newData = new char[newLen + 1];

    for (size_t i = 0; i < lhs.size; i++)
        newData[i] = lhs.str[i];

    newData[newLen - 1] = sym;
    newData[newLen] = '\0';

    MyString result(newData);
    delete[] newData;
    return result;
}

MyString operator+(char sym, const MyString& lhs)
{
    size_t newLen = lhs.size + 1;
    char* newData = new char[newLen + 1];

    newData[0] = sym;
    for (size_t i = 1; i < newLen; i++)
        newData[i] = lhs.str[i - 1];

    newData[newLen] = '\0';

    MyString result(newData);
    delete[] newData;
    return result;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString fin(lhs);
    fin += rhs;
    return rhs;
}
