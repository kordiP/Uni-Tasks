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
    strcpy_s(str, size + 1, other.str);
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

int MyString::asciiToInt() const
{
    int result = 0;
    for (int i = 0; i < size; ++i) {
        char c = str[i];
        if (c >= '0' && c <= '9') {
            result = result * 10 + (c - '0');
        }
        else {
            throw std::invalid_argument("Something went wrong.");
        }
    }
    return result;
}

double MyString::asciiToDouble() const
{
    int i = 0;
    int len = size;
    double result = 0.0;
    bool isNegative = false;

    // Skip leading spaces
    while (i < len && str[i] == ' ') {
        i++;
    }

    // Handle sign
    if (i < len && (str[i] == '-' || str[i] == '+')) {
        isNegative = (str[i] == '-');
        i++;
    }

    // Integer part
    while (i < len && str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    // Fractional part
    if (i < len && str[i] == '.') {
        i++;
        double divisor = 10.0;
        while (i < len && str[i] >= '0' && str[i] <= '9') {
            result += (str[i] - '0') / divisor;
            divisor *= 10.0;
            i++;
        }
    }

    return isNegative ? -result : result;
}

size_t MyString::find(char symbol, size_t skip) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == symbol)
        {
            if (skip > 0)
            {
                skip--;
                continue;
            }
            return i;
        }
    }
    return -1;
}

MyString MyString::substring(size_t start, size_t length) const
{
    if (start >= this->size)
        return MyString();

    if (start + length > this->size || length == 0)
        length = this->size - start;

    MyString result;
    result.size = length;
    result.str = new char[length + 1];

    for (size_t i = 0; i < length; ++i)
    {
        result.str[i] = this->str[start + i];
    }
    result.str[length] = '\0';

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
