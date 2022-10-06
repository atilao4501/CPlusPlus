#include "testahash.h"
#include <iostream>


testaHash::testaHash(int tamanho)
{
    objeto.setTam(tamanho);
}
void testaHash::consulta(){
    std::string nome,mae,mat;

    std::cout << "Insira os dados do aluno a ser buscado(Nome, Mae, Matricula) ";
    std::cin >> nome >> mae >> mat;

    if(objeto.busca(nome,mae,mat).getMatricula() != "naoexiste"){
        aluno alunoaux = objeto.busca(nome,mae,mat);
        std::cout << "\nIndice Gerado: " << (nome+mae).size()%31 << "\n";
        std::cout << alunoaux.getNome() << " " << alunoaux.getMae() << " " << alunoaux.getMatricula() << " " << alunoaux.getEndereco();

    }
    else {
        std::cout << "O elemento não está presente.";
    }
}

void testaHash::insere(){
    std::string nome,mae,mat,ende;

    std::cout << "Insira os dados do aluno a ser inserido(Nome, Mae, Matricula, Endereco) ";
    std::cin >> nome >> mae >> mat >> ende;
    aluno alunoaux(nome,mae,mat,ende);
    objeto.inserir(alunoaux);
}

void testaHash::remove(){
    std::string nome,mae,mat;

    std::cout << "Insira os dados do aluno a ser Removido(Nome, Mae, Matricula) ";
    std::cin >> nome >> mae >> mat;

    if(objeto.remover(nome,mae,mat)){
        std::cout << "\nIndice Gerado: " << (nome+mae).size()%31 << "\n";
        std::cout << "O elemento foi removido";

    }
    else {
        std::cout << "O elemento não está presente.";
    }
}
void testaHash::imprimeHash(){
    objeto.imprimir();
}

void testaHash::principal(){
    try {
        int opcao;
                    std::cout << "\n 0 - Sair\n 1 - Inserir\n 2 - Remover\n 3 - buscar\n 4 - Imprimir\n\n";
                    std::cin >> opcao;

                while (opcao != 0){
                    if(opcao == 1){
                        testaHash::insere();
                    }
                    else if(opcao == 2){
                        testaHash::remove();
                    }
                    else if(opcao == 3){
                        testaHash::consulta();
                    }
                    else if(opcao == 4){
                        testaHash::imprimeHash();
                    }
                    std::cout << "\n 0 - Sair\n 1 - Inserir\n 2 - Remover\n 3 - buscar\n 4 - Imprimir\n\n";
                    std::cin >> opcao;
                }

    }  catch (std::string erro) {
        std::cout<<"\nERRO NO PROGRAMA: "<<erro<<"\n";

    }
}
