#ifndef MAGE_H
#define MAGE_H

class Mage
{
private:
    int strength, constitution, dexterity, intelligence, wisdom, charisma;

public:
    Mage(/* args */);
    ~Mage();

    void fireball() const;
    void printStats() const;
};

#endif // SWORD_H