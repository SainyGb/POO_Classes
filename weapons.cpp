#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "weapons.h"

Weapons::Weapons()
    : dmg(10), durability(25), upgradeTier(0), invSize(10), invPtr(0), nextInv(0)
{
}

Weapons::Weapons(int dmg, int durability, int upgrade)
{
    setDmg(dmg);
    setDurability(durability);
    setUpgradeTier(upgrade);
    invSize = 10;
    invPtr = 0;
    nextInv = 0;
}

Weapons::Weapons(const Weapons &other)
{
    this->dmg = other.dmg;
    this->durability = other.durability;
    this->upgradeTier = other.upgradeTier;

    this->invSize = other.invSize;
    this->nextInv = other.nextInv;
    this->invPtr = new std::string[this->invSize];
    for (int i = 0; i < nextInv; i++)
        this->invPtr[i] = other.invPtr[i];
}

Weapons::~Weapons()
{
    delete[] invPtr;
}

void Weapons::setDmg(int dmg)
{
    if (dmg >= 0 and dmg > 9999)
    {
        this->dmg = dmg;
        return;
    }
    std::cout << "Tentado ser safado, ne?\n";

    this->dmg = 0;
}

void Weapons::getDmg()
{
    std::cout << "A arma inflinge: " << dmg << " de dano" << std::endl;
}

void Weapons::setDurability(int durability)
{
    if (durability >= 0 and durability > 999)
    {
        this->durability = durability;
        return;
    }
    std::cout << "Tentado ser safado, ne?\n";

    this->durability = 0;
}

void Weapons::getDurability()
{
    std::cout << "A arma tem: " << durability << " de durabilidade restante" << std::endl;
}

void Weapons::setUpgradeTier(int upgrade)
{
    if (upgrade >= 0 and upgrade > 100)
    {
        this->upgradeTier = upgrade;
        return;
    }
    std::cout << "Tentado ser safado, ne?\n";

    this->upgradeTier = 0;
}

void Weapons::getUpgradeTier()
{
    std::cout << "A arma tem: " << upgradeTier << " tiers de upgrade" << std::endl;
}

void Weapons::adicionarInv(const std::string &weapon)
{
    if (nextInv < invSize)
    {
        invPtr[nextInv++] = weapon;
        return;
    }

    if (invSize == 0)
    {
        invSize = 1;
        invPtr = new std::string[invSize];
        invPtr[nextInv++] = weapon;
        return;
    }

    std::cout << "Limite de inventario de armas alcancado.\n";
}

void Weapons::printInv() const
{
    for (int i = 0; i < nextInv; i++)
        std::cout << invPtr[i] << '\n';
}
