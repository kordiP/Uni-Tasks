#include <iostream>

class E
{
    char c;
    double d;
    int* ptr;
};

int main()
{
    std::cout << sizeof(E) << "\n" << alignof(E);
}
