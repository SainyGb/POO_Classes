#include <iostream>
#include <random>
#include <stdexcept>
#include <map>

#include "rpg.h"

#include "weapons.h"
#include "itens.h"

int Mage::numChars = 0;
const std::string Mage::PODER[NIVEISDEPODER] = {"F", "D", "C", "B", "A", "S"};

void Mage::getNumMaxChars()
{
    std::cout << NUMEROMAXCHARS << '\n';
}

Mage::Mage(const Data &dataOut)
    : strength(8), constitution(15), dexterity(12), intelligence(16), wisdom(16), charisma(11), health(16), MAXHEALTH(100), MAXMANA(100), dataAtual(dataOut)
{
    std::cout << "Inicializando Mage no constructor da forma minimalista.\n";
    this->numChars++;
    invSize = 5;
    invPtr = 0;
    nextInv = 0;
    minionsPtr = 0;
    nextMinion = 0;
}

Mage::Mage(int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int health, int MAXHEALTH, int MAXMANA)
    : MAXHEALTH(MAXHEALTH), MAXMANA(MAXMANA) //, dataNascimento()
{
    std::cout << "Inicializando Mage no constructor com os sets.\n";
    setStrength(strength);
    setConstitution(constitution);
    setDexterity(dexterity);
    setIntelligence(intelligence);
    setWisdom(wisdom);
    setCharisma(charisma);
    setHealth(health);
    desativarConcentracao();
    invSize = 5;
    invPtr = 0;
    nextInv = 0;
    minionsPtr = 0;
    nextMinion = 0;

    this->numChars++;
}

Mage::Mage(const Mage &other)
    : MAXHEALTH(other.MAXHEALTH), MAXMANA(other.MAXMANA)
{

    this->health = other.health;
    this->strength = other.strength;
    this->constitution = other.constitution;
    this->charisma = other.charisma;
    this->wisdom = other.wisdom;
    this->dexterity = other.dexterity;
    this->intelligence = other.intelligence;

    this->invSize = other.invSize;
    this->nextInv = other.nextInv;
    this->invPtr = new std::string[this->invSize];
    for (int i = 0; i < nextInv; i++)
        this->invPtr[i] = other.invPtr[i];

    this->inimigos.resize(other.inimigos.size());
    for (auto i = 0; i < other.inimigos.size(); i++)
        this->inimigos[i] = other.inimigos[i];

    this->nextMinion = other.nextMinion;
    this->minionsPtr = new std::string[MAXNUMMINIOS];
    for (int i = 0; i < nextMinion; i++)
        this->minionsPtr[i] = other.minionsPtr[i];

    this->numChars++;
}

Mage::~Mage()
{
    delete[] invPtr;
    delete[] minionsPtr;
    for (auto i = 0; i < inimigos.size(); i++)
        delete this->inimigos[i];
    inimigos.clear();
    this->numChars--;
}

void Mage::operator=(const Mage &mage)
{
    health = mage.health;
    strength = mage.strength;
}

void Mage::operator==(const Mage &mage)
{
    if (health == mage.health)
    {
        std::cout << "\nO atributo health eh igual\n";
    }
    else
    {
        std::cout << "O atributo health eh diferente\n";
    }

    if (strength == mage.strength)
    {
        std::cout << "O atributo strength eh igual\n";
    }
    else
    {
        std::cout << "O atributo strength eh diferente\n";
    }
}

void Mage::operator!=(const Mage &mage)
{
    if (health != mage.health)
    {
        std::cout << "\nO atributo health eh diferente\n";
    }
    else
    {
        std::cout << "\nO atributo health eh igual\n";
    }
    if (strength != mage.strength)
    {
        std::cout << "O atributo strength eh diferente\n";
    }
    else
    {
        std::cout << "O atributo strength eh igual\n";
    }
}

Mage Mage::operator!()
{
    concentracao = !concentracao;
    return Mage(concentracao);
}

void Mage::mostrarData() const
{
    std::cout << "A data atual eh: ";
    dataAtual.print();
    std::cout << '\n';
}

Mage::Pet Mage::invocarPet()
{
    Pet pet;
    std::string animal_s;
    int tamanho_s;
    int peso_s;
    std::string nome_s;

    std::cout << "Qual o animal que deseja invocar?\n";
    std::cin >> animal_s;
    pet.animal = animal_s;

    std::cout << "Qual o tamanho dele?\n";
    std::cin >> tamanho_s;
    pet.tamanho = tamanho_s;

    std::cout << "Qual o peso dele? \n";
    std::cin >> peso_s;
    pet.peso = peso_s;

    std::cout << "Qual será o nome dele? \n";
    std::cin >> nome_s;
    pet.nome = nome_s;

    return pet;
}

void Mage::getPet(const Pet &animal)
{
    std::cout << "\nPrintando o pet\n";
    std::cout << "animal: " << animal.animal << std::endl;
    std::cout << "tamanho: " << animal.tamanho << std::endl;
    std::cout << "peso: " << animal.peso << std::endl;
    std::cout << "nome: " << animal.nome << std::endl;
}

void Mage::getStats() const
{
    std::cout << "Strength: " << strength << '\n';
    std::cout << "Durability: " << constitution << '\n';
    std::cout << "Dexterity: " << dexterity << '\n';
    std::cout << "Intelligence: " << intelligence << '\n';
    std::cout << "Wisdom: " << wisdom << '\n';
    std::cout << "Charisma: " << charisma << '\n';
}

void Mage::adicionarMagia()
{
    while (true)
    {
        int desejo = -1;
        std::string magiaNova = "";
        std::cout << "Deseja adicionar uma magia ?\n";
        // while (desejo != 0 or desejo != 1)
        // {
        std::cout << "0 - Nao\n";
        std::cout << "1 - Sim\n";
        std::cin >> desejo;
        // if (desejo != 0 or desejo != 1)
        // {
        //     std::cout << "Opcao invalida, tente novamente. \n";
        // }
        // }
        if (desejo == 0)
        {
            return;
        }
        if (magias.size() < this->NUMEROMAXMAGIA)
        {
            std::cout << "Nome da Magia: ";
            std::cin >> magiaNova;
            magias.push_back(std::string(magiaNova));
            std::cout << "Magia " << magiaNova << " adicionado(a) com sucesso'\n'";
        }
        else
        {
            std::cout << "Nao é possivel adicionar " << magiaNova << "ao livro de feitiços."
                      << " O livro não suporta essa quantidade de magias.\n";
            return;
        }
    }
}

std::string Mage::escolherInimigosRandom()
{

    mapaInimigos[0] = "Zumbi";
    mapaInimigos[1] = "Goblin";
    mapaInimigos[2] = "Elfo";
    mapaInimigos[3] = "Beholder";

    std::random_device rd;                       // obtain a random number from hardware
    std::mt19937 gen(rd());                      // seed the generator
    std::uniform_int_distribution<> distr(0, 3); // define the range

    return mapaInimigos[distr(gen)];
}

void Mage::gerarMinions(const std::string &novoMinion)
{

    if (nextMinion == 0)
    {
        minionsPtr = new std::string[MAXNUMMINIOS];
        minionsPtr[nextMinion++] = novoMinion;
        return;
    }
    if (nextMinion < MAXNUMMINIOS)
    {
        minionsPtr[nextMinion++] = novoMinion;
        return;
    }
    std::cout << "Limite de minions alcancado\n";
}

void Mage::printMinions() const
{
    for (int i = 0; i < nextMinion; i++)
        std::cout << minionsPtr[i] << '\n';
}

void Mage::gerarInimigos(const std::string &novoInimigo)
{
    // std::string novoInimigo = escolherInimigos();
    if (inimigos.size() < MAXNUMINIMIGOS)
    {
        inimigos.push_back(new std::string(novoInimigo));
        std::cout << novoInimigo << " Adicionado.\n";
        return;
    }
    std::cout << "Numero maximo de inimigos alcançado.\n";
}

void Mage::printInimigos() const
{
    for (int i = 0; i < inimigos.size(); i++)
        std::cout << *inimigos[i] << std::endl;
}

void Mage::adicionarInv(const std::string &item)
{
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

    adicionarSlotInv(item);
}

void Mage::adicionarSlotInv(std::string item)
{
    int desejo = -1;
    std::cout << "Limite de inv atingido, deseja adicionar mais slots? (apenas 100 de cash)\n";
    std::cout << "0 - Nao\n";
    std::cout << "1 - Sim\n";

    std::cin >> desejo;

    if (desejo == 0)
    {
        return;
    }

    std::string *invTemp = new std::string[invSize];
    for (int i = 0; i < nextInv; i++)
        invTemp[i] = invPtr[i];

    delete[] invPtr;
    invSize += int(ceil(invSize * 0.5)); // Aumenta a memória em 50%

    invPtr = new std::string[invSize];
    for (int i = 0; i < nextInv; i++)
        invPtr[i] = invTemp[i];
    invPtr[nextInv++] = item;

    delete[] invTemp;
    std::cout << "Slots adicionados com sucesso\n";
}

void Mage::printInv() const
{
    for (int i = 0; i < nextInv; i++)
        std::cout << invPtr[i] << '\n';
}

void Mage::printarMagia()
{
    int cont = 0;
    if (this->magias.size() <= 0)
    {
        std::cout << "Nao tem nenhuma magia para mostrar\n";
        return;
    }
    //     for (auto magia : this->magias)
    //     {
    //         std::cout << "Magia " << cont << " - " << magia << "\n";
    //         cont++;
    //     }
    for (int i = 0; i < magias.size(); i++)
    {
        std::cout << "Magia " << cont << " - " << magias[i] << "\n";
        cont++;
    }
}

void Mage::printarNiveisPoder()
{
    for (int i = 0; i < NIVEISDEPODER; i++)
        std::cout << PODER[i] << '\n';
}

void Mage::getConcentracao() const
{
    std::cout << "Estado de Concentracao: " << concentracao << '\n';
}

void Mage::ativarConcentracao()
{
    concentracao = true;
}

void Mage::desativarConcentracao()
{
    concentracao = false;
}

void Mage::setCharName(const std::string &name)
{
    if (name.length() > 16)
    {
        std::cout << "Nome maior que 16 caracteres, tente novamente por favor\n ";
        return;
    }
    this->charname = name;
}

void Mage::getCharName()
{
    std::cout << "O nome do seu personagem eh: " << charname << '\n';
}

void Mage::fireball() const
{
    std::random_device rd;                       // obtain a random number from hardware
    std::mt19937 gen(rd());                      // seed the generator
    std::uniform_int_distribution<> distr(1, 6); // define the range

    int dmg = 0;
    for (int i = 0; i < 8; i++)
    {
        dmg += distr(gen);
    }

    std::cout << "Your fireball did: " << dmg << "!!!";
}

void Mage::setHealth(int health)
{
    if (health >= 0 and health < MAXHEALTH)
    {
        this->health = health;
        return;
    }
    std::cout << "Tentado ser safado, ne?\n";

    this->health = 0;
}

void Mage::setStrength(int strength)
{
    if (strength >= 0)
    {
        this->strength = strength;
        return;
    }

    this->strength = 0;
}

void Mage::setConstitution(int constitution)
{
    if (constitution >= 0)
    {
        this->constitution = constitution;
        return;
    }

    this->constitution = 0;
}

void Mage::setDexterity(int dexterity)
{
    if (dexterity >= 0)
    {
        this->dexterity = dexterity;
        return;
    }

    this->dexterity = 0;
}

void Mage::setIntelligence(int intelligence)
{
    if (intelligence >= 0)
    {
        this->intelligence = intelligence;
        return;
    }

    this->intelligence = 0;
}

void Mage::setWisdom(int wisdom)
{
    if (wisdom >= 0)
    {
        this->wisdom = wisdom;
        return;
    }

    this->wisdom = 0;
}

void Mage::setCharisma(int charisma)
{
    if (charisma >= 0)
    {
        this->charisma = charisma;
        return;
    }

    this->charisma = 0;
}

void Mage::getHealth() const
{
    std::cout << "Health: " << health << '\n';
}

std::ostream &operator<<(std::ostream &out, const Mage &criacao)
{
    out << "Seu mago foi criado em: ";
    criacao.dataAtual.print();
    out << '\n';
    out << "Strength: " << criacao.strength << '\n';
    out << "Durability: " << criacao.constitution << '\n';
    out << "Dexterity: " << criacao.dexterity << '\n';
    out << "Intelligence: " << criacao.intelligence << '\n';
    out << "Wisdom: " << criacao.wisdom << '\n';
    out << "Charisma: " << criacao.charisma << '\n';
    out << "Health: " << criacao.health << '\n';
    out << "O nome do seu personagem eh: " << criacao.charname << '\n';
    out << "Estado de Concentracao: " << criacao.concentracao << '\n';
    return out;
}