#ifndef MAGE_H
#define MAGE_H

class Mage
{
public:
    Mage();
    Mage(int, int, int, int, int, int, int, int = 100, int = 100);
    Mage(const Mage &);
    ~Mage();

    void fireball() const;
    void getStats() const;
    void getHealth() const;
    void setHealth(int);
    void setStrength(int);
    void setConstitution(int);
    void setDexterity(int);
    void setIntelligence(int);
    void setWisdom(int);
    void setCharisma(int);

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