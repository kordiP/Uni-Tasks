#include <iostream>
#include <fstream>

int main()
{
    std::fstream file("output.txt", std::ios::in | std::ios::out | std::ios::ate);

    file << "abc";
    file.flush();
    char curChar;
    file.seekg(0);
    while (file.get(curChar)) {
        if (curChar == 'b') {
            file.seekp(-1, std::ios::cur);
            file.put('t');
            file.flush();
        }
    }
    file.close();

    return 0;
}
