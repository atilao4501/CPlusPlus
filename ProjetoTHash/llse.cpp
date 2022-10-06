#include "llse.h"
#include <iostream>

namespace hlb{
LLSE::LLSE():
    inicio(0),
    quantidadeElemento (0)

{
}

LLSE::~LLSE()
{
    if(quantidadeElemento != 0){
        while(quantidadeElemento > 0){
            retirarInicio();
        }
        if(inicio) delete inicio;
    }
}
bool LLSE::estaVazia() const{
    return quantidadeElemento == 0;
}

void LLSE::inserirInicio(aluno elemento){
    try {
        NO *pAux = new NO(elemento);
        pAux->setProximo(inicio);
        inicio = pAux;
        quantidadeElemento++;
    }  catch (std::bad_alloc&) {
        throw std::string("Memoria insuficiente");
    }
}

void LLSE::inserirFim(aluno elemento)
{
    try {
        NO *novo = new NO(elemento);
        if(estaVazia()){
            inicio = novo;
            quantidadeElemento++;
            return;
        }
        else {
            NO *pAux = inicio;
            while(pAux->getProximo() != 0){
                pAux = pAux->getProximo();
            }
            pAux->setProximo(novo);
            quantidadeElemento++;
        }
    }  catch (std::bad_alloc&) {
        throw std::string("Memoria insuficiente");
    }
}



aluno LLSE::retirarInicio(){
    if(estaVazia()) throw std::string("Não ha elementos para serem retirados");
    NO *pAux = inicio;
    inicio = inicio->getProximo();
    aluno valor = pAux->getDado();
    delete pAux;
    quantidadeElemento--;
    return valor;
}

aluno LLSE::retirarFim()
{
    if(estaVazia()) throw std::string("Não ha elementos para serem retirados");
    if(inicio->getProximo() == 0){
        aluno dado = inicio->getDado();
        delete inicio;
        quantidadeElemento --;
        inicio = 0;
        return dado;
    }
    else{
        NO *pAux = inicio;
        while(pAux->getProximo()->getProximo() != 0){
            pAux = pAux->getProximo();
        }
        aluno dado = pAux->getProximo()->getDado();
        delete pAux->getProximo();
        pAux->setProximo(0);
        quantidadeElemento --;
        return dado;
    }
}

aluno LLSE::acessar(int pos)
{
    if(estaVazia()){
        aluno aux("","","0","");
        return aux;
    }
    else{
        NO *pAux = inicio;
        int cont = 0;
        while(cont < pos){
            pAux = pAux->getProximo();
            cont++;
    }
    return pAux->getDado();
    }

}

aluno LLSE::retirarQualquer(int pos)
{
    if(estaVazia()) throw std::string("Nao ha elementos para serem retirados");
    if(pos < 0 || pos >= quantidadeElemento) throw QString("Posicao fora do parametro");
    if(pos == 0) return retirarInicio();
    NO *pAux = inicio;
    int cont = 0;
    while(cont < pos - 1){
        pAux = pAux->getProximo();
        cont ++;
    }
    NO *pAux2 = pAux->getProximo();
    pAux->setProximo(pAux2->getProximo());
    aluno dado = pAux2->getDado();
    delete pAux2;
    quantidadeElemento--;
    return dado;
}

int LLSE::getQuantidadeElemento() const{
    return quantidadeElemento;
}
}
