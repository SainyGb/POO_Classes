#include <iostream>

#include "class.h"
#include "rpg.cpp"

int main()
{
    std::cout << "Usando Mage no main\n";

    Mage magelvl9;
    magelvl9.printStats();
    magelvl9.fireball();

    return 0;
}