#include "hash.h"
#include <iostream>

hash::hash():
    tam(0),
    tabela(0)

{   

}

hash::~hash(){
    if (tam != 0){
        for (int i = 0; i < tam; i++){
            delete[] tabela;

        }
    }
}

void hash::setTam(int newTam)
{
    while (newTam <= 20 || newTam >= 100){
        std::cout << "O tamanho deve ser > 20 e < 100: ";
        std::cin >> newTam;
    }
    tam = newTam;
    try {
        tabela = new hlb::LLSE[tam];

    }  catch (std::bad_alloc&) {
        throw std::string("Memoria insuficiente");
    }
}

int hash::funcaoHash(int chave){
    return chave % tam;
}

void hash::inserir(aluno aluno){
    int id = funcaoHash((aluno.getNome()+aluno.getMae()).size());
    tabela[id].inserirFim(&aluno);

}

aluno hash::busca(std::string nome,std::string mae,std::string mat){
    int id = funcaoHash((nome+mae).size());
    for(int i = 0; i < tabela[id].getQuantidadeElemento(); i++){
        if(nome == tabela[id].acessar(i).getNome() && mae == tabela[id].acessar(i).getMae() && mat == tabela[id].acessar(i).getMatricula()){
            return tabela[id].acessar(i);
        }

    }
    class aluno naodeu("","","naoexiste","");
    return naodeu;

}
aluno hash::remover(std::string nome, std::string mae, std::string mat){
    int id = funcaoHash((nome+mae).size());
    class aluno aux("","","naoexiste","");
    for(int i = 0; i < tabela[id].getQuantidadeElemento(); i++){
        if(nome == tabela[id].acessar(i).getNome() && mae == tabela[id].acessar(i).getMae() && mat == tabela[id].acessar(i).getMatricula()){
            aux = tabela[id].acessar(i);
            tabela[id].retirarQualquer(i);
            return aux;
        }

    }
    return aux;

}


void hash::imprimir(){
    for (int i = 0; i < tam; i++){
        std::cout << "Indice = " << i << " ";
        for(int j = 0; j < tabela[i].getQuantidadeElemento(); j++){
            std::cout << " " << tabela[i].acessar(j).getNome() << " : " << tabela[i].acessar(j).getMae() << " : " << tabela[i].acessar(j).getMatricula() << " : " << tabela[i].acessar(j).getEndereco() << " // ";
        }
        std::cout << "\n";
    }

}
