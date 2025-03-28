#include <iostream>
#include "Task.h"
#include "MonthlyPlanner.cpp"

struct Nigga
{
    //char x[0];
};

int main()
{
    /*Task task("UP Basics", 5, 60);
    Task task1("OOP Basics", 10, 120);

    Task task2 = task.compare(task2);
    
    std::cout << task2.getDescription();*/

    std::cout << sizeof(Nigga) << "\n";
    std::cout << alignof(Nigga);
}
