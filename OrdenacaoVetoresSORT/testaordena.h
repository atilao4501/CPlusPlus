#ifndef TESTAORDENA_H
#define TESTAORDENA_H
#include <ordena.h>


class testaordena
{
private:
    int tamanho;
    Itens **VET;
public:
    testaordena();
    ~testaordena();
    void preencherVetor(Itens **vetor, int tam);
    Itens **getVET() const;
    Itens **ordenarVetor(Itens **vetor, int tam, int modo);
    int getTamanho();

};

#endif // TESTAORDENA_H
