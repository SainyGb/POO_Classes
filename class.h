#ifndef MAGE_H
#define MAGE_H

class Mage
{
private:
    int strength;
    int constitution;
    int dexterity;
    int intelligence;
    int wisdom;
    int charisma;

public:
    Mage(/* args */);
    ~Mage();

    void fireball() const;
    void getStats() const;
};

#endif // SWORD_H