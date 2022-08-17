#ifndef LLDE_H
#define LLDE_H

#include <notemplate.h>

namespace afa{

template<typename T>

class LLDE
{
private:
    int quantidadeElementos;
    NO<T> *inicio;
    NO<T> *fim;


public:
    LLDE();
    ~LLDE();

   int getQuantidadeElementos();
   bool estaVazia() const;

   void inserirInicio(T elemento);
   T retirarInicio();

   void inserirFim(T elemento);
   T retirarFim();

   T retirarPos(int pos);
   T operator[](int pos) const;

   void inserirPos(int pos, T elemento);

   void inserirOrdenadoCrescente(T elemento);
   void inserirOrdenadoDecrescente(T elemento);

};
template<typename T>
LLDE<T>::LLDE():
    quantidadeElementos(0),
    inicio(0),
    fim(0)
{
}

template<typename T>
LLDE<T>::~LLDE(){
    if (quantidadeElementos != 0){
        while (quantidadeElementos != 0){
            retirarInicio();
        }
    }
    if (inicio) delete inicio;
    if (fim) delete fim;
}

template<typename T>
bool LLDE<T>::estaVazia() const{

    return (quantidadeElementos==0);
}

template<typename T>
void LLDE<T>::inserirInicio(T elemento){

    try {
        NO<T> *novo = new NO(elemento);

        if (estaVazia()){
         quantidadeElementos++;
         inicio = fim = novo;
         return;
        }

        quantidadeElementos++;

        novo->setProximo(inicio);
        inicio->setAnterior(novo);
        inicio = novo;

    }  catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}

template<typename T>
T LLDE<T>::retirarInicio(){
    if (estaVazia()) throw QString("\nA lista esta vazia");
    if (quantidadeElementos == 1){
        T x = inicio->getDado();

        delete inicio;

        quantidadeElementos--;

        inicio = fim = 0;

        return x;
    }
        NO<T> *aux = inicio;

        inicio = aux->getProximo();
        inicio->setAnterior(0);

        quantidadeElementos--;

        T x = aux->getDado();

        delete aux;
        return x;

}

template<typename T>
int LLDE<T>::getQuantidadeElementos(){
    return quantidadeElementos;
}

template<typename T>
void LLDE<T>::inserirFim(T elemento){
    NO<T> *novo = new NO<T>(elemento);

    if(estaVazia()){
        inicio=fim=novo;
        quantidadeElementos++;
        return;
    }
    fim->setProximo(novo);
    novo->setAnterior(fim);
    fim = novo;
    quantidadeElementos++;
}

template<typename T>
T LLDE<T>::retirarFim(){
    if (estaVazia()) throw QString("Não é possivel retirar, a lista está vazia");

    T x = fim->getDado();

    if(quantidadeElementos == 1){
        x = retirarInicio();

        return x;
    }

    fim = fim->getAnterior();

    delete fim->getProximo();

    fim->setProximo(0);

    quantidadeElementos--;

    return x;

}

template<typename T>
T LLDE<T>::retirarPos(int pos){
    if (estaVazia()) { throw  QString ("a operação não é possível");
}
    if (pos >= quantidadeElementos || pos < 0){
        throw  QString ("a operação não é possível");
    }
    T x;

    if (pos == 0){
        x = retirarInicio();

        return x;
    }
    else if (pos == quantidadeElementos-1){
        x = retirarFim();

        return x;
    }
    else {
        NO<T> *paux = inicio;

        for (int aux = 0; aux < pos; aux++){
            paux = paux->getProximo();

        }

        x = paux->getDado();

        quantidadeElementos--;

        delete paux;

        return x;
    }

}

template<typename T>
void LLDE<T>::inserirPos(int pos, T elemento){
    if(pos < 0 || pos > quantidadeElementos) throw QString("Posicao fora do parametro - IQ");
    if(pos == quantidadeElementos){
        inserirFim(elemento);
        return;
    }
    if(pos == 0 || quantidadeElementos == 0){
        inserirInicio(elemento);
        return;
    }
    else {
        try {
            NO<T> *pAux = inicio;
            NO<T> *novo = new NO<T>(elemento);

            int cont = 0;

            while(cont < pos - 1){
                pAux = pAux->getProximo();
                cont ++;
            }

            pAux->getProximo()->setAnterior(novo);
            novo->setProximo(pAux->getProximo());
            pAux->setProximo(novo);
            novo->setAnterior(pAux);
            quantidadeElementos ++;

        }  catch (std::bad_alloc&) {
            throw QString("Memoria insuficiente");
        }
   }
}
template<typename T>
void LLDE<T>::inserirOrdenadoCrescente(T elemento){
    try {
        if (estaVazia()) { inserirInicio(elemento);
            return; }

        NO<T> *paux = inicio;

        if (quantidadeElementos == 1 && elemento <= paux->getDado()){
            inserirInicio(elemento);
            return;
        }
        else if (quantidadeElementos == 1 && elemento >= paux->getDado()){
            inserirFim(elemento);
            return;
        }

        while (elemento >= paux->getDado() && paux != fim){
            paux = paux->getProximo();

        }

        if (paux == fim){
            if (elemento >= fim->getDado()){
                inserirFim(elemento);
            }
            else if (elemento < fim->getDado()){
                inserirPos(quantidadeElementos-1, elemento);
            }
            return;
        }
        if (paux == inicio){
            inserirInicio(elemento);
            return;
        }

        NO<T> *novo = new NO(elemento);

        novo->setProximo(paux);
        novo->setAnterior(paux->getAnterior());
        paux->getAnterior()->setProximo(novo);
        paux->setAnterior(novo);

        quantidadeElementos++;
    }  catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }

}

template <typename T>
void LLDE<T>::inserirOrdenadoDecrescente(T elemento){
    try {
        if (estaVazia()) { inserirInicio(elemento);
            return; }

        NO<T> *paux = inicio;

        if (quantidadeElementos == 1 && elemento >= paux->getDado()){
            inserirInicio(elemento);
            return;
        }

        while (elemento <= paux->getDado() && paux != fim){
            paux = paux->getProximo();

        }

        if (paux == fim){
            if (elemento <= fim->getDado()){
                inserirFim(elemento);
            }
            else if (elemento > fim->getDado()){
                inserirPos(quantidadeElementos-1, elemento);
            }
            return;
        }
        else if (paux == inicio){
            inserirInicio(elemento);
            return;
        }

        NO<T> *novo = new NO(elemento);

        novo->setProximo(paux);
        novo->setAnterior(paux->getAnterior());
        paux->getAnterior()->setProximo(novo);
        paux->setAnterior(novo);


        quantidadeElementos++;
    }  catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}

template<typename T>
T LLDE<T>::operator[](int pos) const{
    if (estaVazia()) { throw QString (" o acesso Nao é possivel, lista vazia"); }
    if (pos < 0 || pos > quantidadeElementos){
        throw QString ("a posição não é válida.");
    }
    if (pos == 0){
        return inicio->getDado();
    }
    if (pos == quantidadeElementos-1){
        return fim->getDado();
    }

    int aux = 0;
    NO<T> *paux = inicio;

    while (aux < pos){
        paux = paux->getProximo();
        aux++;
    }

    return paux->getDado();
}


}
#endif // LLDE_H
