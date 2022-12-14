#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "itens.h"

Itens::Itens()
    : price(10), qtd(1), type("pocao") //, invSize(10), invPtr(0), nextInv(0)
{
    invSize = 10;
    invPtr = 0;
    nextInv = 0;
}

Itens::Itens(int price, int qtd, std::string type)
{
    setPrice(price);
    setQtd(qtd);
    setType(type);
    desativarRaro();
    invSize = 10;
    invPtr = 0;
    nextInv = 0;
}

Itens::Itens(const Itens &other)
{
    this->price = other.price;
    this->qtd = other.qtd;
    this->type = other.type;

    this->invSize = other.invSize;
    this->nextInv = other.nextInv;
    this->invPtr = new std::string[this->invSize];
    for (int i = 0; i < nextInv; i++)
        this->invPtr[i] = other.invPtr[i];
}

Itens::~Itens()
{
    delete[] invPtr;
}

void Itens::getRaro() const
{
    std::cout << "Raro: " << raro << '\n';
}

void Itens::ativarRaro()
{
    raro = true;
}

void Itens::desativarRaro()
{
    raro = false;
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

void Itens::adicionarInv(const std::string &item)
{
    if (nextInv == 0)
    {
        invPtr = new std::string[invSize];
        invPtr[nextInv++] = item;
        return;
    }

    if (nextInv < invSize)
    {
        invPtr[nextInv++] = item;
        return;
    }

    if (invSize == 0)
    {
        invSize = 1;
        invPtr = new std::string[invSize];
        invPtr[nextInv++] = item;
        return;
    }

    std::cout << "Limite de inventario de itens alcancado.\n";
}

void Itens::printInv() const
{
    for (int i = 0; i < nextInv; i++)
        std::cout << invPtr[i] << '\n';
}

// void Itens::operator=(const Itens &item)
// {
//     price = item.price;
//     type = item.type;
// }

// void Itens::operator==(const Itens &item)
// {
//     if (price == item.price)
//     {
//         std::cout << "\nO atributo price eh igual\n";
//     }
//     else
//     {
//         std::cout << "O atributo price eh diferente\n";
//     }

//     if (type == item.type)
//     {
//         std::cout << "O atributo type eh igual\n";
//     }
//     else
//     {
//         std::cout << "O atributo type eh diferente\n";
//     }
// }

// void Itens::operator!=(const Itens &item)
// {
//     if (price != item.price)
//     {
//         std::cout << "\nO atributo price eh diferente\n";
//     }
//     else
//     {
//         std::cout << "\nO atributo price eh igual\n";
//     }
//     if (type != item.type)
//     {
//         std::cout << "O atributo type eh diferente\n";
//     }
//     else
//     {
//         std::cout << "O atributo type eh igual\n";
//     }
// }

// Itens Itens::operator!()
// {
//     raro = !raro;
//     return Itens(raro);
// }
