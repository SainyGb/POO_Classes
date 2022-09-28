#ifndef MAGE_H
#define MAGE_H

#include <string>
#include <vector>

class Mage
{
public:
    Mage();
    Mage(int, int, int, int, int, int, int, int = 100, int = 100);
    Mage(const Mage &);
    ~Mage();

    void adicionarMagia();
    void printarMagia();
    void printarNiveisPoder();

    void setCharName(const std::string &);
    void getCharName();

    void getConcentracao() const;
    void ativarConcentracao();
    void desativarConcentracao();

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

    static int getNumChars() { return numChars; }
    static void getNumMaxChars();

private:
    int strength;
    int constitution;
    int dexterity;
    int intelligence;
    int wisdom;
    int charisma;
    int health;
    int numMagias;

    std::string charname;

    bool concentracao;

    const int MAXHEALTH;
    const int MAXMANA;

    std::vector<std::string *> magias;

    static int numChars;

    static const int NUMEROMAXCHARS = 5;
    static const int NUMEROMAXMAGIA = 5;

    static const int NIVEISDEPODER = 6;
    static const std::string PODER[NIVEISDEPODER];
};

#endif // SWORD_H