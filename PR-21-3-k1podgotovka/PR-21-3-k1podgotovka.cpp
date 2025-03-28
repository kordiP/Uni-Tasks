#include <iostream>

int main()
{
    
}

struct A
{
    int number;
    char arr[5];
    char* ptr;

    int f1() const {
        return number;
    }

    char* const f2() {
        return arr;
    }

    const char* f3() {
        return arr;
    }

    /*char* const f4() const {
        return arr;
    }*/

    const char* f5() const {
        return arr;
    }

    char* f6() const {
        return ptr;
    }

    const char* f7() const {
        return ptr;
    }

   /* int* f8() const {
        return &number;
    }*/

    const int* f9() const {
        return &number;
    }
};