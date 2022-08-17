#include "LLSE.h"

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

void LLSE::inserirInicio(int elemento){
    try {
        NO *pAux = new NO(elemento);
        pAux->setProximo(inicio);
        inicio = pAux;
        quantidadeElemento++;
    }  catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}

void LLSE::inserirFim(int elemento)
{
    try {
        NO *novo = new NO(elemento);
        if(estaVazia()){
            inicio = novo;;
            quantidadeElemento ++;
            return;
        }
        else {
            NO *pAux = inicio;
            while(pAux->getProximo() != 0){
                pAux = pAux->getProximo();
            }
            pAux->setProximo(novo);
            quantidadeElemento ++;
        }
    }  catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}

void LLSE::inserirQualquer(int pos, int elemento)
{  
    if(pos < 0 || pos > quantidadeElemento) throw QString("Posicao fora do parametro - IQ");
    if(pos == quantidadeElemento){
        inserirFim(elemento);
        return;
    }
    if(pos == 0 || quantidadeElemento == 0){
        inserirInicio(elemento);
        return;
    }
    else {
        try {
            NO *pAux = inicio;
            NO *novo = new NO();
            novo->setDado(elemento);
            int cont = 0;
            while(cont < pos - 1){
                pAux = pAux->getProximo();
                cont ++;
            }
            novo->setProximo(pAux->getProximo());
            pAux->setProximo(novo);
            quantidadeElemento ++;
        }  catch (std::bad_alloc&) {
            throw QString("Memoria insuficiente");
        }
   }
}

int LLSE::retirarInicio(){
    if(estaVazia()) throw QString("Não ha elementos para serem retirados");
    NO *pAux = inicio;
    inicio = inicio->getProximo();
    int valor = pAux->getDado();
    delete pAux;
    quantidadeElemento--;
    return valor;
}

int LLSE::retirarFim()
{
    if(estaVazia()) throw QString("Não ha elementos para serem retirados");
    if(inicio->getProximo() == 0){
        int dado = inicio->getDado();
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
        int dado = pAux->getProximo()->getDado();
        delete pAux->getProximo();
        pAux->setProximo(0);
        quantidadeElemento --;
        return dado;
    }
}

int LLSE::acessar(int pos)
{
    if(estaVazia()) throw QString("Não ha elementos para serem acessados");
    if(pos < 0 || pos >= quantidadeElemento) throw QString("Posicao fora do parametro");
    NO *pAux = inicio;
    int cont = 0;
    while(cont < pos){
        pAux = pAux->getProximo();
        cont ++;
    }
    return pAux->getDado();
}

int LLSE::retirarQualquer(int pos)
{
    if(estaVazia()) throw QString("Nao ha elementos para serem retirados");
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
    int dado = pAux2->getDado();
    delete pAux2;
    quantidadeElemento --;
    return dado;
}

int LLSE::getQuantidadeElemento() const{
    return quantidadeElemento;
}
}
