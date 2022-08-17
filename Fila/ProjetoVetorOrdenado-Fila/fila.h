#ifndef FILA_H
#define FILA_H

#include <QString>

namespace afa{
class Fila
{
private:
    int tamanho;
    int *array;
    int iniciofila;
    int fimfila;
    int quantidadeDeElementos;
public:
    Fila(int tamanho);
    ~Fila();
    bool estaCheia() const;
    bool estaVazia() const;
    void inserir(int elemento);
    void retirar();
    int acessar() const;
    int getQuantidadeDeElementos() const;


};
}

#endif // FILA_H
