#include "testaordena.h"
#include <cstdlib>
#include <random>

int gen_number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 500000);

    return dis(gen);
}

testaordena::testaordena()
{

}
testaordena::~testaordena(){

        for (int pos=0; pos < tamanho; pos++){
            delete VET[pos];
        }

}
int testaordena::getTamanho(){
    return tamanho;
}
void testaordena::preencherVetor(Itens **vetor, int tam){

    tamanho = tam;

    for(int pos = 0; pos < tam; pos++){
        vetor[pos] = new Itens(gen_number());
    }

    VET = vetor;
}
Itens **testaordena::getVET() const
{
    return VET;
}
Itens **testaordena::ordenarVetor(Itens **vetor, int tam, int modo)
{
    tamanho = tam;

    if(modo == 1){

        Ordena::selectionSort(vetor, tam);

    }
    else if (modo == 2){

        Ordena::insertionSort(vetor,tam);

    }
    else if (modo == 3){

        Ordena::bubbleSort(vetor,tam);

    }
    else if (modo == 4){

        Ordena::shellSort(vetor,tam);
    }
    else if (modo == 5){
        Ordena::mergeSort(vetor,tam);
    }
    else throw std::string("Modo nao identificado\n");


    return vetor;

}


