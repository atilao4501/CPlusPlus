
#define ORDENADOR_H
#include <pilha.h>


namespace afa{

class ordenador
{
private:
    int tamanhoVetor;
    int *vetor;
    int *vetorOrdenado;

public:
    ordenador(int tamanhoVetor);
    ~ordenador();
    void criarVetor();
    void ordenarVetor();
    QString getVetor() const;
    QString getVetorOrdenado() const;

};

}
