#include <QCoreApplication>
#include <aluno.h>
#include <lldetemplate.h>
#include <hash.h>

int main()
{

    int opcao, retorno;
    std::string valor;
    afa::LLDE<aluno> L[31];
    aluno aluno("blau","bloa","2022","sampa");

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

        }

        else if(opcao == 2){
            std::cout << "Insira o valor a ser buscado: ";
            std::cin >> valor;

            if(tabela.busca(L,valor).getMatricula() != "-1"){
                std::cout << "\nIndice Gerado: " << std::stoi(valor)%100 << "\n";
                std::cout << "aqui está: " << tabela.busca(L,valor).getNome() << " " << tabela.busca(L,valor).getMae() << " " << tabela.busca(L,valor).getMatricula() << " " << tabela.busca(L,valor).getEndereco();
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
