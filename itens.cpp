#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "itens.h"

Itens::Itens()
    : price(10), qtd(1), type("pocao")
{
}

Itens::Itens(int price, int qtd, std::string type)
{
    setPrice(price);
    setQtd(qtd);
    setType(type);
}

Itens::Itens(const Itens &other)
{
    this->price = other.price;
    this->qtd = other.qtd;
    this->type = other.type;
}

Itens::~Itens()
{
}

void Itens::setPrice(int price)
{
    if (price >= 0)
    {
        this->price = price;
        return;
    }
    std::cout << "Tentado ser safado, ne?\n";

    this->price = 0;
}

void Itens::getPrice()
{
    std::cout << "O item vale: " << price << std::endl;
}

void Itens::setQtd(int qtd)
{
    if (qtd >= 0)
    {
        this->qtd = qtd;
        return;
    }
    std::cout << "Tentado ser safado, ne?\n";

    this->qtd = 0;
}

void Itens::getQtd()
{
    std::cout << "Voce tem: " << qtd << " itens" << std::endl;
}

void Itens::setType(std::string type)
{
    if (type.length() > 16)
    {
        std::cout << "Nome maior que 16 caracteres nao permitido, tente novamente por favor\n ";
        return;
    }
    this->type = type;
}

void Itens::getType()
{
    std::cout << "O item eh do tipo: " << type << std::endl;
}
