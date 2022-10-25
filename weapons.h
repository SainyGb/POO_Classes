#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>

// FALTA FAZER:
//  ADICIONA O ATRIBUTO NOME TANTO NAS WEAPONS QUANTO NOS ITENS E USA O NOME PRA ADICIONAR NO INVENTARIO
//  Colocar dentro de uma de suas classes a classe Date.
//  Fazer a sobrecarga para cada classe dos operadores =, ==, ≠, ! e << (friend).

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

    void getRaro() const;
    void ativarRaro();
    void desativarRaro();

    void getDmg();
    void getDurability();
    void getUpgradeTier();

    void adicionarInv(const std::string &);
    void printInv() const;

    void operator=(const Weapons &);

    void operator==(const Weapons &);

    void operator!=(const Weapons &);

    Weapons operator!();

private:
    int dmg;
    int durability;
    int upgradeTier;
    bool raro;

    std::string *invPtr;
    int invSize;
    int nextInv;
    // place holder for date
};

#endif