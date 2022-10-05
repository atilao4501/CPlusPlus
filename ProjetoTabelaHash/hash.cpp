#include "hash.h"

hash::hash()
{

}

void hash::setTam(int newTam)
{
    tam = newTam;
}

int hash::funcaoHash(int chave){
    return chave % 31;
}

void hash::inserir(afa::LLDE<aluno> L[],aluno aluno){
    std::string valor;
    valor = aluno.getNome()+aluno.getMae();
    int id = funcaoHash(valor.size());
    L[id].inserirFim(aluno);
}
void hash::remover(afa::LLDE<aluno> L[], aluno aluno){
    int id = funcaoHash(std::stoi(aluno.getMatricula()));
    std::cout << "\nIndice Gerado: " << id << "\n";
    L[id].buscarRemoverAluno(aluno);
}

aluno hash::busca(afa::LLDE<aluno> L[], std::string nome, std::string mae, std::string mat){
    std::string valor;
    valor = nome+mae;
    int id = funcaoHash(valor.size());
    return L[id].buscarAluno(nome, mae,mat);

}

void hash::imprimir(afa::LLDE<aluno> L[]){
    for (int i = 0; i < 31; i++){
        std::cout << "Indice = " << i << " ";
        L[i].imprimirListaAlunos();
        std::cout << "\n";
    }

}
