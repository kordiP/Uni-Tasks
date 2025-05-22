#include <iostream>
#include "SystemEngine.h"

int main()
{
    SystemEngine& se = SystemEngine::getInstance();
    se.run();
}
