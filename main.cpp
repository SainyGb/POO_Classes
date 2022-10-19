#include <iostream>

#include "rpg.h"
#include "rpg.cpp"

#include "Data.h"
#include "Data.cpp"

#include "weapons.h"
#include "weapons.cpp"

#include "itens.h"
#include "itens.cpp"

int main()
{
    int strength = 10;
    int constitution = 13;
    int dexterity = 11;
    int intelligence = 15;
    int wisdom = 14;
    int charisma = 10;
    int health = 23;

    std::cout << "Usando Mage no main\n";

    Mage magelvl9;
    const Mage MAGELVL3(strength, constitution, dexterity, intelligence, wisdom, charisma, health);
    Mage othermagelvl3(MAGELVL3);
    Mage *magelvl9Ptr = &magelvl9;
    Mage *magePrt = new Mage();

    std::vector<std::string *> inimigos;
    for (int i = 0; i <= 6; i++)
        inimigos.push_back(new std::string(magelvl9.escolherInimigosRandom()));

    std::cout << "num de chars: " << magelvl9.getNumChars() << '\n';
    std::cout << "num de chars: " << MAGELVL3.getNumChars() << '\n';

    std::cout
        << "\nMagelvl9\n\n";
    // magelvl9.getStats();
    // magelvl9.getHealth();
    // magelvl9.setCharName("Egildo");
    // magelvl9.getCharName();
    // magelvl9.ativarConcentracao();
    // magelvl9.getConcentracao();
    std::cout << magelvl9;

    // std::cout
    //     << "Adicionando Magias p/ magelvl9 utilizando ponteiro\n";
    // magelvl9Ptr->adicionarMagia();
    // magelvl9Ptr->printarMagia();

    std::cout
        << "\nMagelvl3\n\n";
    MAGELVL3.getHealth();
    MAGELVL3.getStats();
    MAGELVL3.getConcentracao();

    std::cout << "\nUsando operador = para copiar atributos do mage lvl3 para o lvl9\n";
    magelvl9 = MAGELVL3;
    cout << magelvl9;

    std::cout << "\nUsando operador == para comparar atributos do mage lvl3 com o mage lvl9";
    magelvl9 == MAGELVL3;

    std::cout << "\nUsando operador != para comparar atributos do mage lvl3 com o mage lvl9";
    magelvl9 != MAGELVL3;

    std::cout << "\nUsando operador ! para negar a concentracao do mage lvl 9\n";
    std::cout << "Sem negar concentracao: ";
    magelvl9.getConcentracao();
    std::cout << "\nDepois de negar com o operador: ";
    !magelvl9;
    magelvl9.getConcentracao();

    std::cout
        << "\nOtherMagelvl3\n\n";
    std::cout << "OtherMagelvl3 e uma copia do Magelvl3\n\n";
    othermagelvl3.getStats();
    othermagelvl3.getHealth();

    std::cout
        << "\nMudando os valores de magePtr\n";
    magePrt->setHealth(999);
    magePrt->getHealth();
    magePrt->setStrength(999);
    magePrt->getStats();
    delete magePrt;

    std::cout << "\nCriando Pet\n";
    Mage::Pet pet = magelvl9.invocarPet();
    magelvl9.getPet(pet);

    std::cout << "Mostrando os niveis de poder\n";
    magePrt->printarNiveisPoder();

    std::cout << "Gerando inimigos: \n\n";
    for (int i = 0; i < inimigos.size(); i++)
    {
        magelvl9.gerarInimigos(*inimigos[i]);
    }

    std::cout << "Printando inimigos: \n\n";
    magelvl9.printInimigos();

    for (int i = 0; i < inimigos.size(); i++)
    {
        delete inimigos[i];
        inimigos.pop_back();
    }

    std::cout << "Adicionando itens no inventário\n";
    magelvl9.adicionarInv("Couro");
    magelvl9.adicionarInv("Carne de Zumbi");
    magelvl9.adicionarInv("adaga quebrada");
    magelvl9.adicionarInv("Couro");
    magelvl9.adicionarInv("Couro");
    magelvl9.adicionarInv("Couro");

    std::cout << "Mostrando Inventario: \n\n";
    magelvl9.printInv();

    std::cout << "Invocando minions\n\n";
    magelvl9.gerarMinions("Lobo da floresta");
    magelvl9.gerarMinions("Lobo da floresta");
    magelvl9.gerarMinions("Lobo da floresta");
    magelvl9.printMinions();

    return 0;
}