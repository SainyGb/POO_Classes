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
    void printInv() const;

    void getRaro() const;
    void ativarRaro();
    void desativarRaro();

    void operator=(const Itens &);

    void operator==(const Itens &);

    void operator!=(const Itens &);

    Itens operator!();

private:
    int price;
    int qtd;
    std::string type;
    bool raro;
    // place holder for date

    std::string *invPtr;
    int invSize;
    int nextInv;
};

#endif