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

    mstr.size = strlen(buff);
    strcpy_s(mstr.str, mstr.size + 1, buff);
    mstr.str[mstr.size] = '\0';

    return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString fin(lhs);
    fin += rhs;
    return rhs;
}
