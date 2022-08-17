#include "fila.h"
#include <iostream>
#include <math.h>
#include <QString>

namespace afa {

Fila::Fila(int tamanho):
    tamanho(0),
    array(0),
    iniciofila(-1),
    fimfila(-1),
    quantidadeDeElementos(0)
{
    if(tamanho <= 0) throw QString("Tamanho nao pode ser <= 0");
        try {
            array = new int[tamanho];
            this->tamanho = tamanho;
    }   catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}
Fila::~Fila(){
    if(array) delete[] array;
}
bool Fila::estaVazia() const{
    if (quantidadeDeElementos == 0){
        return true;
    }
        else return false;
}
bool Fila::estaCheia() const{
    if (quantidadeDeElementos == tamanho){
        return true;
    }
    else return false;
}
void Fila::inserir(int elemento){
    if(estaCheia()) throw QString("A Fila está cheia");
    if (estaVazia()){
        iniciofila = 0;
        fimfila = 0;
        array[fimfila] = elemento;
        quantidadeDeElementos++;
    }
    else {
            quantidadeDeElementos++;
            fimfila++;

            if (fimfila == tamanho){
                fimfila = 0;
            }

            array[fimfila] = elemento;

    }
}
void Fila::retirar(){
    if(estaVazia()){ throw QString("A Fila está vazia");}

        if(iniciofila == fimfila){
            iniciofila = -1;
            fimfila = -1;
            quantidadeDeElementos = 0;
            return;
        }

        iniciofila++;

        if (iniciofila == tamanho){
            iniciofila = 0;
        }

        quantidadeDeElementos--;


}
int Fila::acessar () const{
    if(estaVazia()) throw QString("A Fila está vazia");
    else {
        return array[iniciofila];
    }
}
int Fila::getQuantidadeDeElementos() const{
    return quantidadeDeElementos;
}


}
