#include <QCoreApplication>
#include <aluno.h>
#include <hash.h>
#include <iostream>

int main()
{
    try {
        int opcao;


                    std::cout << "\n 0 - Sair\n 1 - Inserir\n 2 - Remover\n 3 - buscar\n 4 - Imprimir\n\n";
                    std::cin >> opcao;

                    hash tabela(31);

                while (opcao != 0){

                    if(opcao == 1){
                        std::string nome,mae,mat,ende;

                        std::cout << "Insira os dados do aluno a ser inserido(Nome, Mae, Matricula, Endereco) ";
                        std::cin >> nome >> mae >> mat >> ende;
                        aluno alunoaux(nome,mae,mat,ende);
                        tabela.inserir(alunoaux);

                    }

                    else if(opcao == 3){
                        std::string nome,mae,mat;

                        std::cout << "Insira os dados do aluno a ser buscado(Nome, Mae, Matricula) ";
                        std::cin >> nome >> mae >> mat;

                        if(tabela.busca(nome,mae,mat).getMatricula() != "naoexiste"){
                            aluno alunoaux = tabela.busca(nome,mae,mat);
                            std::cout << "\nIndice Gerado: " << (nome+mae).size()%31 << "\n";
                            std::cout << alunoaux.getNome() << " " << alunoaux.getMae() << " " << alunoaux.getMatricula() << " " << alunoaux.getEndereco();

                        }
                        else {
                            std::cout << "O elemento não está presente.";
                        }
                    }
                    else if(opcao == 2){
                        std::string nome,mae,mat;

                        std::cout << "Insira os dados do aluno a ser Removido(Nome, Mae, Matricula) ";
                        std::cin >> nome >> mae >> mat;

                        if(tabela.remover(nome,mae,mat)){
                            std::cout << "\nIndice Gerado: " << (nome+mae).size()%31 << "\n";
                            std::cout << "O elemento foi removido";

                        }
                        else {
                            std::cout << "O elemento não está presente.";
                        }

                    }
                    else if (opcao == 4){
                        tabela.imprimir();
                    }
                    std::cout << "\n 0 - Sair\n 1 - Inserir\n 2 - Remover\n 3 - buscar\n 4 - Imprimir\n\n";
                    std::cin >> opcao;
                }

    }  catch (std::string erro) {
        std::cout<<"\nERRO NO PROGRAMA: "<<erro<<"\n";

    }




}
