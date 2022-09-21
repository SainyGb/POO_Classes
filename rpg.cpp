#include <iostream>
#include <random>
#include <stdexcept>

#include "class.h"

int Mage::numChars = 0;

int Mage::getNumMaxChars()
{
    std::cout << NUMEROMAXCHARS << '\n';
}

Mage::Mage()
    : strength(8), constitution(15), dexterity(12), intelligence(16), wisdom(16), charisma(11), health(16), MAXHEALTH(100), MAXMANA(100)
{
    std::cout << "Inicializando Mage no constructor da forma minimalista.\n";
    this->numChars++;
}

Mage::Mage(int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int health, int MAXHEALTH, int MAXMANA)
    : MAXHEALTH(MAXHEALTH), MAXMANA(MAXMANA)
{
    std::cout << "Inicializando Mage no constructor com os sets.\n";
    setStrength(strength);
    setConstitution(constitution);
    setDexterity(dexterity);
    setIntelligence(intelligence);
    setWisdom(wisdom);
    setCharisma(charisma);
    setHealth(health);
    desativarConcentracao();

    this->numChars++;
}

Mage::Mage(const Mage &other)
    : MAXHEALTH(other.MAXHEALTH), MAXMANA(other.MAXMANA)
{
    this->health = other.health;
    this->strength = other.strength;
    this->constitution = other.constitution;
    this->charisma = other.charisma;
    this->wisdom = other.wisdom;
    this->dexterity = other.dexterity;
    this->intelligence = other.intelligence;

    this->numChars++;
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

void Mage::adicionarMagia(const std::string &magiaNova)
{
    // O vector alunos pode crescer dinamicamente
    // Mas só pode aceitar numAlunos

    if (magias.size() < this->NUMEROMAXMAGIA)
    {
        magias.push_back(new std::string(magiaNova));
        return;
    }

    std::cout << "Nao é possivel adicionar " << magiaNova << 'ao livro de feitiços.' << " O livro não suporta essa quantidade de magias.\n";
}

void Mage::getConcentracao() const
{
    std::cout << "Estado de Concentracao: " << concentracao << '\n';
}

void Mage::ativarConcentracao()
{
    concentracao = true;
}

void Mage::desativarConcentracao()
{
    concentracao = false;
}

void Mage::setCharName(std::string name)
{
    if (name.length() > 16)
    {
        std::cout << "Nome maior que 16 caracteres, tente novamente por favor\n ";
        return;
    }
    this->charname = name;
}

void Mage::getCharName()
{
    std::cout << "O nome do seu personagem eh: " << charname << '\n';
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

void Mage::setStrength(int strength)
{
    if (strength >= 0)
    {
        this->strength = strength;
        return;
    }

    this->strength = 0;
}

void Mage::setConstitution(int constitution)
{
    if (constitution >= 0)
    {
        this->constitution = constitution;
        return;
    }

    this->constitution = 0;
}

void Mage::setDexterity(int dexterity)
{
    if (dexterity >= 0)
    {
        this->dexterity = dexterity;
        return;
    }

    this->dexterity = 0;
}

void Mage::setIntelligence(int intelligence)
{
    if (intelligence >= 0)
    {
        this->intelligence = intelligence;
        return;
    }

    this->intelligence = 0;
}

void Mage::setWisdom(int wisdom)
{
    if (wisdom >= 0)
    {
        this->wisdom = wisdom;
        return;
    }

    this->wisdom = 0;
}

void Mage::setCharisma(int charisma)
{
    if (charisma >= 0)
    {
        this->charisma = charisma;
        return;
    }

    this->charisma = 0;
}

void Mage::getHealth() const
{
    std::cout << "Health: " << health << '\n';
}