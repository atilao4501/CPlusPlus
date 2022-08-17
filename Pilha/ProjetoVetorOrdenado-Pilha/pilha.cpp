#include <Pilha.h>

namespace afa{
Pilha::Pilha(int tamanho):
    tamanho(0),
    topo(-1),
    array(0)
{
    if(tamanho <= 0) throw QString("Tamanho nao pode ser <= 0");
    try {
        array = new int[tamanho];
        this->tamanho = tamanho;
    } catch (std::bad_alloc&) {
        throw QString("Memoria insuficiente");
    }
}
    Pilha::~Pilha(){
    if(array) delete[] array;
}

    bool Pilha::estaCheia() const{
        //return (topo == (tamanho-1));
        if(topo == tamanho-1) return true;
        else return false;
    }

    bool Pilha::estaVazia() const{
        return (topo == -1);
    }

    void Pilha::inserir(int elemento){
        //1 - verificar se está cheia - LE
        if(estaCheia()) throw QString("Está cheia");
        //2 - topo ++
        else topo++;
        //3 - colocar elemento no vetor na posição topo
        array[topo] = elemento;

    }

    void Pilha::retirar(){
        //1 - verificar se estiver vazia - LE
        if(estaVazia()) throw QString("Está vazia");
        //2 - topo --
        else topo--;
    }

    int Pilha::acessar() const{
        //1 - verificar se ela está vazia
        if(estaVazia()) throw QString("Está vazia");
        //2 - return o eletento do topo
        return array[topo];
    }

    int Pilha::quantidadeDeElementos() const{
        //1 - return topo + 1
        return (topo + 1);
    }

    QString Pilha::getPilha() const{
        QString saida = "";
        if(estaVazia()) return saida;
        for(int pos = topo; pos >=0; pos--){
            saida += QString::number(array[pos]) + "\n";
        }
        return saida;
    }

}
