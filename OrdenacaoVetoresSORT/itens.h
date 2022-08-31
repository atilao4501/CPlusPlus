#ifndef ITENS_H
#define ITENS_H
#include <iostream>
#include <string>


class Itens
{
private:
    int chave;
    std::string nome;

public:
    Itens(int y);

    int getChave() const;
    void setChave(int newChave);
    const std::string &getNome() const;
    void setNome(const std::string &newNome);
};

#endif // ITENS_H
