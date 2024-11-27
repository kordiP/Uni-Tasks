#include <iostream>

bool isEven(int number) // 0 & 1 -> 0; 1 & 1 -> 1; 0 & 0 -> 0; so 1010 & 0001 -> 0000
{
    return (number & 1) == 0;
}

int powerOfTwo(int power) // 0000000001 << 3 = 000000001000 OR 2^3 = 8
{
    return 1 << power;
}

int clearBit(int number, int position) // (15, 3) -> 1011
{
    int mask = ~(1 << (position - 1)); // 0001, bitshift left position times - 1 (2) -> 0100 then ~ -> 1011 and 1111 = 1011
    return number & mask;
}

int returnBitVaue(int number, int position) // (15, 3) -> 1
{
    int mask = 1 << (position - 1); // 0100
    return (number & mask) >> (position - 1); // result with mask >> position - 1
}

int giveBitValue(int number, int newValue, int position) // 1111, 0, 3 -> 1011
{
    int mask = 1 << (position - 1); // 0100
    return (number | mask);
}

int main()
{
    std::cout << returnBitVaue(2, 3);
}

