#include <QCoreApplication>
#include <aluno.h>
#include <lldetemplate.h>
#include <hash.h>

int main()
{

    int opcao;
    std::string valor, nomeaux, maeaux, mataux;
    afa::LLDE<aluno> L[31];
    aluno aluno1("blau","bloa","2022","sampa");
    class aluno aluno2("blau","bloa","2025","sampa");

    afa::LLDE<aluno> lista;

   lista.inserirFim(aluno1);
   lista.inserirFim(aluno2);

   std::cout << lista[0].getMatricula();
   std::cout << lista[1].getMatricula();


    hash tabela;

        std::cout << "\n 0 - Sair\n 1 - Inserir\n 2 - buscar\n 3 - Imprimir\n\n";
        std::cin >> opcao;




    while (opcao != 0){

        if(opcao == 1){
            std::cout << "Insira os dados do aluno a ser inserido(Nome, Mae, Matricula, Endereco) ";\
            std::string nome, mae, matricula, endereco;

            std::cin >> nome >> mae >> matricula >> endereco;

            class aluno estudante(nome,mae,matricula,endereco);

            tabela.inserir(L, estudante);
            nome = mae = matricula = endereco = "";

        }

        else if(opcao == 2){
            std::cout << "Insira o nome a ser buscado: ";
            std::cin >> nomeaux;
            std::cout << "Insira o nome da mae a ser buscado: ";
            std::cin >> maeaux;
            std::cout << "Insira a matricula a ser buscada: ";
            std::cin >> mataux;

            if(tabela.busca(L,nomeaux,maeaux,mataux).getMatricula() != "-1"){
                std::cout << "\nIndice Gerado: " << (maeaux+nomeaux).size()%100 << "\n";
                std::cout << "aqui está: " << tabela.busca(L,nomeaux,maeaux,mataux).getNome() << " " << tabela.busca(L,nomeaux,maeaux,mataux).getMae() << " " << tabela.busca(L,nomeaux,maeaux,mataux).getMatricula() << " " << tabela.busca(L,nomeaux,maeaux,mataux).getEndereco();
            }
            else {
                std::cout << "O elemento não está presente.";
            }
        }

        else if(opcao == 3){
            tabela.imprimir(L);

        }
        std::cout << "\n\n 0 - Sair\n 1 - Inserir\n 2 - buscar\n 3 - Imprimir\n\n";
        std::cin >> opcao;
    }


}
