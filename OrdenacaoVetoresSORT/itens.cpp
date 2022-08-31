#include "itens.h"

Itens::Itens(int y)
{
    setChave(y);
}

int Itens::getChave() const
{
    return chave;
}

void Itens::setChave(int newChave)
{
    chave = newChave;
}

const std::string &Itens::getNome() const
{
    return nome;
}

void Itens::setNome(const std::string &newNome)
{
    nome = newNome;
}


