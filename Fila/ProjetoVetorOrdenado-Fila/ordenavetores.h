#ifndef ORDENAVETORES_H
#define ORDENAVETORES_H
#include <fila.h>


namespace afa{

class ordenavetores
{
private:
    int tamanhoVetor;
    int *vetor;
    int *vetorOrdenado;

public:
    ordenavetores(int tamanhoVetor);
    ~ordenavetores();
    void criarVetor();
    void ordenarVetor();
    QString getVetor() const;
    QString getVetorOrdenado() const;

};

}
#endif // ORDENAVETORES_H
