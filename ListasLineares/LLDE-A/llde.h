#ifndef LLDE_H
#define LLDE_H

#include <no.h>

namespace afa{
class LLDE
{
private:
    int quantidadeElementos;
    NO *inicio;
    NO *fim;


public:
    LLDE();
    ~LLDE();

   int getQuantidadeElementos();
   bool estaVazia() const;

   void inserirInicio(int elemento);
   int retirarInicio();

   void inserirFim(int elemento);
   int retirarFim();

   int retirarPos(int pos);
   int operator[](int pos) const;
   void inserirPos(int pos, int elemento);
   void inserirOrdenadoCrescente(int elemento);
   void inserirOrdenadoDecrescente(int elemento);

};
}
#endif // LLDE_H
