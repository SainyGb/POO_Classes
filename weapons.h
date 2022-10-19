#ifndef WEAPONS_H
#define WEAPONS_H

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

private:
    int dmg;
    int durability;
    int upgradeTier;
    // place holder for date
};

#endif