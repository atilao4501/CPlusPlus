#ifndef TESTAHASH_H
#define TESTAHASH_H
#include <hash.h>

class testaHash
{
    hash objeto;
public:
    testaHash(int tamanho);
    void principal();
    void insere();
    void remove();
    void consulta();
    void imprimeHash();
};

#endif // TESTAHASH_H
