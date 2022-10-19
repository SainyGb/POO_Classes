#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>

class Weapons
{
public:
    Weapons();
    Weapons(int, int, int);
    Weapons(const Weapons &);
    ~Weapons();

    void setDmg(int);
    void setDurability(int);
    void setUpgradeTier(int);

    void getDmg();
    void getDurability();
    void getUpgradeTier();

    void adicionarInv(const std::string &);
    void printInv() const;

private:
    int dmg;
    int durability;
    int upgradeTier;

    std::string *invPtr;
    int invSize;
    int nextInv;
    // place holder for date
};

#endif