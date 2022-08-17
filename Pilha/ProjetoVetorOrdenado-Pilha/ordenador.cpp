#include "ordenador.h"
#include <cstdlib>
#include <iostream>


namespace afa {


ordenador::ordenador(int tamanhoVetor):
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
ordenador::~ordenador(){
    if (vetor) delete[] vetor;
    if(vetorOrdenado) delete[] vetorOrdenado;
}

void ordenador::criarVetor(){

    for (int pos = 0; pos < tamanhoVetor; pos++){

       vetor[pos] = rand()%tamanhoVetor;

    }
}

void ordenador::ordenarVetor(){

    criarVetor();

    afa::Pilha pilhaUm(tamanhoVetor);
    afa::Pilha pilhaDois(tamanhoVetor);
    afa::Pilha pilhaTres(tamanhoVetor);

    for (int pos = 0; pos < tamanhoVetor; pos++){

       pilhaUm.inserir(vetor[pos]);
    }

    for (int pos = 0; pos < tamanhoVetor; pos++){

        if (pilhaUm.quantidadeDeElementos() > 1){
            pilhaDois.inserir(pilhaUm.acessar());
            pilhaUm.retirar();


            while (pilhaUm.quantidadeDeElementos() != 0) {

                if (pilhaDois.acessar() <= pilhaUm.acessar()){
                    pilhaTres.inserir(pilhaUm.acessar());
                    pilhaUm.retirar();

                }
                else {
                    pilhaTres.inserir(pilhaDois.acessar());
                    pilhaDois.retirar();
                    pilhaDois.inserir(pilhaUm.acessar());
                    pilhaUm.retirar();

                    while (pilhaTres.quantidadeDeElementos() != 0){
                        pilhaUm.inserir(pilhaTres.acessar());
                        pilhaTres.retirar();
                    }

                }
            }

            while (pilhaTres.quantidadeDeElementos() != 0){
                pilhaUm.inserir(pilhaTres.acessar());
                pilhaTres.retirar();
            }

        }

        else if (pilhaUm.quantidadeDeElementos() == 1){
            pilhaDois.inserir(pilhaUm.acessar());
            pilhaUm.retirar();
        }

                vetorOrdenado[pos] = pilhaDois.acessar();
                pilhaDois.retirar();

    }
    /*if (filaUm.quantidadeDeElementos() > 1){
          filaDois.inserir(filaUm.acessar());
            filaUm.retirar();

            while (contador != filaUm.quantidadeDeElementos()+1){

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
    }*/

}

QString ordenador::getVetor() const{

    QString saida = "";
    for (int pos = 0; pos < tamanhoVetor; pos++){
        saida += QString::number(vetor[pos]) + " ";
    }
    return saida;
}

QString ordenador::getVetorOrdenado() const{

    QString saida = "";
    for (int pos = 0; pos < tamanhoVetor; pos++){
        saida += QString::number(vetorOrdenado[pos]) + " ";
    }
    return saida;
}

}
