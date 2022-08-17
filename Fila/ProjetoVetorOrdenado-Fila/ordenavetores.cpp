#include "ordenavetores.h"
#include <cstdlib>
#include <iostream>


namespace afa {

ordenavetores::ordenavetores(int tamanhoVetor):

    tamanhoVetor(0),
    vetor(0),
    vetorOrdenado(0)

{
    if(tamanhoVetor <= 0) throw QString("Tamanho nao pode ser <= 0");
        try {
        vetor = new int[tamanhoVetor];
        vetorOrdenado = new int[tamanhoVetor];
        this->tamanhoVetor = tamanhoVetor;

        }
    catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}
ordenavetores::~ordenavetores(){
    if(vetor) delete[] vetor;
    if(vetorOrdenado) delete[] vetorOrdenado;
}

void ordenavetores::criarVetor(){

    for (int pos = 0; pos < tamanhoVetor; pos++){

       vetor[pos] = rand()%tamanhoVetor;

    }


}

void ordenavetores::ordenarVetor(){

    afa::Fila filaUm(tamanhoVetor);
    afa::Fila filaDois(tamanhoVetor);

    int contador = 0;

    for (int pos = 0; pos < tamanhoVetor; pos++){

       filaUm.inserir(vetor[pos]);
    }

    for (int pos = 0; pos < tamanhoVetor; pos++){

        if (filaUm.getQuantidadeDeElementos() > 1){
              filaDois.inserir(filaUm.acessar());
                filaUm.retirar();

                while (contador != filaUm.getQuantidadeDeElementos()+1){

                    if(filaDois.acessar() <= filaUm.acessar()){
                        filaUm.inserir(filaUm.acessar());
                        filaUm.retirar();
                        contador++;

                    }
                    else {
                        filaUm.inserir(filaDois.acessar());
                        filaDois.retirar();
                        filaDois.inserir(filaUm.acessar());
                        filaUm.retirar();

                        contador = 0;
                    }

                }
        }
        else if (filaUm.getQuantidadeDeElementos() == 1){
                    filaDois.inserir(filaUm.acessar());

        }


        contador = 0;
                vetorOrdenado[pos] = filaDois.acessar();
                filaDois.retirar();

    }

}

QString ordenavetores::getVetor() const{

    QString saida = "";
    for (int pos = 0; pos < tamanhoVetor; pos++){
        saida += QString::number(vetor[pos]) + " ";
    }
    return saida;
}

QString ordenavetores::getVetorOrdenado() const{

    QString saida = "";
    for (int pos = 0; pos < tamanhoVetor; pos++){
        saida += QString::number(vetorOrdenado[pos]) + " ";
    }
    return saida;
}

}
