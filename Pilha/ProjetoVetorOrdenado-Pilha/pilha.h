#ifndef PILHA_H
#define PILHA_H
#include <QString>

namespace afa{
class Pilha
{

    //Atributos
private:

    int tamanho;
    int topo;
    int *array;

public:

    Pilha(int tamanho);
    ~Pilha();

    bool estaCheia() const;
    bool estaVazia() const;

    void inserir(int elemento);
    void retirar();

    int acessar() const;
    int quantidadeDeElementos() const;
    //metodo para facilitar o trabalho da torre
    QString getPilha() const;

};

}
#endif // PILHA_H
