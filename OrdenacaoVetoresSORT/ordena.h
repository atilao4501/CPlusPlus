#ifndef ORDENA_H
#define ORDENA_H
#include <iostream>
#include <itens.h>
#include <ctime>
#include <unistd.h>

class Ordena
{
public:
    Ordena();
    void static selectionSort(Itens **V, int n);
    void static insertionSort(Itens **V, int n);
    void static bubbleSort(Itens **V, int n);
    void static shellSort(Itens **V, int n);
    void static mergeSort(Itens **A, int tam);
    void static mergeSortR(Itens **A, Itens **B, int ini, int fim);
    void static intercala(Itens **A, Itens **B, int ini, int meio, int fim);
    void static quickSort(Itens **V, int tam);
    void static quickSortR(Itens **vetor, int esq, int dir);

};

#endif // ORDENA_H
