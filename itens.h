#ifndef ITENS_H
#define ITENS_H

#include <string>

class Itens
{
public:
    Itens();
    Itens(int, int, std::string);
    Itens(const Itens &);
    ~Itens();

    void setPrice(int);
    void setQtd(int);
    void setType(std::string);

    void getPrice();
    void getQtd();
    void getType();

    void adicionarInv(const std::string &);
    void Itens::printInv() const;

private:
    int price;
    int qtd;
    std::string type;
    // place holder for date

    std::string *invPtr;
    int invSize;
    int nextInv;
};

#endif