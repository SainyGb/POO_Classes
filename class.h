#ifndef MAGE_H
#define MAGE_H

class Mage
{
public:
    Mage(int = 8, int = 15, int = 12, int = 16, int = 16, int = 11, int = 16);
    ~Mage();

    void fireball() const;
    void getStats() const;
    void getHealth() const;
    void setHealth(int=10)
    void setStrength(int=10);
    void setConstitution(int=10);
    void setDexterity(int=10);
    void setIntelligence(int=10);
    void setWisdom(int=10);
    void setCharisma(int=10);
    void setHealth(int=10);

private:
    int strength;
    int constitution;
    int dexterity;
    int intelligence;
    int wisdom;
    int charisma;
    int health;
    const int MAXHEALTH;
    const int MAXMANA;
};

#endif // SWORD_H