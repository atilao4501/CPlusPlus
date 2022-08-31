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

};

#endif // ORDENA_H
