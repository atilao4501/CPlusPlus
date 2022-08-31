#include "ordena.h"
#include <bits/stdc++.h>
#include <iostream>


Ordena::Ordena()
{

}

void Ordena::selectionSort(Itens **V, int n){

    if (V == nullptr) return;

    int i , j, imin;
    Itens * T = nullptr;

    for (i=0; i<n-1; i++){
        imin = i;
        for (j=i+1; j<n; j++){
            if(V[imin]->getChave() > V[j]->getChave()){
                imin = j;
            }
        }
        if(i != imin){
            T = V[i];
            V[i] = V[imin];
            V[imin] = T;
        }
    }
}
void Ordena::insertionSort(Itens **V, int n){
    long int i,j;
    Itens *T = nullptr;
    if(V != nullptr){
        for(j = 1; j < n; j++){
            T = V[j];
            i = j-1;
            while(i>=0 && V[i]->getChave() > T->getChave()){
                V[i+1] = V[i];
                i--;
            }
            V[i+1] = T;
        }
    }
}
void Ordena::bubbleSort(Itens **V, int n){
    int i, j;
        for (i = 0; i < n - 1; i++)

            for (j = 0; j < n - i - 1; j++){
                if (V[j]->getChave()  > V[j+1]->getChave()){

                    std::swap(V[j],V[j+1]);
                }
            }
}
void Ordena::shellSort(Itens **V, int n){

    int h = 1;

    while (h < n){
        h = 3 * h + 1;
    }

    while(h >= 1){

            for(int j = h; j<n ; j+=1){
                Itens *aux = V[j];
                int i=0;

                for(i=j; (i>=h) && (V[i-h]->getChave()>aux->getChave()); i-=h){
                    V[i] = V[i-h];
                }
                V[i] = aux;
            }

        h /= 3;
    }

}
