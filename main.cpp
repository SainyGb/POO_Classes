#include <iostream>

#include "class.h"
#include "rpg.cpp"

int main()
{
    int strength = 10;
    int constitution = 13;
    int dexterity = 11;
    int intelligence = 15;
    int wisdom = 14;
    int charisma = 10;
    int health = 23;

    std::cout << "Usando Mage no main\n";

    Mage magelvl9;
    Mage magelvl3(strength, constitution, dexterity, intelligence, wisdom, charisma, health);
    Mage othermagelvl3(magelvl3);

    std::cout << "Magelvl9\n\n";
    magelvl9.getStats();
    magelvl9.getHealth();

    std::cout << "\nMagelvl3\n\n";
    magelvl3.getStats();
    magelvl3.getHealth();

    std::cout << "\nOtherMagelvl3\n\n";
    std::cout << "OtherMagelvl1 e uma copia do Magelvl3\n\n";
    othermagelvl3.getStats();
    othermagelvl3.getHealth();
    return 0;
}