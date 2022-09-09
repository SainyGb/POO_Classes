#include <iostream>
#include <random>

#include "class.h"

Mage::Mage()
:strength = 8, constitution = 15, dexterity = 12, intelligence = 16, wisdom = 16, charisma = 11, health = 16
{
    std::cout << "Inicializando Mage no constructor da forma minimalista.\n";
}

Mage:Mage(int strength = 8, int constitution = 15, int dexterity = 12, int intelligence = 16, int wisdom = 16, int charisma = 11, int health = 16)
{
    std::cout << "Inicializando Mage no constructor da forma 'tradicional'.\n";
    
}

Mage::~Mage()
{
}

void Mage::getStats() const
{
    std::cout << "Strength: " << strength << '\n';
    std::cout << "Durability: " << constitution << '\n';
    std::cout << "Dexterity: " << dexterity << '\n';
    std::cout << "Intelligence: " << intelligence << '\n';
    std::cout << "Wisdom: " << wisdom << '\n';
    std::cout << "Charisma: " << charisma << '\n';
}

void Mage::fireball() const
{
    std::random_device rd;                       // obtain a random number from hardware
    std::mt19937 gen(rd());                      // seed the generator
    std::uniform_int_distribution<> distr(1, 6); // define the range

    int dmg = 0;
    for (int i = 0; i < 8; i++)
    {
        dmg += distr(gen);
    }

    std::cout << "Your fireball did: " << dmg << "!!!";
}

void Mage::setHealth(int health)
{
    if (health >= 0)
    {
        this->health = health;
        return;
    }

    this->health = 0;
}


void Mage::getHealth() const
{
    std::cout << "Health: " << health << '\n';
}