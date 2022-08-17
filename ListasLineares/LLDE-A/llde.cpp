#include "llde.h"
namespace afa{
LLDE::LLDE():
    quantidadeElementos(0),
    inicio(0),
    fim(0)
{
}

LLDE::~LLDE(){
    if (quantidadeElementos != 0){
        while (quantidadeElementos != 0){
            retirarInicio();
        }
    }
    if (inicio) delete inicio;
    if (fim) delete fim;
}

bool LLDE::estaVazia() const{

    return (quantidadeElementos==0);
}

void LLDE::inserirInicio(int elemento){

    try {
        NO *novo = new NO(elemento);

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
int LLDE::retirarInicio(){
    if (estaVazia()) throw QString("\nA lista esta vazia");
    if (quantidadeElementos == 1){
        int x = inicio->getDado();

        delete inicio;

        quantidadeElementos--;

        inicio = fim = 0;

        return x;
    }
        NO *aux = inicio;

        inicio = aux->getProximo();
        inicio->setAnterior(0);

        quantidadeElementos--;

        int x = aux->getDado();

        delete aux;
        return x;

}
int LLDE::getQuantidadeElementos(){
    return quantidadeElementos;
}

void LLDE::inserirFim(int elemento){
    NO *novo = new NO(elemento);

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

int LLDE::retirarFim(){
    if (estaVazia()) throw QString("Não é possivel retirar, a lista está vazia");

    int x = fim->getDado();

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
int LLDE::retirarPos(int pos){
    if (estaVazia()) { throw  QString ("a operação não é possível");
}
    if (pos >= quantidadeElementos || pos < 0){
        throw  QString ("a operação não é possível");
    }
    int x;

    if (pos == 0){
        x = retirarInicio();

        return x;
    }
    else if (pos == quantidadeElementos-1){
        x = retirarFim();

        return x;
    }
    else {
        NO *paux = inicio;

        for (int aux = 0; aux < pos; aux++){
            paux = paux->getProximo();

        }

        x = paux->getDado();

        quantidadeElementos--;

        delete paux;

        return x;
    }

}
void LLDE::inserirPos(int pos, int elemento){
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
            NO *pAux = inicio;
            NO *novo = new NO(elemento);

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

void LLDE::inserirOrdenadoCrescente(int elemento){
    try {
        if (estaVazia()) { inserirInicio(elemento);
            return; }

        NO *paux = inicio;

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

        NO *novo = new NO(elemento);

        novo->setProximo(paux);
        novo->setAnterior(paux->getAnterior());
        paux->getAnterior()->setProximo(novo);
        paux->setAnterior(novo);

        quantidadeElementos++;
    }  catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }

}

void LLDE::inserirOrdenadoDecrescente(int elemento){
    try {
        if (estaVazia()) { inserirInicio(elemento);
            return; }

        NO *paux = inicio;

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

        NO *novo = new NO(elemento);

        novo->setProximo(paux);
        novo->setAnterior(paux->getAnterior());
        paux->getAnterior()->setProximo(novo);
        paux->setAnterior(novo);


        quantidadeElementos++;
    }  catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}
int LLDE::operator[](int pos) const{
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
    NO *paux = inicio;

    while (aux < pos){
        paux = paux->getProximo();
        aux++;
    }

    return paux->getDado();
}
}
