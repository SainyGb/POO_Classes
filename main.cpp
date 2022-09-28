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
    const Mage MAGELVL3(strength, constitution, dexterity, intelligence, wisdom, charisma, health);
    Mage othermagelvl3(MAGELVL3);
    Mage *magelvl9Ptr = &magelvl9;
    Mage *magePrt = new Mage();

    std::cout << "num de chars: " << magelvl9.getNumChars() << '\n';
    std::cout << "num de chars: " << MAGELVL3.getNumChars() << '\n';

    std::cout
        << "Magelvl9\n\n";
    magelvl9.getStats();
    magelvl9.getHealth();
    magelvl9.setCharName("Egildo");
    magelvl9.getCharName();
    magelvl9.ativarConcentracao();
    magelvl9.getConcentracao();
    magelvl9.getNumMaxChars();

    std::cout << "Adicionando Magias\n";
    magelvl9Ptr->adicionarMagia();
    magelvl9Ptr->printarMagia();

    std::cout
        << "\nMudando os valores de magePtr\n";
    magePrt->setHealth(999);
    magePrt->getHealth();
    magePrt->setStrength(999);
    magePrt->getStats();
    delete magePrt;

    std::cout
        << "\nMagelvl3\n\n";
    MAGELVL3.getHealth();
    MAGELVL3.getStats();
    MAGELVL3.getConcentracao();

    std::cout << "\nOtherMagelvl3\n\n";
    std::cout << "OtherMagelvl3 e uma copia do Magelvl3\n\n";
    othermagelvl3.getStats();
    othermagelvl3.getHealth();

    std::cout << "Mostrando os niveis de poder\n";
    magePrt->printarNiveisPoder();
    return 0;
}